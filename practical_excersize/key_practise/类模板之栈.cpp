#include <iostream>
using namespace std;

template <typename T, int MAXSIZE>
class Stack
{
private:
	T elems[MAXSIZE];
	int top;
public:
	Stack() {};
	void init() { top = -1; }
	bool isFull() { return top >= MAXSIZE - 1; }
	bool isEmpty() { return top == -1; }
	void push(T e);
	T pop();
};

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
	if (isFull())
	{
		cout << "Stack is full, new elements are not allowed!\n";
		return;
	}
	elems[++top] = e;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
	if (isEmpty())
	{
		cout << "The Stack is empty, pop elements are not allowed!\n";
		return 0;
	}
	return elems[top--];
}

int main()
{
	Stack<int, 10> s1;
	s1.init();
	for (int i = 0; i < 10; i++)
		s1.push(i);
	for (int i = 0; i < 10; i++)
		s1.pop();
	cout << endl;
	system("pause");
	return 0;
}