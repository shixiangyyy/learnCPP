#include <iostream>

int main()
{
	const volatile int local = 10;
	const volatile int* p = &local;
	int* ptr = (int *)&local;//ptr��p��ַһ�������Ͳ�һ��
	std::cout << "Initial value of local: " << *ptr << std::endl;

	*ptr = 100;
	//��volatileʱ��ԭʼ��const int local��ֵ�����ı�
	std::cout << "Modified value of local: " << local << std::endl;

	system("pause");
	return 0;
}