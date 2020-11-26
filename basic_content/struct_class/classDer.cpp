#include <iostream>
using namespace std;

//类继承默认private
class Base
{
private:
	int m_num;
	void say()
	{
		cout << "Here in Base." << endl;
	}
public:
	void sayPub()
	{
		cout << "Here in Base.public." << endl;
	}
	Base(int m_n) :m_num(m_n) {};
	virtual ~Base() {};
};

class Der:public Base
{
private:
	int m_der;
public:
	Der(int m_d, int m_n) :m_der(m_d), Base(m_n) {};
	virtual ~Der() {};
};

int main()
{
	Der d(10, 20);
	//如果是private继承，下面二者都不可访问
	//d.say();//error
	//d.sayPub();//OK
	//如果不注明继承方式，下面二者也都不能访问
	//注明public方式，则sayPub可以访问
	//d.say();//error
	d.sayPub();//OK
	system("pause");
	return 0;
}