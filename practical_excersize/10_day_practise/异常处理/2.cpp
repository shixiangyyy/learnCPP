#include <iostream>
using namespace std;

//���δ����׳��쳣��û�б�������˳�����ֹ��throw�Ժ�
int main()
{
	cout << "1--before try block..." << endl;
	try
	{
		cout << "2---Inside try block..." << endl;
		throw(10); //��ֹ
		cout << "3---After throw..." << endl; //����֮���в�ִ��
	}
	catch (double d)
	{
		cout << "4---In catch block...exception..errorcode is: " << d << endl;
	}
	cout << "5---After catch...\n";

	system("pause");
	return 0;
}