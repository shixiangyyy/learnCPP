//关于文件结束符EOF
//eof()返回true时是读到文件结束符0xFF,而文件结束符是最后一个字符的下一个字符
//因此，当读到最后一个字符时，程序会多读一次
//因为，编译器会让指针停留在最后一个字符那里，然后重复读取一次
//这也就是最后一组数组处理不好会输出两次的原因
//使用peek():返回输入流文件的下一个字符，但它不移动内置指针
//解决办法: while(ioFile.peek() != EOF)，可以实现代码的美观
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
	ioFile.open("./文件读写综合题.dat", ios::out | ios::app);
	cout << "---建立学生档案信息---\n";
	do
	{
		cout << "请输入学生姓名:\n";
		cin >> Name;
		cout << "请输入学生ID:\n";
		cin >> ID;
		cout << "请输入数学成绩:\n";
		cin >> math;
		cout << "请输入英语成绩:\n";
		cin >> english;
		cout << "请输入语文成绩:\n";
		cin >> chinese;
		Person per(Name, ID, math, english, chinese);
		ioFile.write((char*)&per, sizeof(per));
		cout << "是否继续输入学生信息？(y/n):\n";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	ioFile.close();

	ioFile.open("./文件读写综合题.dat", ios::in);
	Person per;
	vector<Person> v;
	while (ioFile.peek() != EOF)
	{
		ioFile.read((char*)&per, sizeof(per));
		v.push_back(per);
	}
	ioFile.close();

	cout << "输出档案中的学生信息：\n";
	for (vector<Person>::iterator iter = v.begin(); iter != v.end(); iter++)
		iter->display();

	system("pause");
	return 0;
}