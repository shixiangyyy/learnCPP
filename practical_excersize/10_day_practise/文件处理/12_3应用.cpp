#include <iostream>
using namespace std;

//cin.put(char c)
//cin.write(const char* c, int n)
//���������
//ʹ��cin.write����ʵ�����һ���ַ���������ǰ����λ
int main()
{
	char c;
	char a[50] = "this is a string...";
	cout << "Use get() to input char: ";
	while ((c = cin.get()) != '\n')
	{
		cout.put(c);
		cout.put('\n');
		cout.put('t').put('h').put('i').put('s').put('\n');
		cout.write(a, 12).put('\n');
		cout << "look" << "\there!" << endl;
	}

	system("pause");
}