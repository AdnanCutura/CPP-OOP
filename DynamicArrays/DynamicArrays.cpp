#include <iostream>
using namespace std;

class Auto
{
private:
	string _naziv;
	int* _snagakW;
public:
	Auto(string naziv = "", int snagaKw = 0)
	{
		_naziv = naziv;
		_snagakW = new int(snagaKw);
	}
	Auto(const Auto& org)
	{
		_naziv = org._naziv;
		_snagakW = new int(*org._snagakW);
	}
	Auto& operator =(const Auto& org)
	{
		if (this == &org)
			return *this;

		delete _snagakW; _snagakW = nullptr;
		_naziv = org._naziv;
		_snagakW = new int(*org._snagakW);

		return *this;
	}

	friend ostream& operator << (ostream& COUT, Auto& automobil)
	{
		COUT << automobil._naziv << " - " << *automobil._snagakW << "KW\n";
		return COUT;
	}
	~Auto()
	{
		delete[] _snagakW; _snagakW = nullptr;
	}

};

class Radnik
{
private:
	float* _rating;
	string _ime;
public:
	Radnik(string ime, float rating)
	{
		_rating = new float(rating);
		_ime = ime;
	}
	Radnik(Radnik& radnik)
	{
		_ime = radnik._ime;
		_rating = new float(*radnik._rating);
	}
	Radnik& operator=(Radnik& radnik)
	{
		if (this == &radnik)
			return *this;

		delete _rating; _rating = nullptr;
		_ime = radnik._ime;
		_rating = new float(*radnik._rating);

		return *this;
	}
	string GetIme()const { return _ime; }
	float GetRating()const { return *_rating; }
	~Radnik()
	{
		delete _rating; _rating = nullptr;
	}

	friend ostream& operator << (ostream& COUT, Radnik& radnik)
	{
		COUT << radnik._ime << " - Rating: " << *radnik._rating << "\n";
		return COUT;
	}
};

class Salon
{
private:
	string _naziv;
	int _maxKapacitet;

	Auto* _automobili;
	int _trenutnoAutomobila;

	Radnik* _radnici[3];
	int _trenutnoRadnika;
public:
	Salon(string naziv, int maxKapacitet)
	{
		_naziv = naziv;
		_maxKapacitet = maxKapacitet;
		_trenutnoAutomobila = 0;
		_automobili = nullptr;
		_trenutnoRadnika = 0;
	}

	friend ostream& operator << (ostream& COUT, Salon& salon)
	{
		COUT << salon._naziv << "\nKapacitet:" << salon._maxKapacitet << "\n";
		COUT << "\nAutomobili " << salon._trenutnoAutomobila << "/" << salon._maxKapacitet << "\n";
		if (salon._trenutnoAutomobila > 0)
		{
			for (int i = 0; i < salon._trenutnoAutomobila; ++i)
				COUT << salon._automobili[i];
		}
		else
			COUT << "Trenutno nema ni jedan automobil.\n";

		COUT << "\nRadnici " << salon._trenutnoRadnika << "/" << 5 << "\n";
		if (salon._trenutnoRadnika > 0)
		{
			for (int i = 0; i < salon._trenutnoRadnika; ++i)
				COUT << *salon._radnici[i];
		}
		else
			COUT << "Trenutno nema ni jedan radnik.\n";

		return COUT;
	}

	bool DodajAutomobil(Auto* automobil)
	{
		if (_trenutnoAutomobila >= _maxKapacitet)
			return false;

		Auto* temp = new Auto[_trenutnoAutomobila + 1];

		for (int i = 0; i < _trenutnoAutomobila; ++i)
			temp[i] = _automobili[i];
		temp[_trenutnoAutomobila++] = *automobil;

		delete[] _automobili; _automobili = nullptr;

		_automobili = temp;
		temp = nullptr;

		return true;
	}
	bool DodajRadnika(Radnik* radnik)
	{
		if (_trenutnoRadnika >= 3)
			return false;
		
		_radnici[_trenutnoRadnika] = new Radnik(radnik->GetIme(), radnik->GetRating());
		_trenutnoRadnika++;
		return true;
	}

	~Salon()
	{
		delete[] _automobili; _automobili = nullptr;
		for (int i = 0; i < _trenutnoRadnika; ++i)
		{
			delete _radnici[i]; _radnici[i] = nullptr;
		}
	}
};

int main()
{
	Auto megane("Megane", 70);
	Auto bmw("BMW M3", 150);
	Auto golf("Golf", 70);

	Radnik adnan("Adnan", 4);
	Radnik edin("Edin", 5);
	Radnik haris("Haris", 3);
	Radnik niko("Niko", 1);

	Salon kramar("Kramar", 10);

	kramar.DodajAutomobil(&megane);
	kramar.DodajAutomobil(&bmw);
	kramar.DodajAutomobil(&golf);

	kramar.DodajRadnika(&adnan);
	kramar.DodajRadnika(&edin);
	kramar.DodajRadnika(&haris);
	kramar.DodajRadnika(&niko);

	cout << kramar;

	system("pause>0");
}