#include <iostream>
#include "inline.h"
using namespace std;

inline void A::Foo(int x, int y)
{
	cout << x * A_x - y * A_y << endl;
}

inline void A::f1(int x)
{
	cout << x * A_x << endl;
}

int main()
{
	A a(5, 10);
	a.f1(5);
	a.Foo(5, 10);

	system("pause");
	return 0;
}