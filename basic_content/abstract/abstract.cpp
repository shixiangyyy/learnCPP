#include <iostream>
using namespace std;

//抽象类
//纯虚函数：没有函数体的虚函数
//抽象类指包含纯虚函数的类
//抽象类不能作为函数返回类型，也不能作为函数参数，但是引用类型可以
//纯虚函数为各派生类提供一个公共界面
class A 
{
private:
	int a;
public:
	virtual void show() = 0;//纯虚函数
	void g() { this->show(); }
	A() {} //抽象类A的构造函数
};

void A::show() {
	cout << "Pure virtual function can also be implemented!" << endl;
}

class B :public A
{
public:
	//派生类中如果不覆盖纯虚函数，那么派生类也将继续作为抽象类
	void show()
	{
		cout << "B:show()" << endl;
	}
};

int main() 
{
	/*抽象类不能进行实例化
	抽象类的指针和引用指向由抽象类派生出来的类的对象
	因此，可以定义抽象类的指针，但是不可以对抽象类进行实例化*/
	//abs a;//错误，抽象类不能创建对象
	//abs* a1;//正确，可以定义抽象类的指针
	//abs *a2 = new abs();//错误，抽象类不能创建对象
	A* p = new B;
	p->show(); //“B:show()”
	B b; //由抽象类派生出来的类实例化的对象
	b.show();
	return 0;
}