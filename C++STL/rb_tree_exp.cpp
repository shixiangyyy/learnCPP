#include <set>
#include <iostream>
using namespace std;

int main()
{
	_Rb_tree<int, int, _Identity<int>, less<int>> itree; //OK
	cout << itree.empty() << endl;
	cout << itree.size() << endl;

	itree._M_insert_unique(3);
	itree._M_insert_unique(8);
	itree._M_insert_unique(5);
	itree._M_insert_unique(0);
	itree._M_insert_unique(13);
	itree._M_insert_unique(5); //no effect,since using unique
	cout << itree.empty() << endl;
	cout << itree.size() << endl;
	cout << itree.count(5) << endl;

	itree._M_insert_equal(5);
	itree._M_insert_equal(5);
	cout << itree.size() << endl;
	cout << itree.count(5) << endl;

	system("pause");
	return 0;
}