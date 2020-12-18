#include <iostream>
using namespace std;

//=default用于big-five之外没有意义，编译会报错
//=delete可用于任何函数身上，(=0只能用于纯virtual函数)，=delete和=0没关系

class Foo
{
	int _i;
public:
	//ctor
	Foo(int i) :_i(i) { cout << "with param ctor.\n"; };
	Foo() = default; //和上一个并存，ctor可以多个并存

	//copy ctor,只能有一个
	Foo(const Foo& x) :_i(x._i) {};
	//Foo(const Foo&) = default; //Error，不能存在，因为已经存在从copy ctor
	//Foo(const Foo&) = delete; //Error，不能存在，已经定义了copy ctor，不能再=delete
	//use of deleted function Foo::Foo(const Foo&)

	Foo(Foo&&) = default; //move ctor

	//copy assignment ctor,只能有一个
	Foo& operator=(const Foo& x) = default;
	//Foo& operator=(const Foo& x) = default; //Error
	//Foo& operator=(const Foo& x) = delete; //Error
	//use of deleted function Foo& Foo::operator=(const Foo&)
	Foo& operator=(const Foo&& x) = delete;

	//void fun1() = default;//Error,普通函数不允许default
	void fun1() = delete;//Ok,普通函数可以delete,但是没啥意义

	~Foo() = default;
	//~Foo() = delete; // Error，这会造成使用Foo object时出错
	//use of deleted  function Foo::~Foo()
}; 

class Empty{};
//等价于 编译器给出的的默认版本函数都是public且inline的
class Empty1
{
public:
	Empty1() {};
	Empty1(const Empty1& rhs) {};
	~Empty1() {};
};

struct NoCopy
{
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;//不让拷贝
	NoCopy& operator=(const NoCopy&) = delete;//不让拷贝
	~NoCopy() = default;
};

struct NoDtor
{
	NoDtor() = default;
	~NoDtor() = delete;//不让析构
};

//对NoCopy进行改进，将copy ctor与copy assignment放进private
//因此外部对象不能进行拷贝赋值，但是可以通过friend与members调用
//boost::noncopyable就用到了privatecopy
class PrivateCopy
{
private:
	PrivateCopy(const PrivateCopy&) {};
	PrivateCopy& operator=(const PrivateCopy&) {};
public:
	PrivateCopy() = default;
	~PrivateCopy() = default;
};

class Zoo :public PrivateCopy {};

int main()
{
	Foo f;
	Foo f1(1);
	f = f1;

	Zoo zoo;
	Zoo zoo1;
	//zoo = zoo1;//继承了都拥有privateCopy的性质，外部对象不能进行拷贝赋值
	//但是friend和members可以

	//NoDtor nd; //error. NoDtor dtor is deleted
	//NoDtor* p = new NoDtor(); //Ok, but we can't delete p
	//delete p; //Error, NoDtor dtor is deleted

	system("pause");
	return 0;

}