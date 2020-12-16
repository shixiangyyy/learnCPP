//variadic5.cpp的例子为递归调用
//该例子为递归继承
#include <iostream>
#include <string>
using namespace std;

namespace light
{
	//类模板
	template <typename...Values> class tuple;
	//特化模板，没有参数
	template <> class tuple<> {};

	//特化模板，1+N个模板参数
	//该特化模板类继承N个模板参数的tuple模板
	template <typename Head, typename...Tail>
	class tuple<Head, Tail...> :private tuple<Tail...>
	{
	private:
		typedef tuple<Tail...> inherited;
	protected:
		Head m_head;
	public:
		tuple() {};
		//本步初始化以后，变递归调用tuple模板类，直到参数包为0
		tuple(Head h, Tail...tail) :m_head(h), inherited(tail...) {}
		Head head() { return m_head; }
		//将当前类型的对象转为一个inherited类型的对象
		//内部什么机制，为何可以自动识别类别，并且可以识别对应的次序？
		//如果模板参数类型为int,int,int，这里也可以正确确认tail包含的参数
		inherited& tail() { return *this; }
	};
}

int main()
{
	using light::tuple;
	tuple<int, float, string> t(41, 5.6, "phanteks");
	//大小输出不同编译器不同，VS2015输出56，g++输出40
	cout << sizeof(t) << endl;
	cout << t.head() << endl;
	cout << t.tail().head() << endl;
	cout << t.tail().tail().head() << endl;

	system("pause");
	return 0;
}