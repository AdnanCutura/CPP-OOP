#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// STL - Standard template library
/* Library filled with containers types
 * Vector - Dynamic array, but not vector
 * created without size
 *
 * studios end up creating own STL Libraries - https://github.com/electronicarts/EASTL - in most cases faster than in normal STL
 *
 * works like dynamic array (copy in temp ...)
 */

struct Coordinate
{
	int X, Y;
	Coordinate(int x, int y) :X(x), Y(y) {};

	Coordinate(const Coordinate& coordinate)
	{
		X = coordinate.X;
		Y = coordinate.Y;
		cout << "Copied!" << endl;
	}
};

ostream& operator<<(ostream& stream, const Coordinate& coordinate)
{
	stream << "X: " << coordinate.X << " - Y: " << coordinate.Y << endl;
	return stream;
}

int main()
{
	vector<Coordinate> coordinates;

	// optimization #1
	coordinates.reserve(3); // reserving 3 spaces

	// optimization #2
	coordinates.emplace_back(0, 6);
	coordinates.emplace_back(2, 5);
	coordinates.emplace_back(7, 4);
	//coordinates.emplace_back(1, 0);
	//coordinates.emplace_back(3, 3);

	//coordinates.push_back(Coordinate(0, 6));
	//coordinates.push_back(Coordinate(2, 5));
	//coordinates.push_back(Coordinate(7, 4));

	for (Coordinate& c : coordinates)
		cout << c;

	
#pragma region Vectors
#if 1

	// Iterators represent generalization of pointers
	//	Object that has defined operation characteristical to pointers
	vector<Coordinate>::iterator begin = coordinates.begin();
	coordinates.erase(begin, begin + 2);

	cout << "\nErasing\n";
	for (Coordinate& c : coordinates)
		cout << c;


	cout << "\nRange\n";
	vector<Coordinate> coordinatesRange(coordinates.begin(), coordinates.end() - 1);
	for (Coordinate& c : coordinatesRange)
		cout << c;


	cout << "\nIterator\n";
	vector<Coordinate>::iterator it;
	it = coordinates.begin();
	while (it != coordinates.end())
		cout << *it++;
	
#endif
#pragma endregion
	
#pragma region Template iterators
#if 1



	// ostream_iterator<elementType, outputType>
	ostream_iterator<const Coordinate&, char> out_iter(cout, "\n");
	
#endif
#pragma endregion

	system("Pause>0");
}