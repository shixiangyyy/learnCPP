#include <iostream>
using namespace std;

struct Base
{
private:
	int v1;//Ĭ��public
	int v2;
public:
	int v3;
	void print()
	{
		cout << "Hello world!" << endl;
	};
};

typedef struct Base1
{
	int v1;
	int v2;
public:
	int v3;
	void print()
	{
		cout << "Hello world in Base1!" << endl;
	};
}B;

//error��B�Ѿ�������ΪBase1�ı���
//void B()
//{
//
//}

void Base()
{
	cout << "Hello world in Base() function!" << endl;
}

int main()
{
	struct Base base;//OK
	//Base base1;//error
	base.v3 = 3;
	base.print();
	cout << base.v3 << endl;

	system("pause");
	return 0;
}