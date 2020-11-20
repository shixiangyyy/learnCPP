#include <stdio.h>
#include <stdlib.h>
extern int add(int x, int y);
int main()
{
	printf("%d\n", add(2, 3));
	system("pause");
	return 0;
}