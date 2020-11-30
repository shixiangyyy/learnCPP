#include <iostream>
using namespace std;

class  Base
{
public:
	virtual ~Base() {};
	void setB(int x) { b = x; };
	void getB() { cout << b << endl; }

private:
	int b;
};

class Der :public Base
{
public:
	virtual ~Der() {};
	void setD(int x) { d = x; };
	void getD() { cout << d << endl; };
private:
	int d;
};

int main()
{
	Base b, *bptr;
	Der d, *dptr;
	b.setB(10);
	b.getB();
	d.setD(20);
	d.getD();

	//对象之间互相赋值
	b = d;
	cout << "b after assignment from d:\n";
	b.getB();//0,因为没有对值初始化，默认为0
	//不允许
	/*Der d1 = b;
	d1.setD(15);
	d1.getD();*/

	//派生类地址赋值给基类指针
	bptr = &d;
	bptr->setB(35);
	bptr->getB();
	//不允许
	/*Der* dptr = new Base(40);
	dptr->setD(45);
	dptr->getD();*/

	//派生类对象初始化基类对象引用
	//Base& rb = Der(50);//error: cannot bind non-const lvalue reference of type 'Base&' to an rvalue of type 'Base'
	Base& rb = d;
	rb.setB(55);
	rb.getB();
	//不允许
	/*Der& rd = Base(60);
	rd.setD(65);
	rd.getD();*/

	system("pause");
	return 0;
}

