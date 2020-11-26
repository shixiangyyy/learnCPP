//静态函数不可以声明为虚函数，也不可以被const和volatile关键字修饰
//类的static函数不属于任何对象或者类实例，因此加上virtual也是没有意义的
//虚函数依赖vptr和vtable进行处理，vptr是一个指针，在类的构造函数中生成，只能使用this指针
//进行访问。而静态成员函数没有this指针，因此无法访问vptr
virtual static void fun(){}
static void fun() const{}