//CÓïÑÔ
#include <stdio.h>
#include <stdlib.h>

struct Base
{
	int v1;
	int v2;
	int v3;
};

void Base()
{
	printf("%s\n", "Hello world!");
}

int main()
{
	struct Base base; //²»³åÍ»
	base.v1 = 1;
	printf("%d\n", base.v1);
	Base();
	system("pause");
	return 0;
}