#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <typename T1, typename T2>
using aliasA = map < T1, T2>;

int main()
{
	//try all specialization
	aliasA<char*, int> map_c_i; 
	map_c_i.insert({"Ê¯Ïè",2}); //OK
	return 0;
}