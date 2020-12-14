#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

class Person
{
private:
	char name[20];
	char id[18];
	int age;
	char addr[20];
public:
	Person() {};
	Person(char* n, char* pid, int age, char* addr)
	{
		strcpy(name, n);
		strcpy(id, pid);
		this->age = age;
		strcpy(this->addr, addr);
	}
	void display()
	{
		cout << name << "\t" << id << "\t" << age << "\t" << addr << endl;
	}
};

int main()
{
	vector<Person> v;
	vector<Person>::iterator iter;
	char ch;
	ofstream oFile("./��ϰ.dat", ios::out | ios::binary);
	char name[20], id[18], addr[20];
	int age;
	cout << "-----��ʼ������˵���------\n";
	do
	{
		cout << "������ ";
		cin >> name;
		cout << "Id: ";
		cin >> id;
		cout << "���䣺 ";
		cin >> age;
		cout << "��ַ�� ";
		cin >> addr;
		Person per(name, id, age, addr);
		oFile.write((char*)&per, sizeof(per));
		cout << "Enter another person(y/n)? ";
		cin >> ch;
	} while (ch == 'y');
	oFile.close();

	ifstream iFile("./��ϰ.dat", ios::in | ios::binary);
	Person s;
	iFile.read((char*)&s, sizeof(s));
	while (!iFile.eof())
	{
		v.push_back(s);
		iFile.read((char*)&s, sizeof(s));
	}
	
	cout << "\n-------��ʼ���ļ��ж�ȡ����--------\n";
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		(*iter).display();
	}

	system("pause");
	return 0;
}