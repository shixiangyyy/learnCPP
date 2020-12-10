#include <iostream>
using namespace std;

int main()
{
	char a, b, c, d;
	cin.get(a);
	cin.get(b);
	c = cin.get();
	d = cin.get();
	cout << int(a) << " " << int(b) << " " << int(c) << " " << int(d) << endl;
	//"abcd"时，输出97 98 99 100
	//a回车b回车 时，这时候已经读入4个char，输出97 10 98 10

	//原因:与直接cin>>不同，cin.get()在缓冲区遇到包括空格(ENTER),[space],[tab]等不会舍弃不读
	//而是读入其ASCII码存入变量中

	system("pause");
	return 0;
}