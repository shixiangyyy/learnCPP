#include <iostream>
//compile:g++ -o file son.cpp mom.cpp

extern int ext;

int main()
{
	std::cout << ext + 10 << std::endl;
	system("pause");
	return 0;
}