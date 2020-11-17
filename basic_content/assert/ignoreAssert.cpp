//可以通过#define NDEBUG来关闭assert
#define NDEBUG
#include <assert.h>
#include <iostream>
using namespace std;

int main()
{
	int x = 7;
	assert(x == 5);
	cout << "assert is closed!" << endl;
	return 0;
}