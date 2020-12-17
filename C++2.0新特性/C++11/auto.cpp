#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

//\include\c++\bits\stl_iterator.h
#if __cplusplus >= 201103L
inline auto
operator-(const reverse_iterator<_IteratorL>& __x,
	const reverse_iterator<_IteratorR>& __y)->decltype(__y.base()-__x.base())
#else
inline typename reverse_iterator<_IteratorL>::difference_type
operator-(const reverse_iterator<_IteratorL>& __x,
	const reverse_iterator<_IteratorR>& __y)
#endif
{ return __y.base() - __x.base(); }


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

}