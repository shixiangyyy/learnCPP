//ͨ�����Ա�������ᱻ�����������Ƿ��������
//����ͨ������ָ���������õ��õ��麯���ض����ܱ�����
//��Ȼ��ʵ���������麯�����߾�̬����ʱ���Ա������������������ľ�̬����Ҳһ���ᱻ����չ��
#include <iostream>
using namespace std;

class Base
{
public:
	inline virtual void who()
	{
		cout << "I'm Base.\n";
	}
	virtual ~Base() {};
};

class Derived :public Base
{
public:
	inline void who()//��дinlineʱ��ʽ����
	{
		cout << "I'm Derived.\n";
	}
};

int main()
{
	//�����Ƿ�����ȡ���ڱ�����
	//�˴�ͨ����������麯������Ҫע���������ĵ��ý����ڱ���ʱ����˿���ʹ������
	Base b;
	b.who();//ͨ�������������麯��

					//�˴�ͨ��ָ������麯������������ʱ��̬���������޷�ȷ��ʹ���ĸ����������Բ�������
	Base* bptr = new Derived();
	bptr->who();
	delete bptr;//�������������������ٻ�����������

	system("pause");
	return 0;
}