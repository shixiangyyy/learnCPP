#include <iostream>
#include <vector>
using namespace std;

//Three lof decltype to infer the type
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
    decltype(arr)r1;
    decltype(ptr) var2;
    decltype(s.d) var3;
    //decltype(overloaded(1)) var4;//error,overload function is not allowed

    //law2
    decltype(fun_1(1)) var5 = true;
    decltype(fun_2(1)) var6 = true;

    //law3
    //left value:
    decltype(++i) var7 = i;
    decltype(true?i:i) var8 = i;
    decltype((i)) var9 = i;
    decltype(arr[5]) var10 = i;
    decltype(*ptr) var11 = i;
    decltype("Hello") var12 = "hello";
    //right value:
    decltype(i++) var13 = i;
    decltype(1) var14 = 10;

    cout  << "Free" << endl;
    system("pause");
    return 0;
}


