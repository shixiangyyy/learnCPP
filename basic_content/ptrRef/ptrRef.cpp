#include <iostream>
using namespace std;

class Copyable
{
public:
	Copyable()
	{
		cout << "Default constructor!" << endl;
	}
	Copyable(const Copyable& o)
	{
		cout << "Copy constructor called!" << endl;
	}
};

Copyable ReturnRvalue()
{
	return Copyable();
}

void AcceptVal(Copyable a)
{

}

void AcceptRef(const Copyable& a)
{
	//Copyable类型的a，直接变成了const Copyable& a引用类型，因此没有发生二次拷贝构造函数调用
}

int main()
{
	cout << "pass by value:" << endl;
	AcceptVal(ReturnRvalue()); //应该调用两次，但是测试只调用了一次拷贝构造函数
	cout << "pass by reference:" << endl;
	AcceptRef(ReturnRvalue()); //应该只调用一次拷贝构造函数
	system("pause");
	return 0;
}