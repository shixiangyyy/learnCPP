#include <iostream>
using namespace std;

//本段代码抛出异常后，没有被捕获，因此程序中止于throw以后
int main()
{
	cout << "1--before try block..." << endl;
	try
	{
		cout << "2---Inside try block..." << endl;
		throw(10); //中止
		cout << "3---After throw..." << endl; //捕获之后本行不执行
	}
	catch (double d)
	{
		cout << "4---In catch block...exception..errorcode is: " << d << endl;
	}
	cout << "5---After catch...\n";

	system("pause");
	return 0;
}