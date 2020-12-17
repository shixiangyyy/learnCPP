#include <iostream>
using namespace std;

void f(int i)
{
	cout << "void f(int) called." << endl;
}

void f(void* p)
{
	cout << "void f(void*) called." << endl;
}

int main()
{
	f(0);

//#ifndef  __cplusplus
//#define NULL ((void*)0)
//#else
//#define NULL 0
//#endif // ! __cplusplus

	//C语言中将NULL定义为空指针，而C++中将NULL定义为0
	//这是因为C++是强类型地，void*是不能隐式转换为其他指针类型的

	if (NULL == 0) cout << "NULL==0" << endl;
	//f(NULL); //ambiguous，不知道调用哪一个
	////因为c++中将NULL定义为0，而不是C语言中的空指针，因此调用歧异
	f(nullptr);
	nullptr_t n1;
	f(n1);

	system("pause");
	return 0;
}