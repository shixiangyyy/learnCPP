#include <iostream>
//compile:g++ -o file const_file2.cpp const_file1.cpp
//execute:./file

extern const int ext;

int main()
{
	std::cout << ext << std::endl;
	system("pause");
	return 0;
}