#include <iostream>
#include <string>
using namespace std;

//将具有继承关系的不同类型异常的反馈定义为虚函数的形式
//从而可以通过返回指针或者引用的方式调用对应的子类虚函数
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