//ʹ��C����ʵ��CPP���ƶ�̬��
//ʹ��struct��װ������Ա����ͨ������ָ��ʵ�ָ�������ĺ�����Ա�Ĳ��컯
#include <stdio.h>

typedef void (*pf)();//����һ������ָ��

typedef struct _A
{
	pf a;
}A;//����

typedef struct _B
{
	A b;
}B;//����

void FunA()
{
	printf("%s\n", "Base A::fun()");
}

void FunB()
{
	printf("%s\n", "Derived B::fun()");
}

int main()
{
	A a;
	B b;
	a.a = FunA;
	b.b.a = FunB;

	//����CPP�麯��ʵ�ֵ�ͨ������ָ��������ຯ��
	A *pa = &a;
	pa->a();
	pa = (A*)&b;
	pa->a();
	return 0;
}