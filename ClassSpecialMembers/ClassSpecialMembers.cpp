#include <iostream>
#include <memory>

using namespace  std;

class Date
{
private:
	int* _day;
	int* _month;
	int* _year;
public:
	Date(int day, int month, int year)
	{
		_day = new int(day);
		_month = new int(month);
		_year = new int(year);
	}

	~Date()
	{
		delete _day; _day = nullptr;
		delete _month; _month = nullptr;
		delete _year; _year = nullptr;
	}

	friend ostream& operator <<(ostream& COUT, Date& date) {
		COUT << *date._day << "/" << *date._month << "/" << *date._year << endl;
		return COUT;
	}
};

class HolyClass
{
private:
	const int _constant;
	int& _referece;
	shared_ptr<int> _sharedPtr;
	Date _date;
public:
	HolyClass(int day, int month, int year, int constant, int& shared, int& reference) :_date(day, month, year), _constant(constant), _referece(reference)
	{
		_sharedPtr = make_shared<int>(shared);
	}
	friend ostream& operator <<(ostream& COUT, HolyClass& obj) {
		COUT << "Constant: " << obj._constant;
		COUT << "\nReference: " << obj._referece << " (" << &obj._referece << ")";
		COUT << "\nDate: " << obj._date;
		COUT << "Shared pointer: " << *obj._sharedPtr << " (" << obj._sharedPtr << ")" << " (" << &(*obj._sharedPtr) << ")";

		return COUT;
	}
};

int main()
{
	int ref = 700;
	const int constNum = 2000;
	int sharedNum = 1945;
	HolyClass holy(10, 5, 2020, constNum, sharedNum, ref);

	cout << "Ref: " << &ref;
	cout << "\nShared: " << &sharedNum;
	cout << "\n\n";

	cout << holy;
	system("Pause>0");
}
