#include <iostream>
using namespace std;

class Error :exception
{
	int _line;
	string _time;
	string _function;
public:
	Error(int line, string function, string time, const char* message) :exception(message)
	{
		_line = line;
		_function = function;
		_time = time;
	}
	void Info()
	{
		cout << "Error message: " << what();
		cout << "\nLine: " << _line;
		cout << "\nFunction: " << _function;
		cout << "\nTiime: " << _time;
	}
};

float Division(float a, float b)
{
	if (b == 0)
		throw Error(__LINE__, __FUNCTION__, __TIME__, "Dividing with 0 is forbidden");
	return a / b;
}

int main()
{
	float result = 0;
	try
	{
		cout << Division(2, 3) << "\n";
		cout << Division(2, 0) << "\n";
	}
	catch (Error& err)
	{
		err.Info();
	}
	catch(exception& err)
	{
		cout << err.what() <<"\n";
	}
	catch(...)
	{
		cout << "Error!\n";
	}

	system("Pause>0");
}
