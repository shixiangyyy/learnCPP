#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char s[20] = "this is a string.";
	double digit = -36.96656;
	cout << setw(30) << setfill('*') << s << endl;
	cout << dec << setprecision(5) << digit << endl;
	cout << dec << 15 << endl;
	//ʹ��setbase(int x)�������ý��ƣ��������еĲ������ǰ���������Ƽ���
	cout << setbase(8) << 15 << endl;
	float x = 0.6937;
	cout << float(int(x * 1000 + 0.5) / 1000.0) << endl;

	system("pause");
	return 0;
}