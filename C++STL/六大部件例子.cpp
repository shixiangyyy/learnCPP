#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int a[7] = {1, 42, 234, 545, 34, 23, 500};
	vector<int, allocator<int>> avec(a, a + 7);
	
	cout<<count_if(avec.begin(), avec.end(), 
		not1(bind2nd(less<int>(), 40)))<<endl; //4,不小于40的元素个数
	
	system("pause");
	return 0;
}

//其中：
//vector：容器
//allocator：分配器
//avec.begin(), avec.end()：迭代器
//less<int>()：函数对象，仿函数
//count_if：算法
//bind2nd：函数适配器(binder), not1：函数适配器(negator, 反向器)
