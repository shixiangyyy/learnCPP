#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

//#�ַ���������ʹ��
//�ں��У��ڲ���ǰ��ʹ��#,Ԥ��������Ѹò���תΪһ���ַ����飬���ַ�������
#define exp(s) printf("test s is:%s\n", s) //ֱ���滻
#define exp1(s) printf("test s is:%s\n", #s) //������Ϊ��������s�ַ�����
#define exp2(s) #s

//##�������Ӳ��������������Ӻ�Ĳ������������������д���
#define expA(s) printf("ǰ׺���Ϻ���ַ���Ϊ��%s\n", gc_##s)
#define expB(s) printf("ǰ׺���Ϻ���ַ���Ϊ��%s\n", gc_ ## s)
#define gc_hello1 "I am gc_hello1"

//\����������
#define MAX(a, b) ((a) > (b)?(a)\
	:(b))

int main()
{
	//#
	exp("hello");
	exp1(hello);//ʹ��#��hello�ַ�����
	string str = exp2(bac);
	cout << str << " " << str.size() << endl;
	//�ո����
	string str1 = exp2(bac   asda);
	cout << str1 << " " << str1.size() << endl;

	//##�������Ӳ�����
	const char* gc_hello = "I am gc_hello";
	expA(hello);
	expB(hello1);

	char var1_p[20];
	char var2_p[20];
	strcpy(var1_p, "aaaa");
	strcpy(var2_p, "bbbb");

	//\����������
	int max_val = MAX(3, 6);
	cout << max_val << endl;

	system("pause");
	return 0;
}