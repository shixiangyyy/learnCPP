#include <iostream>
#include <exception>
using namespace std;

class A
{
public:
	void vf()
	{
		cout << "I come from class A." << endl;
	}
};

//Example1:
//class B:public A{};
//class C:public A{};
//class D:public B, public C{};
//
//int main()
//{
//	D d;
//	//error: request for member 'vf' is ambiguous
//	d.vf(); //ERROR, 产生二义性问题
//
//	system("pause");
//	return 0;
//}

class B: virtual public A{};
class C: virtual public A{};
class D: virtual public B, public C{};

int main()
{
	D d;
	d.vf();

	system("pause");
	return 0;
}