#include <iostream>
using namespace std;

//enum Color{ RED, BLUE };
//
//enum Feeling { EXCITED, BLUE };//重定义

//声明命名空间可以避免枚举命名冲突
namespace Color
{
	enum Type
	{
		RED = 15,
		YELLOW, //默认16
		BLUE //默认17
	};
}

namespace Feeling
{
	enum  Feel
	{
		EXCITED,
		BLUE
	};
}

int main()
{
	Color::Type c = Color::BLUE;//17
	Feeling::Feel f = Feeling::BLUE;
	return 0;
}