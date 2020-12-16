#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

//(3)����һ����ֹ����
template <typename T>
void _hash(size_t& seed, const T& val)
{
	cout << "hash over " << val << endl;
}

//(2)չ���������Ѳ�����Χһ����ͨ������һ����������ÿ����һ�Σ���������С��һ
template <typename T, typename...Args>
void _hash(size_t& seed, const T& val, const Args&...args)
{
	cout << "Parameter " << val << endl;
	//�ݹ�����Լ�
	_hash(seed, args...);
}

//(1)������
template <typename...Args>
size_t _hash(const Args&...args)
{
	cout << "hash start " << endl;
	size_t seed = 10;
	_hash(seed, args...);
	return seed;
}

//���������������ģ��
template<typename...Args>
class A
{
private:
	int size = 10;
public:
	A()
	{
		size = sizeof...(Args);
		cout << size << endl;
	}
};

int main()
{
	size_t f = 10;
	_hash("adidas", 2, 3, 4);
	A<int, string, vector<int>> a;

	//tuple�������ñ䳤����ģ�������ʵ��
	tuple<int, string> t = make_tuple(1, "nike");
	int firstArg = get<0>(t);
	string secondArg = get<1>(t);
	cout << firstArg << " " << secondArg << endl;
	system("pause");
	return 0;
}