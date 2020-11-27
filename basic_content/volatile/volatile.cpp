#include <iostream>

int main()
{
	const volatile int local = 10;
	const volatile int* p = &local;
	int* ptr = (int *)&local;//ptr和p地址一样，类型不一样
	std::cout << "Initial value of local: " << *ptr << std::endl;

	*ptr = 100;
	//加volatile时，原始地const int local数值发生改变
	std::cout << "Modified value of local: " << local << std::endl;

	system("pause");
	return 0;
}