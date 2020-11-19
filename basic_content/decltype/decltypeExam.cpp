#include <iostream>
#include <vector>
using namespace std;

//泛型编程中结合auto的使用，用于追踪函数的返回值的类型
template<typename T>
auto multiply(T x, T y)->decltype(x * y)
{
	return x * y;
}

int main()
{
	int num[] = { 1,2,3,4 };
	vector<int> vec(num, num + 4);
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
	cout << endl;

	typedef decltype(vec.begin()) vectype;
	for (vectype i = vec.begin(); i != vec.end(); i++)
		cout << *i << " ";
	cout << endl;

	/*匿名结构体*/
	struct
	{
		int i;
		double d;
	}anonymous_s;
	decltype(anonymous_s) as;//定义了一个上面的匿名结构体

	cout << multiply(62558, 62559) << endl;//默认判定两个数为int类型，因而还是会溢出
	system("pause");
	return 0;
}