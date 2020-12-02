#include <iostream>
#include <string>
using namespace std;

struct Person
{
	string name;
	double salary;
};

class Group
{
private:
	Person* employ;
	int max; //最大组员人数
	int n; //实际人数
public:
	Group(int m);
	void resizeSpace();
	void display();
	double& operator[](string name);
};

Group::Group(int m = 0)
{
	max = m;
	n = 0;
	employ = new Person[max];
}

void Group::resizeSpace()
{
	max = n * 2;
	Person* employTmp = new Person[max];
	for (int i = 0; i < n - 1; i++)
		*(employTmp + i) = *(employ + i);
	this->employ = employTmp;
}

void Group::display()
{
	for (int i = 0; i < n; i++)
		cout << (employ + i)->name << ":" << (employ + i)->salary << endl;
}

double& Group::operator[](string name)
{
	Person* p;
	for (p = employ; p < employ + n; p++)
		if (p->name == name) return p->salary;
	if (++n > max)
		resizeSpace();
	p = employ + n - 1;
	p->name = name;
	p->salary = 0;
	return p->salary;
}

int main()
{
	Group G(5);
	G["石翔"] = 20000;
	G["里斯"] = 19999;
	G["杰瑞"] = 19998;
	G["亨利"] = 20001;
	G["阿泽"] = 20002;
	G.display();
	//扩容
	G["叶子"] = 100000;
	cout << "After space resize\n";
	G.display();

	system("pause");
	return 0;
}


