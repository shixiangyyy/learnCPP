#include <iostream>
using namespace std;

class A
{
private:
	int remains;
public:
	A(int rem):remains(rem){}
	friend int getRem(A& a);
	virtual ~A(){}
};

int getRem(A& a)
{
	return a.remains;
}

int main()
{
	A a(100);
	cout << getRem(a) << endl;
	system("pause");
	return 0;
}