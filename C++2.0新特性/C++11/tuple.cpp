#include <iostream>
#include <tuple>
using namespace std;

int main()
{
	tuple<int, int, string> t, t1, t2;
	t = make_tuple(0, 0, "0");
	t1 = make_tuple(1, 1, "1");
	t2 = make_tuple(2, 2, "2");

	int a = get<0>(t);
	get<0>(t) = get<1>(t);//����ֱ�Ӹ�ֵ��˵��get���ص�������
	cout << a << endl;
	cout << (get<0>(t) > get<1>(t) ? "true" : "false") << endl;

	typedef tuple<int, int, int, string> T;
	//mata programming�������ͣ������ݵ�type���б��
	cout << tuple_size<T>::value << endl;
	tuple_element<1, T>::type a1 = 10;
	cout << a1 << endl;

	system("pause");
	return 0;
}