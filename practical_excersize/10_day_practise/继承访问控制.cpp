#include <iostream>
using namespace std;

class Base
{
public:
	Base(int i) :crt(i) {};
	int getCRT() { return crt; }
	void base() {};
protected:
	void changeCRT(int i) { crt = i; };
	void basepro() {};
private:
	int crt;
};

class derpub :public Base
{
public:
	derpub(int i, int b) :crt(i), Base(b) { cout << "derpub constructed." << endl; }
	int getCRT() { return crt; };
	int getBaseCRT()
	{
		//return Base::crt;//error,基类私有成员不可以直接访问
		return Base::getCRT();//OK,可以通过基类公有成员函数调用
	}
	void change(int i) { changeCRT(i); } //可以通过对象调用共有函数调用别的
protected:
	void changeCRT(int i) { crt = i; } //对象中不可以直接调用
private:
	int crt;
};

class derpro :protected Base
{
public:
	derpro(int i, int b) :crt(i), Base(b) { cout << "derpro constructed." << endl; }
	int getCRT() { return crt; };
	int getBaseCRT()
	{
		//return Base::crt;//error,基类私有成员不可以直接访问
		return Base::getCRT();//OK,可以通过基类公有成员函数调用
	}
	void change(int i) { changeCRT(i); } //可以通过对象调用共有函数调用别的
protected:
	void changeCRT(int i) { crt = i; } //对象中不可以直接调用
private:
	int crt;
};

class derpri : private Base
{
public:
	derpri(int i, int b) :crt(i), Base(b) { cout << "derpri constructed." << endl; }
	int getCRT() { return crt; };
	int getBaseCRT()
	{
		//return Base::crt;//error,基类私有成员不可以直接访问
		return Base::getCRT();//OK,可以通过基类公有成员函数调用
	}
	void change(int i) { changeCRT(i); } //可以通过对象调用共有函数调用别的
protected:
	void changeCRT(int i) { crt = i; } //对象中不可以直接调用
private:
	int crt;
};

int main()
{
	//public继承
	derpub dpub(1, 2);
	dpub.base();//OK，可以通过派生类对象调用基类公有函数
	//dpub.basepro();//ERROR,基类protected成员不可以在派生类对象调用
	dpub.change(5);
	cout << dpub.getBaseCRT() << endl;
	//dpub.changeCRT();//ERROR,protected成员在对象中不可访问
	cout << dpub.getCRT() << endl;

	//protected继承
	derpro dpro(10, 100);
	cout << dpro.getCRT() << endl;
	cout << dpro.getBaseCRT() << endl;
	//dpro.base();//ERROR，不能调用基类public成员，因为经过保护继承属性变为protected
	//dpro.basepro();//ERROR,变为protected
	dpro.change(1000);
	cout << dpro.getCRT() << endl;

	//private继承
	derpri dpri(1000, 10000);
	//dpri.base();//ERROR,调用基类public成员
	cout << dpri.getCRT() << endl;
	cout << dpri.getBaseCRT() << endl;

	system("pause");
	return 0;
}