#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
T compareMax(T t1, T t2) 
{
	return t1 > t2 ? t1 : t2;
}

//函数模板的特化
template<>
char* compareMax(char* s1, char* s2)
{
	return strcmp(s1, s2) > 0 ? s1 : s2;
}

int main()
{
	cout << compareMax(1, 2) << endl; //函数模板的隐式实例化
	cout << compareMax<int>(1, 's') << endl; //函数模板的显式实例化
	cout << compareMax("asds", "adjf") << endl;
	system("pause");
	return 0;
}