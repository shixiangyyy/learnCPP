#include <iostream>
using namespace std;

//������
//���麯����û�к�������麯��
//������ָ�������麯������
//�����಻����Ϊ�����������ͣ�Ҳ������Ϊ���������������������Ϳ���
//���麯��Ϊ���������ṩһ����������
class A 
{
private:
	int a;
public:
	virtual void show() = 0;//���麯��
	void g() { this->show(); }
	A() {} //������A�Ĺ��캯��
};

void A::show() {
	cout << "Pure virtual function can also be implemented!" << endl;
}

class B :public A
{
public:
	//����������������Ǵ��麯������ô������Ҳ��������Ϊ������
	void show()
	{
		cout << "B:show()" << endl;
	}
};

int main() 
{
	/*�����಻�ܽ���ʵ����
	�������ָ�������ָ���ɳ�����������������Ķ���
	��ˣ����Զ���������ָ�룬���ǲ����ԶԳ��������ʵ����*/
	//abs a;//���󣬳����಻�ܴ�������
	//abs* a1;//��ȷ�����Զ���������ָ��
	//abs *a2 = new abs();//���󣬳����಻�ܴ�������
	A* p = new B;
	p->show(); //��B:show()��
	B b; //�ɳ�����������������ʵ�����Ķ���
	b.show();
	return 0;
}