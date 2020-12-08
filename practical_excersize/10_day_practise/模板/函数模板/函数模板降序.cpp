#include <iostream>
using namespace std;

template <typename T>
//如果是T& a的话，实例化T = char[10]，表示T是10长数组，请注意
void sort(T* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int p = i;
		for (int j = i; j < n; j++)
			if (a[p] < a[j])
				p = j;
		T temp = a[i];
		a[i] = a[p];
		a[p] = temp;
	}
}

template <typename T>
void display(T a, int n)
{
	cout << a[n] << ' ';
}

int main()
{
	char a[10] = { 'a', 'b', 'e', 'g', 'f', 'u', 'v', 'j', 'h', 'b' };
	sort(a, 10);
	for (int i = 0; i < 10; i++)
		display(a, i);
	cout << endl;

	system("pause");
	return 0;
}