#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream ioFile;
	ioFile.open("./a.dat", ios::out);
	ioFile << "����" << " " << 76 << " " << 89 << " " << 100 << endl;
	ioFile << "����" << " " << 89 << " " << 100 << " " << 22 << endl;
	ioFile << "����" << " " << 89 << " " << 53 << " " << 22 << endl;
	ioFile << "����" << " " << 83 << " " << 80 << " " << 22 << endl;
	ioFile << "����" << " " << 89 << " " << 90 << " " << 87 << endl;
	ioFile.close();
	ioFile.open("./a.dat", ios::in | ios::binary);
	char name[10];
	int chinese, math, computer;
	cout << "����\t" << "Ӣ��\t" << "��ѧ\t" << "�����\t" << "�ܷ�" << endl;
	while (!ioFile.eof())
	{
		ioFile >> name >> chinese >> math >> computer;
		cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t" << chinese + math + computer << endl;
	}
	ioFile.close();
	system("pause");
	return 0;
}