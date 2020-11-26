//使用dynamic_cast实现RTTI需要注意的是，被转换对象obj的类型T1必须是多态类型，即必须公有继承自其他类(注意公有继承)，或者T1拥有虚函数
//若T1为非多态类型，使用dynamic_cast会报错

//非多态
class A 
{

};

//多态
class B
{
public:
	virtual ~B() {};
};

//多态类型，公有继承自其他类
class D :public A
{

};

//非多态，私有继承，因此不是多态类型
class E :private A
{

};

//多态，私有继承，但是B中有虚函数
class F :private B
{

};