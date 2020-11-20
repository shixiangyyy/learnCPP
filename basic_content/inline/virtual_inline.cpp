#include <iostream>
using namespace std;

//�麯��Ҳ����������������������Ҫ����һ��������
//ͨ��ĳ����ľ��������ã�����ʹ���麯������
//����������ֵ�������ʱ��̬��̬������Ϊ����
class Base
{
public:
	inline virtual void who()
	{
		cout << "Here in Base." << endl;
	}
	virtual ~Base() { cout << "Base::~Base()" << endl; }
};

class Derived :public Base
{
public:
	inline void who()
	{
		cout << "Here in Derived." << endl;
	}
	virtual ~Derived() { cout << "Derived::~Derived()" << endl; }
};

int main()
{
	//�˴���who�ĵ��ã���ͨ����Base�ľ������bʵ�ֵģ���˿���ʹ�������麯��
	Base b;
	b.who();


	//�˴����麯����������ʱ��̬��̬����Ҫ�������ڼ����ȷ�������Բ���Ϊ����
	Base* bptr = new Derived();
	bptr->who();
	
	delete bptr;
	system("pause");
	return 0;
}