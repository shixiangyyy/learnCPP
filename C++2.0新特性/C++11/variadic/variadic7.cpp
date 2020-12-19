#include <iostream>
#include <string>
using namespace std;

//µÝ¹é¸´ºÏ
//recursive composition
namespace light
{
	template <typename...Values> class tuple;

	template<> class tuple<>{};

	template <typename Head, typename...Tail>
	class tuple<Head, Tail...>
	{
		typedef tuple<Tail...> composited;
	protected:
		Head m_head;
		composited m_tail;
	public:
		tuple() {};
		tuple(Head h, Tail...tail) :m_head(h), m_tail(tail...) {};

		int getSizeTail() { return sizeof(m_tail); }
		auto head()->decltype(m_head) { return m_head; }
		composited& tail() { return m_tail; }
	};
}

struct A
{
	string a;
	float b;
};

int main()
{
	using light::tuple;
	tuple<int, float, string> t(41, 5.6, "phanteks");
	cout << sizeof(A) << endl;
	cout << sizeof(t) << endl;
	cout << t.getSizeTail() << endl;
	cout << t.head() << endl;
	cout << t.tail().head() << endl;
	cout << t.tail().tail().head() << endl;

	system("pause");
	return 0;
}