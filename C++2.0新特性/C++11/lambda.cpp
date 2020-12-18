//C++11引入lambda，允许inline functionality的定义，并且可以是一个参数或者一个局部对象
//lambda改变了C++标准库的使用方式

//原来的函数对象或者仿函数，现在可以通过lambda实现，比如之前的cmp函数等

////看上去是一个函数，实则是一个对象，单独这样写是没有意义的
//[] {std::cout << "hello world!" << std::endl; }

//上述对象可以通过如下方式直接调用
//[] {std::cout << "hello lambda" << std::endl; }() //prints "hello lambda"
//typename后面接小括号表示直接调用lambda表示式子了

//or pass it to objects to get called
//传递给对象进行调用
//auto l = [] {
//	std::cout << "hello lambda" << std::endl;
//};
//l();

//可以理解为一个函数对象(functionality)

//lambda is a definition of functionality, that can be defined inside
//statements and expressions.
//Thus, you can use a lambda as an inline function.

//完整形式
//[...](...)mutable_opt throwSpec_opt ->retType_opt {...}
//mutable表征()中参数是否可以被改写
//throwSpec指定是否抛出异常
//[]中放capture，指定在lambda内部获取外部非静态对象nonstatic outside objects
//you can specify a capture to access data of outer scope that is not passed 
//as an argument

//[=]表示外部变量以value的形式传递给lambda
//[&]表示外部变量以reference形式传递给lambda
//[=, &y]表示传递y以引用传递，但是所有其他的对象都是按值传递

//mutable：对象通过传值的方式，但是lambda定义的内部函数对象中，具有对传递对象的写入权限

//*************************************************************
//*************************************************************
//The type of a lambda is an anonymous function object or functor that is unique for each
//lambda expression. Thus to declare objects of that type, you need templates or auto. If 
//you need the type, you can use decltype(), which is, for example, required to pass a lambda
//as hash function or ordering or sorting criterion to associative or unordered containers.

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Person
{
public:
	string firstName, lastName;
};

class UnNamedLocalFunction
{
	int localVal;
public:
	UnNamedLocalFunction(int val) :localVal(val) {};
	bool operator()(int val) { return val == localVal; }
};

class lambdaFunctor
{
	int _a, _b;
public:
	lambdaFunctor(int a, int b) :_a(a), _b(b) {};
	bool operator()(int n) const { return _a<n&&_b>n; };
};

class X
{
	int _x, _y;
public:
	X(int x, int y) :_x(x), _y(y) {};
	int operator()(int a) { return a; }
	int sum()
	{
		return [&]()->int {
			return operator()(_x + _y);
		}();
	}
	int ff()
	{
		return [this]() {
			return this->_x;
		}();
	}
};

int main()
{
	[] {cout << "Hello lambda!" << endl; }();

	auto I = [] {cout << "Hello lambda!" << endl; };
	I();
	//按值传递
	int id = 0;
	auto f = [id]()mutable {
		cout << "id = " << id++ << endl;
	};
	id = 42;
	f(); f(); f();
	cout << id << endl;
	//按引用传递
	int id1 = 0;
	auto f1 = [&id1] {
		cout << "id1 = " << id1++ << endl;
	};
	id1 = 42;
	f1(); f1(); f1();
	cout << id1 << endl;
	//传参与返回
	int id2 = 0;
	auto f2 = [&id2](int& param) {
		cout << "id2 = " << id2++ << endl;
		++param;
		cout << "param = " << param << endl;
		static int x = 5;
		return id2;
	};
	int param = 1;
	f2(param);
	cout << "param = " << param << endl;
	//[=]:默认以value传递所有外部变量
	//[&}:默认以reference传递所有外部变量
	auto f3 = [&]() {
		cout << "id = " << id << endl;
		cout << "id1 = " << id1 << endl;
		cout << "id2 = " << id2 << endl;
		cout << "param = " << param << endl;
	};
	f3();

	//this指针
	X _x(1, 2);
	cout << "_x.sum() = " << _x.sum() << endl;
	cout << "_x.ff() = " << _x.ff() << endl;

	//下面的lambda函数等价于上述的UnNamedLocalFunction
	int tobefound = 5;
	auto lambda1 = [tobefound](int val) {
		return val == tobefound;
	};
	UnNamedLocalFunction lambda2(tobefound);
	cout << lambda1(5) << " " << lambda2(5) << endl;

	auto ll1 = [](int x)->int { return x + 10; };
	//lambda匿名函数
	function<int(int x)> l1 = [](int x)->float { return x + 10.0; };
	cout << l1(10.1) << endl; //注意，这里输出的int类型，因为被隐式转换为function<int(int x)>类型

	//decltype+lambda
	function<bool(const Person&p1, const Person&p2)> cmp = [](const Person&p1, const Person&p2) {
		return p1.lastName < p2.lastName;
	};

	//将lambda functor作为set容器的sorting criterion，传入set模板，并在对象实例化时作为cmp参数
	set<Person, decltype(cmp)> coll(cmp); //set有一个构造函数是以这种cmp准则为参数，因此传入lambda对象cmp

	// 函数对象是很强大的，封装代码和数据来自定义标准库的行为，但需要写出函数对象需要写出整个class，这是不方便的，
	//而且是非本地的，用起来也麻烦，需要去看怎样使用，另外编译出错的信息也不友好，而且它们不是inline的，效率会低一些
	//（算法效率还是最重要的）。

	vector<int> vec{ 5,23,4,234,234,22,2,2,5,6 };
	int x = 4, y = 22;
	vec.erase(remove_if(vec.begin(), vec.end(), [x, y](int n) {return x < n&&n < y; }), vec.end());
	for_each(vec.begin(), vec.end(), [](int i) {cout << i << " "; });
	cout << endl;

	system("pause");
	return 0;
}