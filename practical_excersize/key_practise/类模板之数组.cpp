#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

const int MAXSIZE = 5;

template <typename T>
class Array
{
private:
	T elems[MAXSIZE];
public:
	Array();
	T& operator[](int n);
	void sort();
};

template <typename T>
Array<T>::Array()
{
	for (int i = 0; i < MAXSIZE; i++)
		elems[i] = 0;
}

template <typename T>
T& Array<T>::operator[](int n)
{
	assert(n < MAXSIZE);
	return elems[n];
}

template <typename T>
void Array<T>::sort()
{
	int p, j;
	for (int i = 0; i < MAXSIZE; i++)
	{
		p = i;
		for (int j = i + 1; j < MAXSIZE; j++)
		{
			if (elems[p] < elems[j]) p = j;
		}
		T temp = elems[p];
		elems[p] = elems[i];
		elems[i] = temp;
	}
}

//类模板函数特化
template <>
void Array<char*>::sort()
{
	int p, j;
	for (int i = 0; i < MAXSIZE; i++)
	{
		p = i;
		for (int j = i + 1; j < MAXSIZE; j++)
		{
			if (strcmp(elems[p], elems[j]) < 0) p = j;
		}
		char* temp = elems[p];
		elems[p] = elems[i];
		elems[i] = temp;
	}
}

int main()
{
	Array<int> aint;
	Array<char*> astr;
	aint[0] = 9; aint[1] = 10; aint[2] = 100; aint[3] = 22; aint[4] = 9;
	aint.sort();
	astr[0] = "sfds"; astr[1] = "shi"; astr[2] = "yousi"; astr[3] = "yezi"; astr[4] = "heixn";
	astr.sort();

	for (int i = 0; i < MAXSIZE; i++)
		cout << aint[i] << "\t" << astr[i] << endl;

	system("pause");
	return 0;
}