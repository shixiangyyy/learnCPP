#include <iostream>
using namespace std;

//https://blog.csdn.net/qq_35524916/article/details/58178072
//c++�У�����һ������(���߳��˵�һ���������⣬������������Ĭ��ֵ�Ķ����)�Ĺ��캯���е����ֽ�ɫ��
//1������
//2����Ϊһ��Ĭ�϶�������������ת��������
//���磺aaa=xxx������xxxǡ����aaa���������캯�����β����ͣ�����������Զ����øù�����������һ��aaa�Ķ���
//���ԣ�
//��ʱ���������Ҫ�ù��ܶ�������ɻ�����ʹ��explicit�ؼ��ֶԹ��캯����������
//�Ա�������Ϊ����ת��������������ʹ��
class Test1
{
private:
	int n;
public:
	Test1(int num):n(num){}
};

//ʹ��explicit���ε��������캯�����Ա�����ʽת���븴�Ƴ�ʼ��
class Test2
{
private:
	int n;
public:
	explicit Test2(int num):n(num){}
};

int main()
{
	Test1 t1 = 12; //OK,Test1��û����explicit���ε��������캯����������ʽת��
	Test2 t2(13);//OK,ֱ�ӳ�ʼ��
	//Test2 t3 = 14;//error,�޷���14 int������ʽת��������ʼ��t3

	return 0;
}