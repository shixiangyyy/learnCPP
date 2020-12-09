#include <iostream>
using namespace std;

const int MAXSIZE = 5;

//堆栈满了或者空了时抛出的异常类
class Full {}; 
class Empty {};

template <typename T>
class Stack
{
	int top;
	int maxsize = MAXSIZE;
	T elem[MAXSIZE];
public:
	void push(T e);
	T pop();
	Stack() { top = -1; }
};

template <typename T>
void Stack<T>::push(T e)
{
	if (top >= maxsize - 1) throw Full();
	*(elem + ++top) = e;
}

template <typename T>
T Stack<T>::pop()
{
	if (top == -1) throw Empty();
	return *(elem + top--);
}

int main()
{
	Stack<int> stk;
	for (int i = 0; i < MAXSIZE; i++) stk.push(i);
	try
	{
		stk.push(0);
	}
	catch (Full) { cout << "Catch an Full type exception.\n"; }

	for (int i = 0; i < MAXSIZE; i++) 
	{ 
		cout << "Pop the " << i << "th element: " << stk.pop() << endl; 
	}
	try
	{
		stk.pop();
	}
	catch (Empty) { cout << "Catch an empty type exception.\n"; }

	system("pause");
}