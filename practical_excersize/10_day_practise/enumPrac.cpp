#include <iostream>
using namespace std;

//�ڲ���Ա�����ⲿ������
//ע�⽫�ṹ�塢�ࡢ�����ռ�����������ö�����͵�������
typedef enum
{
	s, m, t, w, thu, f, sat
}WEEKDAY;

int main()
{
	WEEKDAY week = s;
	for (int i = week; i != WEEKDAY::sat; i++)
	{
		cout << i << endl;
		cout << week + s << endl;
		cout << "game over!" << endl;
	}

	system("pause");
	return 0;
}