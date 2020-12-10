#include <iostream>
using namespace std;

int main()
{
	/* ‰»Î£∫
	ffassfjd, sfjkfdjks, fjskldf, fsjkdfljk, jfsfjlsf,
	 ‰≥ˆ£∫
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