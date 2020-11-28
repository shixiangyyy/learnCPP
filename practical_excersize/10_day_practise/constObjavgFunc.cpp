#include <iostream>
using namespace std;

class R
{
public:
	R(int r1, int r2) :R1(r1), R2(r2) {};
	void print();
	void print() const;//常函数
private:
	int R1, R2;
};

void R::print()
{
	cout << "普通调用" << endl;
	cout << R1 << " " << R2 << endl;
}


//常函数，默认常对象调用
//const是函数类型的一个组成部分，因此再实现部分也要带osnt关键字
//const关键字可以被用于参与对重载函数的区分
//通过常对象只能调用它的常成员函数(调用别的有修改对象成员的危害)
void R::print() const
{
	cout << "常对象函数调用" << endl;
	//R1++; //提示R1是read-only类型，不可以进行修改，因为默认常函数是常对象调用
	//R2++;
	cout << R1 << " " << R2 << endl;
}

int main()
{
	R a(5, 4);
	a.print();

	const R b(8, 9);
	b.print();

	system("pause");
	return 0;
}