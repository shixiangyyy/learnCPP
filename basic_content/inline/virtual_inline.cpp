#include <iostream>
using namespace std;

//虚函数也可以是内联函数，但是需要满足一定的条件
//通过某个类的具体对象调用，可以使用虚函数内联
//但是如果呈现的是运行时动态多态，则不能为内联
class Base
{
public:
	inline virtual void who()
	{
		cout << "Here in Base." << endl;
	}
	virtual ~Base() { cout << "Base::~Base()" << endl; }
};

class Derived :public Base
{
public:
	inline void who()
	{
		cout << "Here in Derived." << endl;
	}
	virtual ~Derived() { cout << "Derived::~Derived()" << endl; }
};

int main()
{
	//此处对who的调用，是通过类Base的具体对象b实现的，因此可以使用内联虚函数
	Base b;
	b.who();


	//此处的虚函数呈现运行时动态多态，需要在运行期间才能确定，所以不能为内联
	Base* bptr = new Derived();
	bptr->who();
	
	delete bptr;
	system("pause");
	return 0;
}