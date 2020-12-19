#include <iostream>
using namespace std;

//只有一个参数的maximum函数
int maximum(int n) { return n; }

//递归调用
template <typename...Args>
int maximum(int n, const Args&...args)
{
	return std::max(n, maximum(args...));
}

//参数type相同的max函数
//C++11允许构造函数和其他函数把初始化列表当作参数
//可以按照引用传递
//这个没有递归调用，效率更高
int max(initializer_list<int> initializerList)
{
	int res = *initializerList.begin();
	for (auto elem : initializerList)
		res = max(res, elem);
	return res;
}

int main()
{
	cout << max({ 10,8,100,1 }) << endl;
	cout << maximum(57, 2342, 234924, 4234, 2) << endl;
	system("pause");
	return 0;
}