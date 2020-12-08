#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int SIZE = 11;

template <typename T, int SIZE>
class Array
{
private:
	T elem[SIZE];
public:
	Array();
	void sort();
	T& operator[](int n);
};

template <typename T, int SIZE>
Array<T, SIZE>::Array()
{
	for (int i = 0; i < SIZE; i++)
		elem[i] = 0;
}

template <typename T, int SIZE>
T& Array<T, SIZE>::operator[](int n)
{
	if (n >= SIZE) cout << "Out of range." << endl;
	return elem[n];
}

template <typename T, int SIZE>
void Array<T, SIZE>::sort()
{
	for (int i = 0; i < SIZE; i++)
	{
		int p = i;
		for (int j = i; j < SIZE; j++)
			if (elem[j] > elem[p]) p = j;
		swap(elem[i], elem[p]);
	}
}

template <>
void Array<const char*, SIZE>::sort()
{
	for (int i = 0; i < SIZE; i++)
	{
		int p = i;
		for (int j = i; j < SIZE; j++)
			if (strcmp(elem[j], elem[j])) p = j;
		swap(elem[i], elem[p]);
	}
}

int main()
{
	cout << "Int Array.\n";
	//写上10，编译器自动将模板类SIZE弄为10，原先的11失效
	Array<int, 10> intArr;
	for (int i = 0; i < 10; i++)
		intArr[i] = i;
	intArr.sort();
	for (int i = 0; i < 10; i++) cout << intArr[i] << " ";

	cout << "\nString Array\n";
	Array<const char*, 10> strArr;
	for (int i = 0; i < 10; i++)
	{
		strArr[i] = "abc";
	}
	strArr.sort();
	for (int i = 0; i < 10; i++) cout << strArr[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}