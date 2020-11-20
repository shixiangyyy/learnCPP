#include <iostream>
#include <vector>
using namespace std;

//Three lof decltype to infer the type
//law1:
//���e��һ���������ŵı�Ƿ����ʽ�������Ա���ʱ��ʽ����decltype����e�������ʵ�������
//���û�и����ͻ���e��һ�������صĺ��������±������
//law2 :
//���e��һ���������û���һ�����ز��������ã��򷵻غ����ķ�������
//law3 :
//���e������������������������e��������T�����e��һ����ֵ���򷵻�T&�����e��һ����ֵ���򷵻�T
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
    //left value:����ĳλ�õ�����
    decltype(++i) var7 = i; //int&
    decltype(true?i:i) var8 = i; //int&
    decltype((i)) var9 = i; //int&
    decltype(arr[5]) var10 = i; //int&
    decltype(*ptr) var11 = i; //int&
    decltype("Hello") var12 = "hello"; //const char[6]&
    //right value: ���Կ���һ����ʱֵ�����ܱ������������ַ���
	//��ֵ������&&��ʾ����int && rRef = square(5)
    decltype(i++) var13 = i; //int
    decltype(1) var14 = 10; //int

    system("pause");
    return 0;
}


