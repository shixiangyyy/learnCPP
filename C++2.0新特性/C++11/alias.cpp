#include <vector>
using namespace std;

//C++11不可以对alias template做偏特化或者全特化
//Because an alias-declaration cannot declare a template-id, 
//it is not possible to partially or explictly specialize an 
//alias template
//不能对化名做全特化或者偏特化，需要特化的话，需要对本名模板进行特化
template <typename T>
using Vec = vector<T, allocator<T>>;
//使用宏定义不行
//#define Vec<T> template<typename T> vector<T,allocator<T>>;
//宏是简单的替换,使用macro难以达到using相同的效果

int main()
{
	Vec<int> col;
	//如果使用宏#define的话，上述会被替换为：
	//template <typename int> vector<int, allocator<int>>;error
	//使用typedef也无法做到，没法指定模板参数

	return 0;
}