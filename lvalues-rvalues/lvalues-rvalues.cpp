#include <iostream>
using namespace std;

int& GetValueRef()
{
	static int value = 10;
	return value;
}

int GetValue()
{
	int value = 5;
	return value;
}

void PrintName(const std::string& name)
{
	std::cout << "[lvalue and rvalue]" << name << std::endl;
}

void PrintName(std::string& name)
{
	std::cout << "[lvalue] " << name << std::endl;
}

void PrintName(std::string&& name)
{
	std::cout << "[rvalue] " << name << std::endl;
}

int main()
{
	int i = 10; // i is lvalue, 10 is rvalue
	int a = i; // assigning to lvalue, another lvalue

	int b = GetValue(); // rvalue is a function
	GetValueRef() = 5; //lvalue reference, rvalue 5

	string firstName = "Adnan";
	string lastname = "Cutura";
	string username = firstName + lastname;

	PrintName(username);
	PrintName(firstName + lastname);
}
