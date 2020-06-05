#include <iostream>
#include<vector>
using namespace std;

template<typename T>
void Print(T value)
{
	cout << value << endl;
}

void PrintFunction()
{
	cout << "This exist without call\n";
}

template<typename T, int N>
class Array
{
private:
	// Stack array
	T _array[N];
public:
	int GetSize() const { return N; }
};


int main()
{
	// Implicitly defining type
	Print(5);
	Print("Test");
	Print(5.5);

	// Explicitly defining type
	Print<int>(4);

	vector<int> aa;
	// Class template wth n;
	Array<float, 5> array;

	system("Pause>0");
}
