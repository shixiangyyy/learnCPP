#include <iostream>
using namespace std;

//����������Ϊstaticʱ���ռ佫�ڳ�������������ڷ���
//��ʹ��ε��øú�������̬�����Ŀռ�Ҳֻ����һ��
//��������Ҫά�ֺ���״̬�ĳ���
void demo()
{
	static int i = 0;
	cout << i++ << endl;
}

int main()
{
	for (int i = 0; i <= 5; i++)
		demo();
	system("pause");
	return 0;
}