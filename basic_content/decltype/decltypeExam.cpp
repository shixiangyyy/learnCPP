#include <iostream>
#include <vector>
using namespace std;

//���ͱ���н��auto��ʹ�ã�����׷�ٺ����ķ���ֵ������
template<typename T>
auto multiply(T x, T y)->decltype(x * y)
{
	return x * y;
}

int main()
{
	int num[] = { 1,2,3,4 };
	vector<int> vec(num, num + 4);
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
	cout << endl;

	typedef decltype(vec.begin()) vectype;
	for (vectype i = vec.begin(); i != vec.end(); i++)
		cout << *i << " ";
	cout << endl;

	/*�����ṹ��*/
	struct
	{
		int i;
		double d;
	}anonymous_s;
	decltype(anonymous_s) as;//������һ������������ṹ��

	cout << multiply(62558, 62559) << endl;//Ĭ���ж�������Ϊint���ͣ�������ǻ����
	system("pause");
	return 0;
}