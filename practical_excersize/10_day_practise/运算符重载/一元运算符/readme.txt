重载一元运算符
1、一元运算符只需要一个运算参数，如&，？，++
2、一元运算符常见调用形式:
	@a  a@ //隐式调用形式，前缀运算和后缀运算
	a.operator@() //显式调用一元运算符@,其中a代表操作数
	operator@(a)
3、@a将被解释为下面的形式之一
	a.operator@()
	operator@(a)
4、一元运算符作为类成员函数重载时不需要参数
	class x{
		...
		T operator@(){...};
	}
5、前自增/减 与 后自增/减
	C++编译器可以通过在运算符函数参数表中插入关键字int来区分前后两种方式
	//前缀
	operator@();
	operator@(X& x);
	//后缀
	operator@(int);
	operator@(X& x, int);
	