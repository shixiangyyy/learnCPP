#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//���ļ���д����󣬺ô��ǽ�������������ȡ�������в���������ȥ����ϸ��
class Employee
{
private:
	int number, age;
	char name[20];
	double sal;
public:
	Employee() {};
	Employee(int num, char* name, int age, double salary)
	{
		number = num;
		strcpy(this->name, name);
		this->age = age;
		sal = salary;
	}
	void display()
	{
		cout << number << "\t" << name << "\t" << age << "\t" << sal << endl;
	}
};

int main()
{
	ofstream out("./Employee.dat", ios::out);
	Employee e1(1, "����", 23, 2320);
	Employee e2(2, "����", 23, 2520);
	Employee e3(3, "����", 21, 3320);
	Employee e4(4, "����", 23, 4320);
	//��e1-e4��˳��д���ļ�
	out.write((char*)&e1, sizeof(e1));
	out.write((char*)&e2, sizeof(e2));
	out.write((char*)&e3, sizeof(e3));
	out.write((char*)&e4, sizeof(e4));

	//����Ĵ��뽫e3�������Ϊ40��
	Employee e5(3, "����", 40, 3320);
	out.seekp(2 * sizeof(e1));
	out.write((char*)&e5, sizeof(e5));
	out.close();

	//��ȡ�ļ��е����ݲ�������ʾ
	ifstream inFile("./Employee.dat", ios::in | ios::binary);
	Employee eml;
	for (int i = 0; i < 4; i++)
	{
		inFile.read((char*)&eml, sizeof(eml));
		eml.display();
	}
	inFile.close();

	system("pause");
	return 0;
}