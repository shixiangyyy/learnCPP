#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

//#字符串操作符使用
//在宏中，在参数前面使用#,预处理器会把该参数转为一个字符数组，“字符串化“
#define exp(s) printf("test s is:%s\n", s) //直接替换
#define exp1(s) printf("test s is:%s\n", #s) //将或许为变量名的s字符串化
#define exp2(s) #s

//##符号连接操作符，符号链接后的参数名必须在作用域中存在
#define expA(s) printf("前缀加上后的字符串为：%s\n", gc_##s)
#define expB(s) printf("前缀加上后的字符串为：%s\n", gc_ ## s)
#define gc_hello1 "I am gc_hello1"

//\续航操作符
#define MAX(a, b) ((a) > (b)?(a)\
	:(b))

int main()
{
	//#
	exp("hello");
	exp1(hello);//使用#将hello字符串化
	string str = exp2(bac);
	cout << str << " " << str.size() << endl;
	//空格忽略
	string str1 = exp2(bac   asda);
	cout << str1 << " " << str1.size() << endl;

	//##符号链接操作符
	const char* gc_hello = "I am gc_hello";
	expA(hello);
	expB(hello1);

	char var1_p[20];
	char var2_p[20];
	strcpy(var1_p, "aaaa");
	strcpy(var2_p, "bbbb");

	//\续航操作符
	int max_val = MAX(3, 6);
	cout << max_val << endl;

	system("pause");
	return 0;
}