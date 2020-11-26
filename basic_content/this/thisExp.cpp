#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	typedef enum {
		Boy = 0,
		Girl
	}sexType;
	Person(string n, int a, sexType s):name(n), age(a), sex(s) {}
	int getAge()
	{
		return this->age;
	}
	Person& addAge(int a)
	{
		age += a;
		return *this;//���ر�����
	}
	virtual ~Person(){}

private:
	string name;
	int age;
	sexType sex;
};

int main()
{
	Person p("Xiang Shi", 25, Person::Boy);
	cout << p.getAge() << endl;
	cout << p.addAge(5).getAge() << endl; //addAgeֱ�ӷ��ض�����
	
	system("pause");
	return 0;
}