#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

//(3)重载一个终止函数
template <typename T>
void _hash(size_t& seed, const T& val)
{
	cout << "hash over " << val << endl;
}

//(2)展开函数，把参数氛围一个普通参数和一个参数包，每调用一次，参数包大小减一
template <typename T, typename...Args>
void _hash(size_t& seed, const T& val, const Args&...args)
{
	cout << "Parameter " << val << endl;
	//递归调用自己
	_hash(seed, args...);
}

//(1)泛化版
template <typename...Args>
size_t _hash(const Args&...args)
{
	cout << "hash start " << endl;
	size_t seed = 10;
	_hash(seed, args...);
	return seed;
}

//任意参数个数的类模板
template<typename...Args>
class A
{
private:
	int size = 10;
public:
	A()
	{
		size = sizeof...(Args);
		cout << size << endl;
	}
};

int main()
{
	size_t f = 10;
	_hash("adidas", 2, 3, 4);
	A<int, string, vector<int>> a;

	//tuple就是利用变长参数模板的特性实现
	tuple<int, string> t = make_tuple(1, "nike");
	int firstArg = get<0>(t);
	string secondArg = get<1>(t);
	cout << firstArg << " " << secondArg << endl;
	system("pause");
	return 0;
}