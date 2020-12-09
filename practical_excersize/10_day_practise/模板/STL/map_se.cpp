#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string name[3] = { "张麻子","李二","王三" };
	double sala[3] = { 1200, 1400,2400 };
	map<string, double> sal;
	map<string, double>::iterator it;
	for (int i = 0; i < 3; i++)
	{
		sal.insert(make_pair(name[i], sala[i]));
	}
	sal["吴四"] = 3500;
	sal["何五"] = 4000;
	for (it = sal.begin(); it != sal.end(); it++)
		cout << it->first << ":" << it->second << endl;

	system("pause");
	return 0;
}