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
		temperature(100); //��������쳣���������κ������ò���ִ��
		temperature(0);
		temperature(50);
	}
	catch (const char* s) { cout << s << endl; }

	system("pause");
	return 0;
}