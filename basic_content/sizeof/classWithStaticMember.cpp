#include <iostream>
using namespace std;

//��ľ�̬���ݴ���������������ȫ�����global data member��
//�������һ�����ݳ�Ա�����ǲ���Ӱ����Ĵ�С
//�������������˶��ٸ�ʵ�������������˶����µ��࣬��̬���ݳ�Աֻ��һ��ʵ��
//��̬���ݳ�Ա��һ�����������Ѿ�����
//�����ֽڶ���ԭ��

class A
{
public:
	char b;
	virtual void fun() {};
	static int c;
	static int d;
	static int e;
};

int A::c = 1;
int A::d = 2;
int A::e = 3;

int main()
{
	cout << "This is a 64bit computer." << endl;
	A* a = new A();
	A f;
	a->b = 'a';
	cout << "A class size: " << sizeof(A) << endl; //16 &X64ƽ̨��X86ƽ̨Ϊ8�������ֽڶ��룬����64λ8+8
	cout << "A object pointer a size: " << sizeof(a) << endl; //8 &X64ƽ̨��X86ƽ̨Ϊ4
	cout << "A object f size: " << sizeof(f) << endl;

	delete a;
	cout << A::c << " " << A::d << " " << A::e << endl;

	system("pause");//to check the existence of a
	return 0;
}