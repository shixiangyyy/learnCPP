#include <iostream>
//#define isNs1 1
#define isGlobal 1
using namespace std;

void func()
{
	cout << "::func()" << endl;
}

namespace ns1
{
	void func()
	{
		cout << "ns1::func()" << endl;
	}
}

namespace ns2
{
#ifdef isNs1
	using ns1::func;//使用ns1中的函数
#elif isGlobal
	using ::func;//使用全局函数
#else
	void func()
	{
		cout << "Other::func" << endl;
	}
#endif
}

int main()
{
	ns2::func();
	system("pause");
	return 0;
}