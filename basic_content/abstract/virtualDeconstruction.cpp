#include <iostream>
using namespace std;

//对比析构函数加上virtual前后的运行结果
class base
{
public:
	base()
	{
		cout << "Base" << endl;
	}
	virtual ~base()
	{
		cout << "~Base" << endl;
	}
};

class der :public base
{
public:
	der()
	{
		cout << "der" << endl;
	}
	virtual ~der()
	{
		cout << "~der" << endl;
	}
};

class der1 :public der
{
public:
	der1() {
		cout << "der1" << endl;
	}
	virtual ~der1() {
		cout << "~der1" << endl;
	}
};

int main() {
	base *Der = new der;
	cout << endl;
	der *Der1 = new der1;
	cout << endl;

	delete Der;
	cout << endl;
	delete Der1;
	cout << endl;

	return 0;
}