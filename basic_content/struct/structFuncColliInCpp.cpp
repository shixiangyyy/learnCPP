#include <iostream>
using namespace std;

struct Student
{

};


//当使用typedef定义结构体别名是，CPP也不允许结构体别名和函数重名
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
//void Student2(){} //error,Student2已经被定义为struct Base1的别名

int main()
{
	//Student s; //ERROR
	struct Student s; //OK,因此若CPP中存在结构体和函数重名，使用结构体时要加struct

}