#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char c[30] = "this is string";
	double d = -123.23234;
	//此处left和right是std命名空间中的对象，而不应该是ios::left
	cout << setw(30) << left << setfill('*') << c << "----L1" << endl;
	cout << setw(30) << right << setfill('-') << c << "----L2" << endl;
	//setfill使用一次之后后面对于iostream都有用，直到下一次setfill
	cout << dec << showbase << showpoint << setw(30) << d << "----L4" << endl;
	cout << setw(30) << showpoint << setprecision(10) << setfill('*') << d << "----L5" << endl;
	cout << setw(30) << setbase(16) << 100 << "----L5" << endl;

	system("pause");
	return 0;
}