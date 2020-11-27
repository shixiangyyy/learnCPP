#include <iostream>
using namespace std;

//相同的内存地址
union myUni
{
	struct {int i; int j; int k;}stu;
	int m;
}MU;

int main()
{
	MU.stu.i = 5;
	MU.stu.j = 5;
	MU.stu.k = 10;
	MU.m = 0; //由于union里面共享内存空间，因此m将覆盖stu的第一个元素的内容
	printf("%d %d %d %d\n", MU.stu.i, MU.stu.j, MU.stu.k, MU.m);
	
	system("pause");
	return 0;
}