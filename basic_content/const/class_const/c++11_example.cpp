#include <iostream>
#include <cassert>
using namespace std;

//����ʹ��const����������׳�Ե�C++11����
//const��Ա����ֻ�ܵ��ó���Ա�����Ҳ��ܶ��κγ�Ա���������޸�
//��ͨ��Ա�����������������ͨ���߳���Ա�������߱���
//��ĳ�����ֻ�ܵ�����ĳ���Ա�������߳�����
//��Ϊ���ܶԳ������������޸ģ�������÷ǳ���Ա�������߱������������޸��������Ե�Σ��
//���ڴˣ����������Ľ�׳�ԣ����Կ���Ϊ���ֺ�������const���ͳ�Ա�������Է�����ĳ�������е���
//��const������Է��������Ա����
class Apple
{
private:
	int people[100];
public:
	Apple(int i);
	static const int appleNum = 100;//c++11����ֱ�Ӷ��崦��ֵ��������Ҫʹ�ó�ʼ���б�
	void take(int num) const;
	int add(int num);
	int add(int num) const;
	int getCount() const;
};

//Ҳ������������д��
//static const int appleNum;
//Ȼ�����������³�ʼ������Ա��
//const int Apple::appleNum = 100;
//C++11�������ע�ʹ��룬������ֱ�ӽ��г�ʼ��

Apple::Apple(int i){}

void Apple::take(int num) const
{
	cout << "Take " << num << " apples from the bag!" << endl;
}

int Apple::add(int num)
{
	take(num);
	return 0;
}

//����add������Ϊ����Ա�����������������
int Apple::add(int num) const
{
	take(num);
	return 0;
}

int Apple::getCount() const
{
	take(1);
	return appleNum;
}

int main()
{
	Apple a(2);
	cout << a.getCount() << endl;
	a.add(10);
	const Apple b(10);
	b.add(100);
	return 0;
}