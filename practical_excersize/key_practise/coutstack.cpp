#include <iostream>
using namespace std;

//22335
//�ɼ�g++ʹ�ö��д���cout
//����������Щ������ʹ�õ�stack����cout
int main()
{
	int i = 1;
	cout << ++i << i++ << i << i++ << ++i << endl;
	system("pause");
}