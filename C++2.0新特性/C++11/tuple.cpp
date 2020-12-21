#include <iostream>
#include <tuple>
using namespace std;

int main()
{
	tuple<int, int, string> t, t1, t2;
	t = make_tuple(0, 0, "0");
	t1 = make_tuple(1, 1, "1");
	t2 = make_tuple(2, 2, "2");

	int a = get<0>(t);
	get<0>(t) = get<1>(t);//可以直接赋值，说明get返回的是引用
	cout << a << endl;
	cout << (get<0>(t) > get<1>(t) ? "true" : "false") << endl;

	typedef tuple<int, int, int, string> T;
	//mata programming处理类型，对数据的type进行编程
	cout << tuple_size<T>::value << endl;
	tuple_element<1, T>::type a1 = 10;
	cout << a1 << endl;

	system("pause");
	return 0;
}