#include <iostream>
using namespace std;

//通过纯虚虚构函数，让基类无法被实例化，只能通过子类实例化实现接口
//下述代码OK，因为纯虚析构函数被实现
//“纯虚函数的默认实现，仅仅是它再析构函数中才有意义”
class Abs
{
public:
	virtual ~Abs() = 0
	{
		cout << "~Abs" << endl;//可以不必有具体语句
	}
};

class interfAbs:public Abs
{

};

int main() {
	interfAbs* p = new interfAbs;
	delete p;
	Abs* p2 = new interfAbs;
	delete p2;

	return 0;
}

//下述代码发生链接时问题，报错说找不到Abs的析构函数实现
//原因是Abs的纯虚函数是纯虚的，空指针?
//因而，上述第一段代码，通过给纯虚析构函数实现，使得兼顾了父类的不可实例化，以及接口逻辑的实现
//class Abs
//{
//public:
//	virtual ~Abs() = 0;
//};
//
//class interfAbs :public Abs
//{
//
//};
//
//int main() {
//	interfAbs* p = new interfAbs;
//	delete p;
//	Abs* p2 = new interfAbs;
//	delete p2;
//
//	return 0;
//}