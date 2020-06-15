#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void PrintValue(int value)
{
	cout << "Value: " << value << "\n";
}
void Foreach(vector<int>& vector, void(*func)(int))
{
	for (int i = 0; i < vector.size(); ++i)
		func(vector[i]);
	cout << "\n";
}

void Foreach2(vector<int>& vector, const std::function<void(int)>& func)
{
	for (int i = 0; i < vector.size(); ++i)
		func(vector[i]);
	cout << "\n";
}

int main()
{
	vector<int> numbers = { 1,3,7,2,1,9 };

#pragma region Pointer to function
#if 0
	typedef void(*PrintValueFunc) (int);

	void(*myFunc) (int) = PrintValue;
	PrintValueFunc func = PrintValue;

	myFunc(5);
	func(8);

	Foreach(numbers, PrintValue);
#endif
#pragma endregion

#pragma region Lambda
#if 1

	Foreach(numbers, [](int value) { cout << "Value: " << value << endl; });

	auto lambda = [](int value) { cout << "Value: " << value << endl; };
	Foreach(numbers, lambda);

	int a = 5;
	auto lambda1 = [&a](int value) { cout << "Value: " << value << " - " << a << endl; };
	auto lambda2 = [=](int value) { cout << "Value: " << value << " - " << a << endl; };

	Foreach2(numbers, lambda1);
	Foreach2(numbers, lambda2);
#endif
#pragma endregion

	auto it = std::find_if(numbers.begin(), numbers.end(), [](int value)
		{
			return value > 5;
		});

	cout << *it << endl;

	
	system("Pause>0");
}
