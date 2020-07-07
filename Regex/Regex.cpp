#include <iostream>
#include <iostream>
#include <regex>
using namespace std;

int main()
{

	string pravilo = "[a-z]+[.][a-z]+[@](hotmail.com|fit.ba|outlook.com)";
	string rijec;

	do
	{
		getline(cin, rijec);
	} while (!regex_match(rijec, regex(pravilo)));
}
