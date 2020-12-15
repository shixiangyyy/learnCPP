//�����ļ�������EOF
//eof()����trueʱ�Ƕ����ļ�������0xFF,���ļ������������һ���ַ�����һ���ַ�
//��ˣ����������һ���ַ�ʱ���������һ��
//��Ϊ������������ָ��ͣ�������һ���ַ����Ȼ���ظ���ȡһ��
//��Ҳ�������һ�����鴦���û�������ε�ԭ��
//ʹ��peek():�����������ļ�����һ���ַ����������ƶ�����ָ��
//����취: while(ioFile.peek() != EOF)������ʵ�ִ��������
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class Person
{
private:
	char name[20];
	char ID[20];
	int math, english, chinese, sum;
public:
	Person() {};
	Person(char* Name, char* id, int math, int english, int chinese)
	{
		strcpy(name, Name); strcpy(ID, id);
		this->math = math; this->english = english; this->chinese = chinese;
		sum = math + english + chinese;
	}
	void display()
	{
		cout << name << "\t" << ID << "\t" << math << "\t" << english << "\t" 
			<< chinese << "\t" << sum << endl;
	}
};

int main()
{
	char ch;
	char Name[20], ID[20];
	int math, english, chinese;
	fstream ioFile;
	ioFile.open("./�ļ���д�ۺ���.dat", ios::out | ios::app);
	cout << "---����ѧ��������Ϣ---\n";
	do
	{
		cout << "������ѧ������:\n";
		cin >> Name;
		cout << "������ѧ��ID:\n";
		cin >> ID;
		cout << "��������ѧ�ɼ�:\n";
		cin >> math;
		cout << "������Ӣ��ɼ�:\n";
		cin >> english;
		cout << "���������ĳɼ�:\n";
		cin >> chinese;
		Person per(Name, ID, math, english, chinese);
		ioFile.write((char*)&per, sizeof(per));
		cout << "�Ƿ��������ѧ����Ϣ��(y/n):\n";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	ioFile.close();

	ioFile.open("./�ļ���д�ۺ���.dat", ios::in);
	Person per;
	vector<Person> v;
	while (ioFile.peek() != EOF)
	{
		ioFile.read((char*)&per, sizeof(per));
		v.push_back(per);
	}
	ioFile.close();

	cout << "��������е�ѧ����Ϣ��\n";
	for (vector<Person>::iterator iter = v.begin(); iter != v.end(); iter++)
		iter->display();

	system("pause");
	return 0;
}