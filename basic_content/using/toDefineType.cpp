#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> V1;
using V2 = vector<int>;

int main()
{
	int num1[] = { 1,2,3,4,5 };
	V1 v1(num1, num1 + sizeof(num1) / sizeof(int));
	int num2[] = { 6,7,8,9,10 };
	V2 v2(num2, num2 + sizeof(num2) / sizeof(int));

	cout << "v1:" << endl;
	for (auto i : v1)
		cout << i << " ";
	cout << endl;

	cout << "V2:" << endl;
	for (auto i : v2)
		cout << i << " ";
	cout << endl;
		
	system("pause");
	return 0;
}