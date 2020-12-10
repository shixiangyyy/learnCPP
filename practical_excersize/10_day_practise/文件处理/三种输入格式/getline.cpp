#include <iostream>
using namespace std;

//cin.getline(arrayname, size)与cin.get(arrayname, size)的区别
//get遇到[enter]时会结束输入，但是不会删除缓冲区中的[enter];
//getline遇到[enter]时也会结束当前输入，但是会删除缓冲区中的[enter]
//类似地：
//cin.getline(arrayname, size, s)与cin.get(arrayname, size, s)的区别
//getline遇到s时会结束输入，也会清除缓冲中的s，不让下一个cin读取
//get遇到s时也会结束输入，但是不会清楚缓冲中的s，可以被下一个cin读取到
int main()
{
	/*asfasfsss
	asfasfsss
	10*/
	//char a[10];
	//char b;
	//cin.get(a, 10); //遇到[enter]停止，但是不清楚缓冲区[enter]
	//cin.get(b); //可能读空格
	//cout << a << endl << int(b);

	/*输入：
	12345
	a
	输出：
	12345
	97*/
	//char a[10];
	//char b;
	//cin.getline(a, 10); //遇到空格停，但是清楚缓冲中[enter]
	//cin.get(b); //不会读到空格
	//cout << a << endl << int(b);

	/*输入：
	asfjldsff
	输出:
	a
	f*/
	//char a[10];
	//char b;
	//cin.getline(a, 10, 's'); //遇到s结束对a的输入，输入的数据剔除s，但是剩余的保留
	//cin.get(b);
	//cout << a << endl << b;

	/*输入:
	asffsdf
	输出：
	a
	s*/
	char a[10];
	char b;
	cin.get(a, 10, 's'); //遇到s结束对a的输入，输入的s不会被剔除，但是剩余的保留
	cin.get(b);
	cout << a << endl << b;

	system("pause");
}