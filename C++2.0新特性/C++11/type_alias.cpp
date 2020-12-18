//template template parameter，模板模板参数
//就是一个模板的参数本身也是一个模板
//在此情况下，可以使用该模板模板参数的type alias，获取类型
//这是别名alias的一种艰深应用
//type alias,类型化名，类似于typedef

//There is no difference between a type alias declaration and typedef declaration.
//This declaration may appear in block scope, class scope, or namespace scope

//using关键字的三个用途
//using-directives for namespaces and using-declaration for namespace members
	//using namespace std; using std::vector;
//using-declaration for class members
	//using _Base::M_allocate;
	//using _Base::M_deallocate;
//type alias and alias template declaration(since C++11)

#include <iostream>
#include <vector>
using namespace std;

//using第一种使用
//相当于typedef
using func = void(*)(int, int);
//相当于typedef void (fun*)(int, int) func

void example(int, int ){}

//using第二种使用
//用于type alias,声明模板别名
template <typename T>
struct Container
{
	using value_type = T;
};

//模板模板参数
//该模板的模板参数也是一个模板
//该情况下，通过在作为参数的模板中使用using定义type alias
//可以在该模板下面方便地获取类型名称
template <typename Cn>
void func2(const Cn& cn)
{
	Cn m; //Cn类型的m变量可以定义，但是Cn类型内含的数据类型不可以直接定义
	typename Cn::value_type n;//因而可以获取类型Cn::value_type
	//然后定义一个value_type类型的n
}

template <typename Container, typename T>
void func3(const Container& cn, T elem)
{
	//Container<T> cn; //Error, Container is not a template
	Container n; //OK
}

//template template parameter
template <typename T, template <class> class Cont>
class XCL
{
	Cont<T> c;
};

//第三种使用，alias template
template <typename CharT>
using string = basic_string<CharT, char_traits<CharT>>;

//使用alias template给vector重新命名，使得Vec模板可以被当作
//Container模板类的参数
template <typename T>
using Vec = vector<vector<T>>;

//综上，type alias相当于typedef，没什么不同
int main()
{
	func fn = example;

	Container<int> cn;
	//使用type alias的目的，不是单纯地为了少写几句代码
	//而是比如在该情况下，为了达到要求的简洁的调用形式
	func2(cn);

	//XCL<int, vector> cl; //Error,type/value mismatch(原因是XCL模板第二个
	//参数模板只有一个模板参数，但是vector类型实际上有两个参数)
	XCL<int, Container> xcl; //OK
	XCL<int, Vec> xcl1; //OK

	return 0;
}

