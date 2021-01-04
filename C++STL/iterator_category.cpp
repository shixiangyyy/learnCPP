#include <iostream>
#include <iterator>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

template <typename Typ>
void display_category(Typ itre)
{
	typename iterator_traits<Typ>::iterator_category catg;
	_display_category(catg);
	cout << "typeid(itre).name() = " << typeid(itre).name() << endl << endl;
}

void _display_category(input_iterator_tag)
{
	cout << "input_iterator_tag" << endl;
}

void _display_category(output_iterator_tag)
{
	cout << "output_iterator_tag" << endl;
}

void _display_category(forward_iterator_tag)
{
	cout << "forward_iterator_tag" << endl;
}

void _display_category(bidirectional_iterator_tag)
{
	cout << "bidirectional_iterator_tag" << endl;
}

void _display_category(random_access_iterator_tag)
{
	cout << "random_access_iterator_tag" << endl;
}

int main()
{
	cout << "Test iterator_category.......\n" << endl;
	
	cout << "array:";
	display_category(array<int, 10>::iterator());
	cout << "vector:";
	display_category(vector<int>::iterator());
	cout << "list:";
	display_category(list<int>::iterator());
	cout << "forward_list:";
	display_category(forward_list<int>::iterator());
	cout << "deque:";
	display_category(deque<int>::iterator());
	cout << "set:";
	display_category(set<int>::iterator());
	cout << "map:";
	display_category(map<int, int>::iterator());
	cout << "multiset:";
	display_category(multiset<int>::iterator());
	cout << "multimap:";
	display_category(multimap<int, int>::iterator());
	cout << "unordered_set:";
	display_category(unordered_set<int>::iterator());
	cout << "unordered_map:";
	display_category(unordered_map<int, int>::iterator());
	cout << "unordered_multiset:";
	display_category(unordered_multiset<int>::iterator());
	cout << "unordered_multimap:";
	display_category(unordered_multimap<int, int>::iterator());
	cout << "istream:";
	display_category(istream_iterator<int>());
	cout << "ostream:";
	display_category(ostream_iterator<int>(cout, ""));
	
	system("pause");
	return 0;
}

/* Test iterator_category.......

array:random_access_iterator_tag
vector:random_access_iterator_tag
list:bidirectional_iterator_tag
forward_list:forward_iterator_tag
deque:random_access_iterator_tag
set:bidirectional_iterator_tag
map:bidirectional_iterator_tag
multiset:bidirectional_iterator_tag
multimap:bidirectional_iterator_tag
unordered_set:bidirectional_iterator_tag
unordered_map:bidirectional_iterator_tag
unordered_multiset:bidirectional_iterator_tag
unordered_multimap:bidirectional_iterator_tag
istream:input_iterator_tag
ostream:output_iterator_tag */

