#include <iostream>
using namespace std;

//final�ؼ������������ط�
//��һ�������࣬����˵��������������ܱ��̳У����򱨴�
class Base final
{
public:
	Base() {};
	virtual void func() {};
};

class Dericed :public Base{}; //Error,cannot derive from 'final'
//base "base" in derived type Derived
//��˼��Base�����˾�����������̳���

//�ڶ��������麯������ʾ���麯�������ٱ�override�ˣ���override�ᱨ��
class Base1
{
public:
	Base1() {};
	virtual void func()final {};
};

class Derived1 :public Base1
{
	virtual void func() {};//Error:overriding final function virtual void Base1::func()
};

int main()
{

}

