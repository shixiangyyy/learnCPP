#include <iostream>
using namespace std;

//不可以直接修改常量指针指向的值，但是可以通过第三者指针修改其指向的值
int main()
{
	const int* ptr;
	//*ptr = 3;//error,表达式必须是可修改左值
	int val = 3;
	ptr = &val;
	//*ptr = 100;//error,表达式必须是可修改左值
	int* ptr1 = const_cast<int*>(ptr);//通过ptr1接受去重
	*ptr1 = 100;
	cout << *ptr << endl;
	int* ptr2 = &val;
	*ptr2 = 200;//ok
	cout << *ptr << endl; //100
	cout << *ptr1 << endl;
	system("pause");
	return 0;
}