#include <iostream>
using namespace std;

class Apple
{
public:
	int i;
	Apple()
	{
		i = 0; 
		cout << "Inside Constructor!" << endl;
	}
	virtual ~Apple()
	{
		cout << "Inside Destructor!" << endl;
	}
};

int main()
{
	if (true)
	{
		//不加static时，作用域内构造、析构。
		//Inside Constructor->Inside Destructor->End of main
		//Apple obj;
		//加static时，作用域贯穿程序的生命周期
		//Inside Constructor->End of main->Inside Destructor
		//实际运行时，没有Inside Destructor.直接main结束终止
		static Apple obj;
	}
	cout << "End of main." << endl;
	system("pause");
	return 0;
}
