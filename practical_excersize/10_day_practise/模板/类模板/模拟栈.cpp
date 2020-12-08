#include <iostream>
using namespace std;

template <typename T, int MAXSIZE>
class Stack
{
private:
	int top;
	T elem[MAXSIZE];
public:
	Stack() { top = -1; };
	void setEmpty() { top = -1; };
	T pop();
	void push(T e);
	bool isEmpty() { return top <= -1; }
	bool full() { return top >= MAXSIZE - 1; }
};

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
	if (isEmpty())
	{
		cout << "栈已空，请不要弹出。" << endl;
		return -1;
	}
	return elem[top--];
}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
	if (!full())
	{
		elem[++top] = e;
	}
	else
	{
		cout << "栈已满，请重新分配空间。" << endl;
	}
}

int main()
{
	Stack<int, 10> intStack;
	Stack<char, 10> charStack;
	intStack.setEmpty();
	charStack.setEmpty();

	cout << "int stack\n";
	for (int i = 0; i < 10; i++)
		intStack.push(i);
	for (int i = 0; i < 10; i++) cout << intStack.pop() << " ";

	cout << "\nchar stack\n";
	for (int i = 0; i < 10 ; i++)
		charStack.push('a' + i);
	for (int i = 0; i < 10; i++) cout << charStack.pop() << " ";
	cout << endl;

	system("pause");
	return 0;
}