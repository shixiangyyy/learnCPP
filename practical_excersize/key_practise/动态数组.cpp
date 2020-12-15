#include <iostream>
#include <cstring>

int main()
{
	char* sPtr;
	const char* s = "hello world.";
	sPtr = new char[strlen(s) + 1]; //多一位'\0'
	std::cout << sPtr[strlen(s)] << std::endl; //空一行
	strcpy(sPtr, s);
	std::cout << sPtr << std::endl; //hello world.
	strncpy(sPtr, s, strlen(s));
	std::cout << sPtr << std::endl; //hello world.
	delete sPtr;
	system("pause");
	return 0;
}