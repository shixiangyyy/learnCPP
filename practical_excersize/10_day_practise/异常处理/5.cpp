#include <iostream>
using namespace std;

void handler(int n) throw(int, char, double)
{
	n == 1 ? throw(n) : (n == 2 ? throw('x') : throw(1.1));
}

int main()
{
	cout << "Before handler...\n";
	try
	{
		handler(1);
	}
	catch (int i) { cout << "Catch an interger...\n"; }
	catch (char c) { cout << "Catch a character...\n"; }
	catch (double d) { cout << "Catch a double...\n"; }

	system("pause");
}