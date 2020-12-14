#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//往文件中写入对象，好处是将来可以整个读取出来进行操作，不必去考虑细节
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
	Employee e1(1, "张三", 23, 2320);
	Employee e2(2, "李四", 23, 2520);
	Employee e3(3, "王五", 21, 3320);
	Employee e4(4, "和流", 23, 4320);
	//按e1-e4的顺序写入文件
	out.write((char*)&e1, sizeof(e1));
	out.write((char*)&e2, sizeof(e2));
	out.write((char*)&e3, sizeof(e3));
	out.write((char*)&e4, sizeof(e4));

	//下面的代码将e3的年龄改为40岁
	Employee e5(3, "王五", 40, 3320);
	out.seekp(2 * sizeof(e1));
	out.write((char*)&e5, sizeof(e5));
	out.close();

	//读取文件中的内容并进行显示
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