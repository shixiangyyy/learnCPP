#include <iostream>
#include <vector>
using namespace std;

//Three lof decltype to infer the type
//law1:
//如果e是一个不带括号的标记符表达式或者类成员访问表达式，则decltype返回e所代表的实体的类型
//如果没有该类型或者e是一个被重载的函数，则导致编译错误
//law2 :
//如果e是一个函数调用或者一个重载操作符调用，则返回函数的返回类型
//law3 :
//如果e不属于以上两种情况，则假设e的类型是T。如果e是一个左值，则返回T&；如果e是一个右值，则返回T
void overloaded(int){};
void overloaded(char, char){};
const bool fun_1(int){return true;}
const bool& fun_2(int)
{
    const bool& flag = true;
    return flag;
}

int main()
{
    int i = 4;
    const int j = 5;
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;
    struct{ double d; }s;

    //law1
    decltype(arr) var1; //int[5]
    decltype(ptr) var2; //int*
    decltype(s.d) var3; //double
    //decltype(overloaded(1)) var4;//error,overload function is not allowed

    //law2
    decltype(fun_1(1)) var5 = true; //bool
    decltype(fun_2(1)) var6 = true; //const bool&

    //law3
	//http://c.biancheng.net/view/1510.html
    //left value:访问某位置的名称
    decltype(++i) var7 = i; //int&
    decltype(true?i:i) var8 = i; //int&
    decltype((i)) var9 = i; //int&
    decltype(arr[5]) var10 = i; //int&
    decltype(*ptr) var11 = i; //int&
    decltype("Hello") var12 = "hello"; //const char[6]&
    //right value: 可以看作一个临时值，不能被程序其他部分访问
	//右值引用用&&表示，如int && rRef = square(5)
    decltype(i++) var13 = i; //int
    decltype(1) var14 = 10; //int

    system("pause");
    return 0;
}


