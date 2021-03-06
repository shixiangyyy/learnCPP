#include <iostream>
#include <string>
#include <tuple>
#include <bitset>
using namespace std;

//tuple递归调用
//知道有几个元素的同时，还要知道当前处理第几个
template <int IDX, int MAX, typename...Args>
struct print_tuple
{
	static void print(ostream& os, const tuple<Args...>& tp)
	{
		os << get<IDX>(tp) << (IDX + 1 == MAX ? "" : ",");
		print_tuple<IDX + 1, MAX, Args...>::print(os, tp);
	}
};

//偏特化，凡是特化的，优先级相对泛化模板优先级就更高些
template <int MAX, typename...Args>
struct print_tuple<MAX, MAX, Args...>
{
	//当IDX+1 = MAX时，调用的是下面这个函数
	static void print(ostream& os, const tuple<Args...>& tp){}
};

template <typename...Args>
ostream& operator << (ostream& os, const tuple<Args...>& tp)
{
	os << "[";
	print_tuple < 0, sizeof...(Args), Args...>::print(os, tp);
	return os << "]";
}

int main()
{
	cout << make_tuple(7.5, string("hello"), bitset<16>(377), 47) << endl;
	system("pause");
	return 0;
}