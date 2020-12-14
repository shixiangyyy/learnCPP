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
		employ = new Person[this->max];//��ֹemployΪ��ָ�룬����ʼ��ʱ��Ĭ�����Աָ��Ϊ��ָ��
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
		//��ʱ�����ڵĻ�
		Person* p = employ + n++;
		//p->name = name;//����д����ȫ��������ָ�븳ֵ��ǳ��������Ҫʵ�����
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
	salMan["ʯ��"] = 11111;
	salMan["��˼"] = 23841;
	salMan["Ҷ��"] = 23542;
	cout << "ʯ�裺" << salMan["ʯ��"] << endl;
	cout << "��˼��" << salMan["��˼"] << endl;
	cout << "Ҷ��: " << salMan["Ҷ��"] << endl;

	system("pause");
	return 0;
}