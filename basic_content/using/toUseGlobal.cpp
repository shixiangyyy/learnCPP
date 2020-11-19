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
	using ns1::func;//ʹ��ns1�еĺ���
#elif isGlobal
	using ::func;//ʹ��ȫ�ֺ���
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