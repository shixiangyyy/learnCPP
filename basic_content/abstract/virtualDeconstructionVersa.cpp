#include <iostream>
using namespace std;

//һ����˵��һ����������������麯������ô����������ҲӦ�ö���Ϊ�麯��
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

class der:public base
{
public:
	der()
	{
		cout << "Derived" << endl;
	}
	~der()
	{
		cout << "~der" << endl;
	}
};

class der1 :public der
{
public:
	der1()
	{
		cout << "der1" << endl;
	}
	~der1()
	{
		cout << "~der1" << endl;
	}
};

int main()
{
	base* b = new der;
	der* Der1 = new der1;
	delete b;
	delete Der1;

	return 0;
}