#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream ioFile;
	ioFile.open("./a.dat", ios::out);
	ioFile << "张三" << " " << 76 << " " << 89 << " " << 100 << endl;
	ioFile << "李四" << " " << 89 << " " << 100 << " " << 22 << endl;
	ioFile << "王五" << " " << 89 << " " << 53 << " " << 22 << endl;
	ioFile << "陈留" << " " << 83 << " " << 80 << " " << 22 << endl;
	ioFile << "何四" << " " << 89 << " " << 90 << " " << 87 << endl;
	ioFile.close();
	ioFile.open("./a.dat", ios::in | ios::binary);
	char name[10];
	int chinese, math, computer;
	cout << "姓名\t" << "英语\t" << "数学\t" << "计算机\t" << "总分" << endl;
	while (!ioFile.eof())
	{
		ioFile >> name >> chinese >> math >> computer;
		cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t" << chinese + math + computer << endl;
	}
	ioFile.close();
	system("pause");
	return 0;
}