派生类通过从基类继承的成员函数调用虚函数时，访问的是派生类中的版本。

内联函数也不能是虚函数，因为内联函数采用的是静态联编的方式，而虚函数
是在程序运行时才与具体函数动态绑定的，采用的是动态联编的方式。

基类虚构函数几乎总是为虚析构函数。假定使用delete删除一个指向派生类的基类
指针，如果基类析构函数不是虚函数的话，那么delete调用的就是基类析构函数。
在通过基类对象的引用或者指针调用派生类对象时，将致使对象析构不彻底。

一旦将某个成员函数声明为虚函数后，它在继承体系中就永远为虚函数了。