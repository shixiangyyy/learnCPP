#include <iostream>
using namespace std;

int main()
{
	/*���룺
	ffassfjd, sfjkfdjks, fjskldf, fsjkdfljk, jfsfjlsf,
	�����
	ffassfjd
	sfjkfdjks
	fjskldf
	fsjkdfljk
	jfsfjlsf*/
	char stu[5][10];
	for (int i = 0; i < 5; i++)
		cin.getline(stu[i], 10, ',');
	for (int i = 0; i < 5; i++)
		cout << stu[i] << endl;

	system("pause");
}