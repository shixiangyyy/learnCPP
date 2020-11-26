#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base constructed!" << endl;
	}
	virtual ~Base()
	{
		cout << "Base destructed!" << endl;
	}
};

class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived constructed!" << endl;
	}
	virtual ~Derived()
	{
		cout << "Derived destructed!" << endl;
	}
};

int main()
{
	Derived* dptr = new Derived();
	Base* bptr = dptr;
	//������������дΪ�麯��ʱ��ɾ��bptr��ֻ����Base����������
	//����������дΪ�麯��ʱ��ɾ��bptr���Ⱥ����Derived��Base����������
	delete bptr;

	system("pause");
	return 0;
}