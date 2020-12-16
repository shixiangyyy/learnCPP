#include <iostream>
#include <string>
#include <tuple>
#include <bitset>
using namespace std;

//tuple�ݹ����
template <int IDX, int MAX, typename...Args>
struct print_tuple
{
	static void print(ostream& os, const tuple<Args...>& tp)
	{
		os << get<IDX>(tp) << (IDX + 1 == MAX ? "" : ",");
		print_tuple<IDX + 1, MAX, Args...>::print(os, tp);
	}
};

//ƫ�ػ�
template <int MAX, typename...Args>
struct print_tuple<MAX, MAX, Args...>
{
	//��IDX+1 = MAXʱ�����õ��������������
	static void print(ostream& os, const tuple<Args...>& tp){}
};

template <typename...Args>
ostream& operator << (ostream& os, const tuple<Args...>& tp)
{
	os << "[";
	print_tuple < 0, sizeof...(Args), Args...>::print(os, tp);
	return os << "]";
}

int main()
{
	cout << make_tuple(7.5, string("hello"), bitset<16>(377), 47) << endl;
	system("pause");
	return 0;
}