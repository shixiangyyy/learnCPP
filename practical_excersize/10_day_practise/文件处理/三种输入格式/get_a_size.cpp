#include <iostream>
using namespace std;

//cin.get(arrayname, size):���ַ����뵽arrayname�У����Ȳ�����size
int main()
{
	//size��Ӳ���������������sizeʱ����ȡsize-1���ַ�������'\0'
	//����������ģ�������Ϊsize��ȡ��ģ�������arrayname��С��ʱ��ֱ�Ӵ��룬����ʱ��arrayname�Զ�����

	////1�����봮�� < size && ���봮�� > arraylengthʱ�����Զ�����arrayname�Ĵ�С, ʹ�ܱ���������������
	//char a[10];
	//cin.get(a, 20);
	//cout << a << endl;
	//cout << sizeof(a) << endl; //�����Ժ�a��size����10����ʹa�Ѿ�����
	//cout << a[12] << endl; //������������ź������
	////2�����봮�� < size && ���봮�� <arraylengthʱ���Ѵ�ȫ�����룬���油'\0'
	//char b[10];
	//cin.get(b, 20);
	//cout << b << endl;
	//cout << sizeof(b) << endl;
	////3�����봮�� > size���Ƚ�ȡsize - 1���ַ��������Ǵ���arraylength,��ִ������1���Զ�����arrname��ʹ�ܱ�������
	//char c[10];
	//cin.get(c, 15);
	//cout << c << endl;
	//cout << sizeof(c) << endl;
	////4�����봮�� > size���Ƚ�ȡsize - 1���ַ�����С��array length����ѽ�ȡ�Ĵ���array��������'\0'
	//char d[20];
	//cin.get(d, 15);
	//cout << d << endl;
	//cout << sizeof(d) << endl;

	//get(arrayname, size, c)���ַ�
	//�����������뵽arrayname�У������ȵ���size��������c�ַ�ʱ����
	//����arrayname�������ַ����飬������Ϊstring���ͣ�cΪ���ƣ���������cʱ����������
	char e[15];
	cin.get(e, 10, '\t'); //����sizeʱ����ȡsize-1��������'\0'
	cout << e << endl;
	cout << sizeof(e) << endl;

	system("pause");
}