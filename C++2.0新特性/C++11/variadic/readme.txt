variadic template:
目的:
可以很方便地实现函数递归调用；
可以实现递归继承；
扩充代码的复用可能性：
	普通的模板赋予了模板函数或者模板类对数据类型的通用性，但是没有赋予对参数个数的复用性；
	很多处理都是与处理对象的个数关系不大，比如min/max函数等；
	总结：参数类型任意化延申的参数个数任意化。
	
基本语法：
声明一个带有可变参数个数的模板的语法：
	template <typename ... elementPack> class tuple;
	tuple<int, string> a;
	其中elementPack表示一个模板参数包(parameter pack)。参数包是一个新引入C++的新概念。
	上例中，参数包elementPack就是int，string这个参数的合集。
	
	不仅类型的模板参数可以是参数包，非类型的模板参数也可以是参数包：
	template <typename T, unsigned PrimaryDimension, unsigned ... Dimensions>
	class Array{/*/};
	...
	Array<double, int, int> rotation_matrix;
	
	如何在程序中具体使用打包的任意个数的参数：
		C++11使用unpack和类似函数重载似的“模板特化”来抽取具体参数：
		https://www.cnblogs.com/muxue/archive/2013/04/13/3018608.html
		
例子：
C++11新标准库，有很多库都是直接依赖于variadic template这个语言特性：tuple,bind,function;
典型例子：C++11FQA的例子，“类型安全”的printf:
	printf.cpp