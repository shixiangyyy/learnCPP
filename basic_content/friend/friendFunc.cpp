#include <iostream>
using namespace std;

class A
{
private:
	int remains;
	static void toUse() { cout << "A's private function called!" << endl; };
public:
	A(int rem) :remains(rem) {};
	friend void callPrivate();
	friend int getRem(A& a);
	virtual ~A() {};
};

void callPrivate()
{
	A::toUse();
}

int getRem(A& a)
{
	return a.remains;//通过具体对象调用
}

int main()
{
	A a(100);
	cout << getRem(a) << endl;
	callPrivate();
	system("pause");
	return 0;
}