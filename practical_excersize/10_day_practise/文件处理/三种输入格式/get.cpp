#include <iostream>
using namespace std;

int main()
{
	char a, b, c, d;
	cin.get(a);
	cin.get(b);
	c = cin.get();
	d = cin.get();
	cout << int(a) << " " << int(b) << " " << int(c) << " " << int(d) << endl;
	//"abcd"ʱ�����97 98 99 100
	//a�س�b�س� ʱ����ʱ���Ѿ�����4��char�����97 10 98 10

	//ԭ��:��ֱ��cin>>��ͬ��cin.get()�ڻ��������������ո�(ENTER),[space],[tab]�Ȳ�����������
	//���Ƕ�����ASCII����������

	system("pause");
	return 0;
}