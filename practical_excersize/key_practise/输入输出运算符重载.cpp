#include <iostream>
#include <string.h>
using namespace std;

class Sales
{
private:
	char name[10];
	char id[20];
	int age;
public:
	Sales(char* name, char* id, int age);
	friend ostream& operator<< (ostream& os, Sales& s);
	friend istream& operator>> (istream& is, Sales& s);
};

Sales::Sales(char* name, char* id, int age)
{
	strcpy(this->name, name);
	strcpy(this->id, id);
	this->age = age;
}
//重载输出运算符
ostream& operator<< (ostream& os, Sales& s)
{
	os << s.name << '\t'<< s.id << '\t'<< s.age << '\t';
	return os;
}
//重载输入运算符
istream& operator>> (istream& is, Sales& s)
{
	cout << "输入雇员的姓名，身份证号，年龄" << endl;
	is >> s.name >> s.id >> s.age;
	return is;
}

int main()
{
	Sales s1("石翔", "421127199506150010", 25);
	cout << s1;
	cout << endl;
	cin >> s1;
	cout << s1;
	system("pause");
	return 0;
}