#include <iostream>
using namespace std;

const int MAXSIZE = 5;

//堆栈满了或者空了时抛出的异常类
template <typename T>
class Full 
{
	T a;
public:
	Full(T e) :a(e) {};
	T getValue() { return a; }
};
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
	if (top >= maxsize - 1) throw Full<T>(e);
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
	Stack<char> stk;
	for (int i = 0; i < MAXSIZE; i++) stk.push('a' + i);
	try
	{
		stk.push('a');
	}
	catch (Full<char> err)
	{
		cout << "Exception: Stack full...\n";
		cout << "The value not push in Stack: " << err.getValue() << endl;
	}

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