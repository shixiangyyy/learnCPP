#include <iostream>
using namespace std;

//���еľ�̬�����ɶ��������ڲ�ͬ�Ķ��󣬲�������ͬ��̬�����Ķ������
//Ҳ������Ϊ���ԭ�򣬾�̬���������ù��캯����ʼ��
class Apple
{
public:
	static int i;
	Apple()
	{
		//Do nothing
	};
};

int Apple::i = 3;//��ʼ����ʽ

int main()
{
	Apple obj1;
	Apple obj2;
	obj1.i = 1;
	obj2.i = 2;
	cout << obj1.i << endl;

	system("pause");
	return 0;
}