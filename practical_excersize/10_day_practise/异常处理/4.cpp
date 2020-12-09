#include <iostream>
using namespace std;

void temperature(int t)
{
	if (t == 100) throw("It's at the boiling point.");
	else if (t == 0) throw("It's at the freezing point.");
	else cout << "The temperature is OK." << endl;
}

int main()
{
	try
	{
		temperature(100); //捕获这个异常，后面两次函数调用不再执行
		temperature(0);
		temperature(50);
	}
	catch (const char* s) { cout << s << endl; }

	system("pause");
	return 0;
}