#include <iostream>
using namespace std;

//���캯��������Ϊ�麯��
//�����麯����vtable�Ǳ���ʱ�����������麯����ָ��vptr�������н׶�ʵ��������Ų�����
//��ʵ����������Ҫ�õ����캯��������ʱ��vptr��û��������˹��캯���������麯��
//֮����ʹ���麯������Ϊ������Ϣ����ȫ��ʱ��ʵ�ֳ���Ķ�̬����
//����ຬ���麯������ô���������ڹ��캯������Ӵ���������vptr,������vtable��Ҫvptr
class Base
{
public:
};

class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived created!" << endl;
	}
	//Copy constructor
	Derived(Derived &rhs)
	{
		cout << "Derived created by deep copy!" << endl;
	}
	~Derived()
	{
		cout << "Derived destroyed." << endl;
	}
};

int main()
{
	Derived s1;
	Derived s2 = s1;

	//˼�����ͨ��ָ������ָ��������������ĳ�ʼ��

	system("pause");
	return 0;
}