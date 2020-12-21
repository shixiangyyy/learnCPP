#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

//\include\c++\bits\stl_iterator.h
//#if __cplusplus >= 201103L
//inline auto
//operator-(const reverse_iterator<_IteratorL>& __x,
//	const reverse_iterator<_IteratorR>& __y)->decltype(__y.base()-__x.base())
//#else
//inline typename reverse_iterator<_IteratorL>::difference_type
//operator-(const reverse_iterator<_IteratorL>& __x,
//	const reverse_iterator<_IteratorR>& __y)
//#endif
//{ return __y.base() - __x.base(); }


class C
{
private:
	string str;
public:
	//explicit修饰的构造函数，可以防止隐式转换和复制初始化
	explicit C(const string& s) :str(s) {};
	
	friend ostream& operator<<(ostream& os, const C& c)
	{
		cout << c.str << endl;
	}
};

int main()
{
	auto i = 42; //编译器实参推导

	auto ll1 = [](int x) {return x + 10; }; //自动判定lambda表达式类型

	function<int(int x)> ll = [](int x) {return x + 10; }; //lambda匿名functor

	cout << ll1(10) << endl;

	list<int> lst{ 1,2,3 };
	list<int>::iterator iter = find(lst.begin(), lst.end(), 2);
	auto iterAT = find(lst.begin(), lst.end(), 2); //少写几个字

	vector<int> vec{ 22,234,23,2343,45234,524,5324 };
	//==================range based for statement============================
	//pass by value(1)
	for (auto elem : vec) cout << elem << " ";
	cout << endl;
	//C++2.0之前，编译器会把(1)转为(2)或者(3)
	for (auto _pos = vec.begin(); _pos != vec.end(); _pos++) cout << *_pos << " ";
	cout << endl;
	//(3)，C++2.0之后，全局函数begin和end可以接受容器作为参数
	for (auto _pos = begin(vec); _pos != end(vec); _pos++)cout << *_pos << " ";
	cout << endl;
	//(4) pass by reference
	for (auto &elem : vec) cout << elem << " ";
	cout << endl;
	//编译器会将(4)转为(5)
	for (auto _pos = vec.begin(); _pos != vec.end(); _pos++)
	{
		auto& elem = *_pos;
		cout << elem << " ";
	}cout << endl;

	vector<string> vs{ "Hello", "world of auto!" };
	//C类中加了explicit就不能进行隐式类型转换了，所以下述代码不能通过编译
	/*for (const C& elem:vs){...} 因为vs不能被隐式转换为C类型*/
	
	//auto缺点：降低代码的可读性，可能得不到想要的预期，配合decltype会有意想不到的效果
	//auto可能得不到预想的类型，比如vector<bool>[]的返回类型
	vector<bool> v(true);
	auto var = v[0];
	cout << typeid(var).name() << endl; //St14_Bit_reference

	system("pause");
	return 0;
}