#include <iostream>
using namespace std;

#ifdef _DEBUG
#define LOG(x) cout << x << endl
#else
#define LOG(x)
#endif
// alocating memory
#define PAUSE system("Pause>0")


int main()
{
	LOG("Hello world");
	PAUSE;
}