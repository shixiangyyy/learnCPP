#include <iostream>
using namespace std;

namespace Color
{
	enum Type
	{
		RED = 15,
		YELLOW,
		BLUE
	};
}

struct Color1
{
	enum Type
	{
		RED = 102,
		YELLOW,
		BLUE
	};
};

//c++11枚举类
//枚举类中enum作用域不再是全局的
//并且不能够隐式转化为其他类型
//等同于：enum class Color2:int
enum class Color2
{
	RED = 1002,
	YELLOW,
	BLUE
};

enum class Color3:char//可以指定用特定的类型来存储enum
{
	RED = 'r',
	BLUE //'s'
};

//通过枚举常量建立在整个类中都恒定的常量
//注意使用const成员并不能保证整个类都恒定
//枚举常量的缺点是，隐含数据类型是整数，最大值有限，并且不能表示浮点数
class Person
{
public:
	typedef enum {
		BOY = 0,
		GIRL
	}Sextype;
};

int main()
{
	Color::Type c = Color::RED;
	cout << c << endl;

	Color1 c1;
	cout << c1.RED << endl;

	Color2 c2 = Color2::RED;
	//Error,不能直接输出Color2类型的c2,因为C++11枚举类不会隐式转换成其他类型
	//cout << c2 << endl;
	cout << static_cast<int>(c2) << endl;//必须使用static_cast显式转化类型

	char c3 = static_cast<char>(Color3::BLUE);//同上
	cout << c3 << endl;

	system("pause");
	return 0;
}