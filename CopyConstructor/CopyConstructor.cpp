#include <iostream>
using namespace std;

class Akaunt
{
private:
	char* _korisnickoIme;
	char* _email;
	bool _isAktivan;

public:
	Akaunt(const char* korisnickoIme, const char* email, bool isAktivan = true)
	{
		int size = strlen(korisnickoIme) + 1;
		_korisnickoIme = new char[size];
		strcpy_s(_korisnickoIme, size, korisnickoIme);

		size = strlen(email) + 1;
		_email = new char[size];
		strcpy_s(_email, size, email);
		_isAktivan = isAktivan;
		cout << "Account created!\n";
	}

	// Konstruktor kopije
	Akaunt(const Akaunt& akaunt)
	{
		int size = strlen(akaunt._korisnickoIme) + 1;
		_korisnickoIme = new char[size];
		strcpy_s(_korisnickoIme, size, akaunt._korisnickoIme);

		size = strlen(akaunt._email) + 1;
		_email = new char[size];
		strcpy_s(_email, size, akaunt._email);
		_isAktivan = akaunt._isAktivan;
		cout << "Account copied!\n";
	}

	~Akaunt()
	{
		delete[] _korisnickoIme;
		_korisnickoIme = nullptr;
		delete[] _email;
		_email = nullptr;
		cout << "Account destroed!\n";
	}

	virtual void Ispisi()
	{
		cout << "---------------------\n";
		cout << "Korisnicko ime: " << _korisnickoIme << "\nEmail: " << _email << endl;
		cout << "---------------------\n";
	}

	Akaunt& operator = (Akaunt& akaunt)
	{
		if (this == &akaunt)
			return *this;

		delete[]_korisnickoIme;
		delete[]_email;

		int size = strlen(akaunt._korisnickoIme) + 1;
		_korisnickoIme = new char[size];
		strcpy_s(_korisnickoIme, size, akaunt._korisnickoIme);

		size = strlen(akaunt._email) + 1;
		_email = new char[size];
		strcpy_s(_email, size, akaunt._email);
		_isAktivan = _isAktivan;

		return *this;
	}


};

class Korisnik : virtual public Akaunt
{

private:
	float* _prosjecnaOcjena;
	string _ime;
	string _prezime;
public:
	Korisnik(const char* korisnickoIme, const char* email, string ime, string prezime, bool isAktivan = true)
		: Akaunt(korisnickoIme, email, isAktivan)
	{
		this->_ime = ime;
		this->_prezime = prezime;
		_prosjecnaOcjena = new float;
	}

	void setProsjecnaOcjena(float prosjecnaOcjena)
	{
		*_prosjecnaOcjena = prosjecnaOcjena;
	}
	void Ispisi() override
	{
		Akaunt::Ispisi();
		cout << "\nIme: " << _ime << "\nPrezime" << _prezime << endl;
	}
	~Korisnik()
	{
		delete _prosjecnaOcjena;
		_prosjecnaOcjena = nullptr;
	};

};

class Admin : virtual public Akaunt
{
private:
	bool _isGlavni;
public:
	Admin(const char* korisnickoIme, const char* email, bool isAktivan = true, bool isGlavni = false) : Akaunt(korisnickoIme, email, isAktivan)
	{
		this->_isGlavni = isGlavni;
	}
};

void Print_Copy(Akaunt akaunt) { akaunt.Ispisi(); }
void Print_Reference(Akaunt& akaunt) { akaunt.Ispisi(); }
void Print_Pointer(Akaunt* akaunt) { akaunt->Ispisi(); }

int main()
{

#pragma region Copy constructor on assignment
#if 0

	Akaunt a1("admin1", "admin@mail.com");

	// Ukoliko nemamo preklopljen operator dodjele pozvat će se defaultni konstruktor
	Akaunt a2 = a1;

	// Problem defaultnog konstruktora kopije
	/*
		&a1._email	0x00aff724 {0x00ef7fc8 "admin@mail.com"}	char * *
		&a2._email	0x00aff710 {0x00ef7fc8 "admin@mail.com"}	char * *
	*/

	a1.Ispisi();
	a2.Ispisi();

	/* Pri kraju programa pozvat će se destruktor za oba objekta i a1 i a2, a2 će pokušati dealocirati već dealociranu vrijednost i desit će se run-time error */


#endif

#pragma endregion

#pragma region Copy constructor in methods
#if 1

Akaunt a1("admin1", "admin@mail.com");
//Print_Copy(a1);
//Print_Reference(a1);
//Print_Pointer(&a1);
	
#endif
#pragma endregion

	system("pause>0");
}