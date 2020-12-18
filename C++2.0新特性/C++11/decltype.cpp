#include <iostream>
#include <map>
#include <set>
using namespace std;

//decltype用法一，推断返回类型
template <typename T1, typename T2>
auto add(T1 t1, T2 t2)->decltype(t1 + t2)
{
	return t1 + t2;
}

class Person
{
public:
	string firstname;
	string lastname;
};

int main()
{
	cout << add('a', 'b') << endl;

	//用法二，模板元编程
	//例如在一个模板函数或者模板类获取容器的value_type
	map<string, float> coll;
	decltype(coll)::value_type m{ "石翔", 1.0 };
	cout << m.first << m.second << endl;

	//用法三，用于返回lambda的类型(不好描述)
	auto cmp = [](const Person& p1, const Person& p2)
	{
		return p1.firstname > p2.lastname;
	};

	//告诉set，比较大小的方式是cmp的方式
	//一个Person的set，其比较大小用于RB树排序的是cmp类型的方法
	set<Person, decltype(cmp)> col(cmp);

}