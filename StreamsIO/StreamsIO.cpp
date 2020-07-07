#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream file;
	file.open("numbers.txt");
	file << "1 2 3 4 5 6 7 8 9 10\n";
	file.close();
}
