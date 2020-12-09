#include <iostream>
using namespace std;

int main()
{
	cout << "1--before try block..." << endl;
	try
	{
		cout << "2---Inside try block..." << endl;
		throw(10);
		cout << "3---After throw..." << endl; //捕获之后本行不执行
	}
	catch (int i)
	{
		cout << "4---In catch block...exception..errorcode is: " << i << endl;
	}
	catch (char* s)
	{
		cout << "5---In catch block 2...exception errorcode is: " << s << endl;
	}
	cout << "6---After catch...\n";

	system("pause");
	return 0;
}