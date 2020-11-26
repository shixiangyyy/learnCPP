#include <iostream>
using namespace std;

//虚函数实现运行时多态
class Employee
{
public:
	virtual void raiseSalary()
	{
		cout << 0 << endl;
	};
	virtual void promote() {};
};

class Manager :public Employee
{
public:
	virtual void raiseSalary()
	{
		cout << 200 << endl;
	};
	virtual void promote() {};
};

class Engineer :public Employee
{
public:
	virtual void raiseSalary()
	{
		cout << 100 << endl;
	};
	virtual void promote() {};
};

void globalRaiseSalary(Employee* emp[], int n)
{
	for (int i = 0; i < n; i++)
		emp[i]->raiseSalary();
}

int main()
{
	//必须是public继承，虚函数才有效实现动态多态
	Employee* emp[] = { new Manager(), new Engineer() };
	globalRaiseSalary(emp, 2);
	system("pause");
	return 0;
}