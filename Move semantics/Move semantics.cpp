#include <iostream>
using namespace std;

char* allocateChar(const char* string)
{
	int size = strlen(string) + 1;
	char* newChar = new char[size];
	strcpy_s(newChar, size, string);
	return newChar;
}

class String
{
private:
	char* _data;
	int _size;
public:
	String() = default;
	String(const char* string)
	{
		_data = allocateChar(string);
		_size = strlen(_data);
		cout << "String created!\n";
	}
	String(const String& org)
	{
		_data = allocateChar(org._data);
		cout << "String copied!\n";
	}

	// Move constructor, doesn't copy string, takes rvalue reference - temporary value
	String(String&& org) noexcept
	{
		// Only assigning the pointer to original object (org)
		_data = org._data;
		_size = org._size;

		// Taking care of the org string instance, we are stealing data from instance, and after we stole it, we need to clean up the mess, meaning set those attributes to default values
		org._size = 0;
		org._data = nullptr;

		cout << "String moved!\n";
	}

	~String()
	{
		delete[] _data;
		_data = nullptr;
		cout << "String deleted!\n";
	}
	void GetData() { cout << _data << endl; }
};

class Entity
{
private:
	String _string;
public:
	Entity(const String& string) : _string(string)
	{
	}
	Entity(String&& string) : _string(move(string))
	{
	}
	void Print()
	{
		_string.GetData();
	}
};

int main()
{
	// Moving object instead of copying it -> better performance

	//Entity entity(String("Adnan"));

	//entity.Print();


	String ado("Adnan");
	String niko = move(ado);

	system("Pause>0");
}
