#include <iostream>
#include <cstring>
using namespace std;

struct Person
{
	char* name;
	double salary;
};

class salaryManager
{
private:
	Person* employ;
	int max;
	int n;
public:
	salaryManager(int max = 0) 
	{ 
		this->max = max; 
		n = 0;  
		employ = new Person[this->max];//防止employ为空指针，不初始化时，默认类成员指针为空指针
	};
	void display()
	{
		for (int i = 0; i < n; i++)
			cout << employ[i].name << "\t" << employ[i].salary << endl;
	}
	double& operator[](char* name)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(employ[i].name, name) == 0) return employ[i].salary;
		}
		//暂时不存在的话
		Person* p = employ + n++;
		//p->name = name;//这样写不安全，这样是指针赋值，浅拷贝，需要实现深拷贝
		p->name = new char[strlen(name) + 1];
		strcpy(p->name, name);
		p->salary = 0;
		return p->salary;
	}
	~salaryManager() { delete [] employ; }
};

int main()
{
	salaryManager salMan(3);
	salMan["石翔"] = 11111;
	salMan["游思"] = 23841;
	salMan["叶子"] = 23542;
	cout << "石翔：" << salMan["石翔"] << endl;
	cout << "游思：" << salMan["游思"] << endl;
	cout << "叶子: " << salMan["叶子"] << endl;

	system("pause");
	return 0;
}