#include <iostream>
#include <list>
using namespace std;

template <typename T>
using Lst = list<T>;

template<typename T, template<typename T2> typename Container >
class XLS
{
private:
	Container<T> c;
};

int main()
{
	XLS<string, Lst> xls;

	return 0;
}