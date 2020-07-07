#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 * string - array of characters
// const char*  -> c way of writing strings
 * string stream
 */

int main()
{
#if 0
	string name = "Adnan";
	name.append("x(Ado)x");
	name += "Cutura";


	cout << name << endl;
	cout << "Capacity: " << name.capacity() << endl;
	cout << "Max size: " << name.max_size() << endl;
	cout << "Size: " << name.size() << endl;

	name.reserve(50); //Increasing capacity
	cout << "Capacity: " << name.capacity() << endl;

	// Find replace
	name.replace(name.find('x'), 1, " ");
	name.replace(name.find('x'), 1, " ");
	cout << name << endl;
#endif


	stringstream stream;
	stream << "Adnan" << " " << "Cutura\n";
	cout << stream.str();

	string streamToString = stream.str();
	const char* stringToChar = streamToString.c_str();
	
	cout << stringToChar;
	
}