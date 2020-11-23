#include <iostream>
using namespace std;

class Copyable
{
public:
	Copyable()
	{
		cout << "Default constructor!" << endl;
	}
	Copyable(const Copyable& o)
	{
		cout << "Copy constructor called!" << endl;
	}
};

Copyable ReturnRvalue()
{
	return Copyable();
}

void AcceptVal(Copyable a)
{

}

void AcceptRef(const Copyable& a)
{
	//Copyable���͵�a��ֱ�ӱ����const Copyable& a�������ͣ����û�з������ο������캯������
}

int main()
{
	cout << "pass by value:" << endl;
	AcceptVal(ReturnRvalue()); //Ӧ�õ������Σ����ǲ���ֻ������һ�ο������캯��
	cout << "pass by reference:" << endl;
	AcceptRef(ReturnRvalue()); //Ӧ��ֻ����һ�ο������캯��
	system("pause");
	return 0;
}