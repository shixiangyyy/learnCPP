https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/struct

C语言中的结构体：
C语言中，struct只是单纯用作数据的复合类型，只能将数据成员放在结构体声明中，而不能将函数放在里面；
C结构体中不能使用C++访问修饰符，如public、protected、private，在C++中允许使用
C结构体不存在继承的概念
C中定义结构体变量，如果使用了下面定义则必须加struct
C中允许结构体名字与函数名字同名，如struct Base以及不冲突的void Base(){}

C++中的结构体：
与C语言进行对比：
C++结构体不仅可以定义成员变量，还可以定义函数；
可以添加访问修饰符；
C++结构体可以直接使用而不用带struct
C++继承
若结构体的名字与函数名字相同，是可以正常运行且正常调用的，但是定义结构体变量的时候只用用带struct的！
示例见structFuncColliInCpp.cpp
