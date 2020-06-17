#include <iostream>
#include <vector>
using namespace std;

#ifndef _DEBUG
#define Log(message)
#else
#define Log(message) cout<<"-> " << message << endl
#endif

const char* crt = "\n-------------------------\n";

class Entity
{
private:
	float _health;
	float _power;
public:
	Entity(float health = 10, float power = 0)
	{
		_health = health;
		_power = power;
		Log("Entity created");
	}
	virtual ~Entity() { Log("Entity deleted"); }

	void SetHealth(float health)
	{
		_health = health;
	}
	void SetPower(float power)
	{
		_power = power;
	}
	float GetPower() const
	{
		return _power;
	}
	float GetHealth() const
	{
		return _health;
	}
	virtual void Print() { cout << "Health: " << _health << "\nPower: " << _power << "\n"; }
};
class Enemy :public Entity
{
private:
	string _superPower;
public:
	Enemy(string superPower, float health = 10, float power = 0) :Entity(health, power)
	{
		_superPower = superPower; Log("Enemy created");
	}
	~Enemy() { Log("Enemy deleted"); }

	void Print() override
	{
		Entity::Print();
		cout << "Super power: " << _superPower << endl;
	}
};
class Player :public Entity
{
private:
	string _username;
	int _level;
public:
	Player(string username = "New-Player", float health = 10, float power = 0) :Entity(health, power)
	{
		_level = 0;
		_username = username;
		Log("Player created");
	}
	~Player() { Log("Player deleted"); }
	int GetLevel() const { return _level; }
	string GetUsername() const { return _username; }


	void Print() override
	{
		Entity::Print();
		cout << "Username: " << _username << "\nLevel: " << _level << "\n\n";
	}
};
class Object
{
	float _health;
	float _power;
public:
	Object(float health = 10, float power = 0)
	{
		_health = health;
		_power = power;
	}
	virtual ~Object() {};

	operator Entity()
	{
		cout << "Reinterpret conversion." << endl;
		return Entity(_health, _power);
	}

	void Print() const { cout << "Health: " << _health << "\nPower: " << _power << endl; }
};

int main()
{

	Entity e1(15, 100);
	Player p1("Adnan Cutura", 20, 100);

	Player* p1pok = new Player("AdoNet", 30, 200);

#pragma region Upcasting

#pragma region Implicit and explicit
#if 0

	// Implicitly upcasting Player to Entity
	Entity e2 = p1;
	e2.Print(); cout << endl;

	Entity* e4 = &p1;
	e4->Print(); cout << endl;

	Entity* e5 = p1pok;
	e5->Print(); cout << endl;

	Entity e6 = *p1pok;
	e6.Print(); cout << endl;

	//Explicitly upcasting Player to Entity
	Entity e3 = (Entity)p1;
	e3.Print(); cout << endl;

	e4 = nullptr; e5 = nullptr;
#endif
#pragma endregion

#pragma region Static_cast
#if 0

	// Left side is pointer, right is object
	Entity* e2Pok = static_cast<Entity*>(&p1); // Forbidden dealocation since pointer points to Entity which has destructor
	e2Pok->Print(); cout << endl;

	// Left and right side are pointers
	Entity* e3Pok = static_cast<Entity*>(p1pok);
	e3Pok->Print(); cout << endl;

	// Left side is object, right is pointer
	Entity e7 = static_cast<Entity&>(*p1pok);
	e7.Print(); cout << endl;

	// Left and right side are objects
	Entity e8 = static_cast<Entity&>(p1);
	e8.Print();  cout << endl;

	e2Pok = nullptr; e3Pok = nullptr;

#endif
#pragma endregion

#pragma region  Virutal constructor
#if 0
	Entity* entity = new Entity;
	delete entity;

	cout << "---------------\n";
	Player* player = new Player;
	delete player;

	cout << "---------------\n";
	// Memory leak without virtual destructor
	// Virutal constructor will not override but call down in the hierarchy next one
	Entity* polyBase = new Player("Adnan");
	delete polyBase;
#endif
#pragma endregion

#pragma endregion

#pragma region Downcasting
#if 0

#pragma region Implicit and explicit
#if 0

	// Implicit downcast is forbidden, it will results in creating a compile-time error
	// Player sE1 = e1;
	// Player* sE2 = &e1;

	// Explicitly downcasting Entity to Player

	// Error: Triggering copy constructor, since e1 hasn't Player data, during the copy of empty pointer it will create run-time error
	//Player pE3 = (Player&)e1;

	Player* p2 = (Player*)&e1;
	p2->Print();

	p2 = nullptr;

#endif
#pragma endregion

#pragma region Dynamic and static cast
#if 0

	Entity* entities[4] = {
		new Player("Player_1",10,10),
		new Player("Player_2",20,20),
		new Enemy("Fireball",30,20),
		new Enemy("Wizard",20,30),
	};

	for (int i = 0; i < 4; ++i)
	{
		// Dynamic downcasting Entity to player with a pointer to class as a return type
		Player* pDynamic = dynamic_cast<Player*>(entities[i]);

		if (pDynamic != nullptr)
		{
			cout << "-> Player\n";
			pDynamic->Print();
		}
		else
		{
			// Static downcasting Entity to Enemy with a pointer to class as a return type
			Enemy* eStatic = static_cast<Enemy*>(entities[i]);
			cout << "-> Enemy\n";
			eStatic->Print();
		}

		cout << crt;
	}

	for (int i = 0; i < 4; ++i)
	{
		try
		{
			// Dynamic downcasting Entity to player with a reference to class as a return type
			Player pDynamic = dynamic_cast<Player&>(*entities[i]);
			pDynamic.Print();
		}
		catch (exception& err)
		{
			cout << "-> Error: " << err.what() << endl;
		}
		cout << crt;
	}

#endif
#pragma endregion

#endif
#pragma endregion

#pragma region Const casting
#if 0
	const Player playerConst = Player("Constant attacker");
	//Player* player = const_cast<Player*>(&playerConst); //static_cast cannot cast away const or other type qualifiers
	Player player = const_cast<Player&>(playerConst); //static_cast cannot cast away const or other type qualifiers

#endif
#pragma endregion

#pragma region Reinterpret casting
#if 0

	Entity* entity = new Entity(88, 55);
	Object* object = reinterpret_cast<Object*>(entity);

	entity->Print();
	cout << endl;
	object->Print();

#endif
#pragma endregion

}