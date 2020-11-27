#include <iostream>

int main()
{
	const int local = 10;
	int* ptr = (int *)&local;
	std::cout << "Initial value of local: " << *ptr << std::endl;

	*ptr = 100;
	std::cout << "Modified value of local: " << local << std::endl;

	system("pause");
	return 0;
}