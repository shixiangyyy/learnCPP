#include <iostream>
//ʹ��extern "C",������������Ӧ��Ѱ������_add�����C���Ժ������ţ�������CPP����add_int_int
extern "C"
{
	#include "add.h"
}
using namespace std;

int main()
{
	cout << add(2, 3) << endl;
	system("pause");
	return 0;
}