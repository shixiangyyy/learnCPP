#include <iostream>
using namespace std;

//������
//���麯����û�к�������麯��
//������ָ�������麯������
class A 
{
private:
	int a;
public:
	virtual void show() = 0;//���麯��
	void g() { this->show(); }
	A() {} //������A�Ĺ��캯��
};

class B :public A
{
public:
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

	B b; //�ɳ�����������������ʵ�����Ķ���
	b.show();
	return 0;
}