#include <iostream>
using namespace std;

class X
{
public:
	int operator()(int i)
	{
		cout << "X::operator(" << i << ")" << endl;
		return i;
	}
	int operator()(int i, int j)
	{
		cout << "X::operator(" << i << "," << j << ")" << endl;
		return i;
	}
	int operator[](int i)
	{
		cout << "X::operator[" << i << "]" << endl;
		return i;
	}
	int operator[](const char* cp)
	{
		cout << "X::operator[" << cp << "]" << endl;
		return 0;
	}
};

int main()
{
	X obj;
	int i = obj(1);
	int j = obj(obj(5), 6);
	int b = obj[i];
	int c = obj["Ê¯Ïè"];
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");
	return 0;
}