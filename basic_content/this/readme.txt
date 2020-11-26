https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/this

一个对象的this指针并不属于对象的一部分，不影响sizeof(obj)的计算结果。

this指针的作用域在类的内部。当在类的非静态成员函数调用类的非静态成员的时候，编译器会自动将对象本身的地址作为一个
隐含参数传递给函数。换言之，即使没有写上this指针，编译器进行编译的时候也是会默认加上this指针的。this指针作为非静
态成员函数的隐含形参，对各个成员函数的访问均通过this指针进行。

this指针的使用：
1、在类的非静态成员函数中返回对象本身时，return *this;
2、当参数与类的成员变量名相同时，需要带上this指针，this->n = n;

this指针被编译器解析为A* const this,即对象内容可以变，但是指针本身(对象地址)不可以改变。

this指针在成员函数开始执行前进行构造，在成员执行结束之后清除。如果一个成员函数是const函数，则只能访问const类型成员，
因此，const成员函数里面的this被解析为const A* const类型，即指针本身和所指向的对象都不可修改。

需要注意的是，C++中类和结构体之间存在一定的区别。类的默认成员访问是private，结构体是public。类的this指针和结构体的
this指针应该存在差别。

