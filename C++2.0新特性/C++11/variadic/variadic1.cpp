#include <iostream>
using namespace std;

void printx(){}

//ģ���ػ��İ汾
template <typename T, typename...Args>
void printx(const T& firstArg, const Args&...args)
{
	cout << firstArg << endl;
	printx(args...);
}

//�����棬��������Խ����������
//������������ػ��汾��ģ���ʱ������ķ���ģ�彫��Զ��������
template <typename T, typename...Args>
void printx(const Args&...args)
{
	printx(args...);
}

int main()
{
	printx("hello world!", 2, 434, 5, 5, 5, 's', 'x');
	system("pause");
	return 0;
}