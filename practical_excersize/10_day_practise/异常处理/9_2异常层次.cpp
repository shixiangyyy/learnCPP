#include <iostream>
#include <string>
using namespace std;

//�����м̳й�ϵ�Ĳ�ͬ�����쳣�ķ�������Ϊ�麯������ʽ
//�Ӷ�����ͨ������ָ��������õķ�ʽ���ö�Ӧ�������麯��
class BasicException
{
public:
	virtual string where() { return "BasicException.\n"; }
};

class FileSysException : public BasicException
{
	virtual string where() { return "FileSysException.\n"; }
};

class FileNotFount :public FileSysException
{
	virtual string where() { return "FileNotFoundException.\n"; }
};

class DiskNotFoundExceptiopn :public FileSysException
{
	virtual string where() { return "DiskNotFoundException.\n"; }
};

int main()
{
	try
	{
		DiskNotFoundExceptiopn err;
		throw &err;
	}
	catch (BasicException* p) { cout << p->where(); }
	//"DiskNotFoundException."

	system("pause");
}