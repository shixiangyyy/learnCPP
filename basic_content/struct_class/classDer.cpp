#include <iostream>
using namespace std;

//��̳�Ĭ��private
class Base
{
private:
	int m_num;
	void say()
	{
		cout << "Here in Base." << endl;
	}
public:
	void sayPub()
	{
		cout << "Here in Base.public." << endl;
	}
	Base(int m_n) :m_num(m_n) {};
	virtual ~Base() {};
};

class Der:public Base
{
private:
	int m_der;
public:
	Der(int m_d, int m_n) :m_der(m_d), Base(m_n) {};
	virtual ~Der() {};
};

int main()
{
	Der d(10, 20);
	//�����private�̳У�������߶����ɷ���
	//d.say();//error
	//d.sayPub();//OK
	//�����ע���̳з�ʽ���������Ҳ�����ܷ���
	//ע��public��ʽ����sayPub���Է���
	//d.say();//error
	d.sayPub();//OK
	system("pause");
	return 0;
}