#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

template <typename T1, typename  T2>
class Dictionary
{
private:
	T1* _array1;
	T2* _array2;
	int _numElements;
public:
	Dictionary()
	{
		_array1 = nullptr;
		_array2 = nullptr;
		_numElements = 0;
	}
	~Dictionary()
	{
		delete[] _array1; _array1 = nullptr;
		delete[] _array2; _array2 = nullptr;
	}
	Dictionary(const Dictionary& dict)
	{
		cout << "Copy constructor!\n";
		_numElements = dict._numElements;
		_array1 = new T1[_numElements];
		_array2 = new T2[_numElements];

		for (int i = 0; i < _numElements; ++i)
		{
			_array1[i] = dict._array1[i];
			_array2[i] = dict._array2[i];
		}
	}
	Dictionary& operator = (const Dictionary& dict)
	{
		cout << "Operator = !\n";
		if (this == &dict)
			return *this;

		delete[] _array1; _array1 = nullptr;
		delete[] _array2; _array2 = nullptr;

		_numElements = dict._numElements;
		_array1 = new T1[_numElements];
		_array2 = new T2[_numElements];

		for (int i = 0; i < _numElements; ++i)
		{
			_array1[i] = dict._array1[i];
			_array2[i] = dict._array2[i];
		}

		return *this;
	};
	void AddElement(T1 elem1, T2 elem2)
	{
		T1* temp1 = new T1[_numElements + 1];
		T2* temp2 = new T2[_numElements + 1];

		for (int i = 0; i < _numElements; ++i)
		{
			temp1[i] = _array1[i];
			temp2[i] = _array2[i];
		}

		temp1[_numElements] = elem1;
		temp2[_numElements++] = elem2;

		delete[] _array1; _array1 = nullptr;
		delete[] _array2; _array2 = nullptr;

		_array1 = temp1;
		_array2 = temp2;

		temp1 = nullptr;
		temp2 = nullptr;
	}

	friend ostream& operator <<(ostream& COUT, Dictionary<T1, T2>& collection)
	{
		for (int i = 0; i < collection._numElements; ++i)
			COUT << collection._array1[i] << " - " << collection._array2[i] << "\n";
		return COUT;
	}

	T1* GetArray1()const { return _array1; };
	T2* GetArray2()const { return _array2; };
	T1& GetElement1ByIndex(int index)const {
		if (index >= _numElements)
			throw exception("Index exceed dictionary size!");
		return _array1[index];
	};
	T1& GetElement2ByIndex(int index)const {
		if (index >= _numElements)
			throw exception("Index exceed dictionary size!");
		return _array2[index];
	};

	tuple<T1, T2> GetByIndex(int index) const {

		if (index >= _numElements)
			throw exception("Index exceed dictionary size!");

		return make_tuple(_array1[index], _array2[index]);
	};
	Dictionary<T1, T2> GetRange(int from, int to)const
	{

		if (to > _numElements)
			throw exception("Index exceed dictionary size!");

		if (from > to)
			throw exception("From must be less or equal than To!");

		if (from < 0)
			throw exception("From must be greater than 0!");

		Dictionary<T1, T2> dictionary;

		dictionary._numElements = to - from - 1;
		dictionary._array1 = new T1[dictionary._numElements];
		dictionary._array2 = new T2[dictionary._numElements];

		//for (int i = from, j = 0; i < to - 1; i++, j++)
		for (int i = from, j = 0; j < dictionary._numElements; i++, j++)
		{
			// operator dodjele
			dictionary._array1[j] = _array1[i];
			dictionary._array2[j] = _array2[i];
		}

		return dictionary;
	}
	void RemoveAt(int index)
	{
		if (index < 0 || index >= _numElements)
			throw exception("Index exceeded dictionary size!");

		T1* temp1 = new T1[_numElements - 1];
		T2* temp2 = new T2[_numElements - 1];

		for (int i = 0, j = 0; i < _numElements; ++i)
		{
			if (i == index)
				continue;
			temp1[j] = _array1[i];
			temp2[j++] = _array2[i];
		}

		delete[] _array1; _array1 = nullptr;
		delete[] _array2; _array2 = nullptr;

		_array1 = temp1;
		_array2 = temp2;
		--_numElements;

		temp1 = nullptr; temp2 = nullptr;

	}

	void SortDescending()
	{
		sort(_array1, _array1 + _numElements, [](T1 a, T1 b)
			{
				return a > b;
			});
		sort(_array2, _array2 + _numElements, [](T2 a, T2 b)
			{
				return a > b;
			});
	}
	void SortAscending()
	{
		sort(_array1, _array1 + _numElements, [](T1 a, T1 b)
			{
				return a < b;
			});
		sort(_array2, _array2 + _numElements, [](T2 a, T2 b)
			{
				return a < b;
			});
	}
};

int main()
{
	Dictionary<int, float> dictionary;

#pragma region Fill dictionary

	for (int i = 1; i < 11; ++i)
		dictionary.AddElement(i + 2, i * 0.5);

	cout << dictionary << endl;

#pragma endregion

#pragma region Get Dictionary pairs by index
	
	int elem1; float elem2;
	tie(elem1, elem2) = dictionary.GetByIndex(5);
	cout << elem1 << " - " << elem2 << "\n";

#pragma endregion

#pragma region Get Dictionary array
	
	int* a1 = dictionary.GetArray1();

	for (int i = 0; i < 10; ++i)
		cout << *(a1 + i) << "\n";
	
#pragma endregion

#pragma region Get range from dictionary
	
	//Copy constructor required
	Dictionary<int, float> range = dictionary.GetRange(2, 7);
	cout << range << endl;
	
#pragma endregion
#pragma region Remove at certain index
	
	dictionary.RemoveAt(3);
	cout << dictionary;
	
#pragma endregion

#pragma region Sorting
	
	dictionary.SortDescending();
	cout << dictionary;

	dictionary.SortAscending();
	cout << dictionary;
	
#pragma endregion
	
	system("Pause>0");
}
