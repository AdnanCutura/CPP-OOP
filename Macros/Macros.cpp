#include <iostream>
using namespace std;

#ifdef _DEBUG
#define LOG(x) cout << x << endl
#else
#define LOG(x)
#endif
// alocating memory
#define PAUSE system("Pause>0")
#define getmax(a,b) a>b?a:b

int main()
{
	LOG("Hello world");

	int a = getmax(2, 3);
	cout << "Max: " << a << endl;


    cout << "This is the line number " << __LINE__;
    cout << " of file " << __FILE__ << ".\n";
    cout << "Its compilation began " << __DATE__;
    cout << " at " << __TIME__ << ".\n";
    cout << "The compiler gives a __cplusplus value of " << __cplusplus;

	PAUSE;
}