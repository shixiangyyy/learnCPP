#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

//\include\c++\bits\stl_iterator.h
//#if __cplusplus >= 201103L
//inline auto
//operator-(const reverse_iterator<_IteratorL>& __x,
//	const reverse_iterator<_IteratorR>& __y)->decltype(__y.base()-__x.base())
//#else
//inline typename reverse_iterator<_IteratorL>::difference_type
//operator-(const reverse_iterator<_IteratorL>& __x,
//	const reverse_iterator<_IteratorR>& __y)
//#endif
//{ return __y.base() - __x.base(); }


class C
{
private:
	string str;
public:
	//explicit���εĹ��캯�������Է�ֹ��ʽת���͸��Ƴ�ʼ��
	explicit C(const string& s) :str(s) {};
	
	friend ostream& operator<<(ostream& os, const C& c)
	{
		cout << c.str << endl;
	}
};

int main()
{
	auto i = 42; //������ʵ���Ƶ�

	auto ll1 = [](int x) {return x + 10; }; //�Զ��ж�lambda���ʽ����

	function<int(int x)> ll = [](int x) {return x + 10; }; //lambda����functor

	cout << ll1(10) << endl;

	list<int> lst{ 1,2,3 };
	list<int>::iterator iter = find(lst.begin(), lst.end(), 2);
	auto iterAT = find(lst.begin(), lst.end(), 2); //��д������

	vector<int> vec{ 22,234,23,2343,45234,524,5324 };
	//==================range based for statement============================
	//pass by value(1)
	for (auto elem : vec) cout << elem << " ";
	cout << endl;
	//C++2.0֮ǰ�����������(1)תΪ(2)����(3)
	for (auto _pos = vec.begin(); _pos != vec.end(); _pos++) cout << *_pos << " ";
	cout << endl;
	//(3)��C++2.0֮��ȫ�ֺ���begin��end���Խ���������Ϊ����
	for (auto _pos = begin(vec); _pos != end(vec); _pos++)cout << *_pos << " ";
	cout << endl;
	//(4) pass by reference
	for (auto &elem : vec) cout << elem << " ";
	cout << endl;
	//�������Ὣ(4)תΪ(5)
	for (auto _pos = vec.begin(); _pos != vec.end(); _pos++)
	{
		auto& elem = *_pos;
		cout << elem << " ";
	}cout << endl;

	vector<string> vs{ "Hello", "world of auto!" };
	//C���м���explicit�Ͳ��ܽ�����ʽ����ת���ˣ������������벻��ͨ������
	/*for (const C& elem:vs){...} ��Ϊvs���ܱ���ʽת��ΪC����*/
	
	//autoȱ�㣺���ʹ���Ŀɶ��ԣ����ܵò�����Ҫ��Ԥ�ڣ����decltype�������벻����Ч��
	//auto���ܵò���Ԥ������ͣ�����vector<bool>[]�ķ�������
	vector<bool> v(true);
	auto var = v[0];
	cout << typeid(var).name() << endl; //St14_Bit_reference

	system("pause");
	return 0;
}