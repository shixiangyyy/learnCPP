#include <iostream>
using namespace std;

struct Student
{

};


//��ʹ��typedef����ṹ������ǣ�CPPҲ������ṹ������ͺ�������
typedef struct Base1
{
private:
	int v1;
	int v3;
public:
	int v2;
	void print() { cout << "Hello world!" << endl; }
}Student2;

void Student(){}
//void Student2(){} //error,Student2�Ѿ�������Ϊstruct Base1�ı���

int main()
{
	//Student s; //ERROR
	struct Student s; //OK,�����CPP�д��ڽṹ��ͺ���������ʹ�ýṹ��ʱҪ��struct

}