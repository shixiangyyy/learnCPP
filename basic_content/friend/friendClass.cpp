#include <iostream>
using namespace std;

class A
{
private:
	int remains;
public:
	A(int rem):remains(rem){}
	virtual ~A(){}
	friend class B;
};

class B
{
private:
	int remains;
public:
	B(A& a) { this->remains = a.remains * 2; }
	int getRem() { return this->remains; }
	virtual ~B(){}
};

int main()
{
	A a(100);
	B b(a);
	cout <<  b.getRem() << endl;
	
	system("pause");
	return 0;
}