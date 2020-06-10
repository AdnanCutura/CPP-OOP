#include <iostream>
#include <vector>
using namespace std;

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
	}
	virtual ~Entity() { }

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
	virtual void Print() { cout << "Health: " << _health << "\nPower: " << _power << endl; }
};

class Enemy :public Entity
{
private:
	string _superPower;
public:
	Enemy(string superPower) { _superPower = superPower; }
	~Enemy() { }

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
	Player(string username = "New-Player")
	{
		_level = 0;
		_username = username;
	}
	~Player() { }
	int GetLevel() const { return _level; }
	string GetUsername() const { return _username; }


	void Print() override
	{
		Entity::Print();
		cout << "Username: " << _username << "\nLevel: " << _level << endl;
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

#pragma region Static casting
#if 1

	float f1 = 2.19;
	int i1 = f1;
	int i2 = static_cast<int>(f1);

	vector<int> v = static_cast<vector<int>>(10);
	cout << v.size() << endl;

	Player* player = new Player("adnan");
	Entity* e = static_cast<Entity*>(player);
	e->Print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	Entity* entity = new Entity(25, 5);
	Player* p = static_cast<Player*>(entity);
	p->Print();
#endif
#pragma endregion

#pragma region Dynamic casting
#if 0

	Entity* entitesList[4] = {
		new Player("Adnan Cutura"),
		new Enemy("Magic"),
		new Player("Edin Džeko"),
		new Enemy("Fire")
	};

	vector<Player> listOfPlayers;
	vector<Enemy> listOfEnemies;
	Player* playerAdnan = new Player("Adnan Čutura");
	Enemy* enemyFireball = new Enemy("Fire");

	Player p;
	Player p_bad;
	try
	{
		Player p = dynamic_cast<Player&>(*playerAdnan);
		Player p_bad = dynamic_cast<Player&>(*enemyFireball);
	}
	catch (exception& err)
	{
		cout << err.what() << endl;;
	}

	p.Print();
	p_bad.Print();
	cout << "........................" << endl;

	for (int i = 0; i < 4; ++i)
	{
		Player* player = dynamic_cast<Player*>(entitesList[i]);

		if (player)
		{
			listOfPlayers.push_back(*player);
			continue;
		}

		Enemy* enemy = dynamic_cast<Enemy*>(entitesList[i]);
		if (enemy)
			listOfEnemies.push_back(*enemy);
	}


	for (size_t i = 0; i < listOfPlayers.size(); i++)
	{
		listOfPlayers[i].Print();
		cout << "\n-------------------------\n";
	}

	cout << "\n*************************\n\n";
	for (size_t i = 0; i < listOfEnemies.size(); i++)
	{
		listOfEnemies[i].Print();
		cout << "\n-------------------------\n";
	}


#endif // 0
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

	system("Pause>0");
}
