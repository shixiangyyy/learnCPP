空类大小为1

当类不包含虚函数和非静态数据成员时，其对象大小也为1.

如果在类中声明了虚函数，那么在实例化对象时，编译器会自动在对象里安插一个指针指向虚函数表Vtable，在32位系统上会使用4个字节用于存放

对于包含虚函数的类，不管有多少个虚函数，都只有一个虚指针，vptr的大小，64位系统为8个字节

类的大小与普通数据成员有关，与成员函数或者静态成员无关
即：普通成员函数、静态成员函数、静态数据成员、静态常量数据成员都不影响类的大小
虚函数对类大小有关，这是由于虚函数表指针带来的影响
虚继承对类大小有关，这是因为虚基表指针带来的影响
空类的大小是一个特殊情况，空类的大小为1