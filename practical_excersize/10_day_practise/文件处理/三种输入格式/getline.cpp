#include <iostream>
using namespace std;

//cin.getline(arrayname, size)��cin.get(arrayname, size)������
//get����[enter]ʱ��������룬���ǲ���ɾ���������е�[enter];
//getline����[enter]ʱҲ�������ǰ���룬���ǻ�ɾ���������е�[enter]
//���Ƶأ�
//cin.getline(arrayname, size, s)��cin.get(arrayname, size, s)������
//getline����sʱ��������룬Ҳ����������е�s��������һ��cin��ȡ
//get����sʱҲ��������룬���ǲ�����������е�s�����Ա���һ��cin��ȡ��
int main()
{
	/*asfasfsss
	asfasfsss
	10*/
	//char a[10];
	//char b;
	//cin.get(a, 10); //����[enter]ֹͣ�����ǲ����������[enter]
	//cin.get(b); //���ܶ��ո�
	//cout << a << endl << int(b);

	/*���룺
	12345
	a
	�����
	12345
	97*/
	//char a[10];
	//char b;
	//cin.getline(a, 10); //�����ո�ͣ���������������[enter]
	//cin.get(b); //��������ո�
	//cout << a << endl << int(b);

	/*���룺
	asfjldsff
	���:
	a
	f*/
	//char a[10];
	//char b;
	//cin.getline(a, 10, 's'); //����s������a�����룬����������޳�s������ʣ��ı���
	//cin.get(b);
	//cout << a << endl << b;

	/*����:
	asffsdf
	�����
	a
	s*/
	char a[10];
	char b;
	cin.get(a, 10, 's'); //����s������a�����룬�����s���ᱻ�޳�������ʣ��ı���
	cin.get(b);
	cout << a << endl << b;

	system("pause");
}