#include <iostream>
#include <map>
#include <set>
using namespace std;

//decltype�÷�һ���ƶϷ�������
template <typename T1, typename T2>
auto add(T1 t1, T2 t2)->decltype(t1 + t2)
{
	return t1 + t2;
}

class Person
{
public:
	string firstname;
	string lastname;
};

int main()
{
	cout << add('a', 'b') << endl;

	//�÷�����ģ��Ԫ���
	//������һ��ģ�庯������ģ�����ȡ������value_type
	map<string, float> coll;
	decltype(coll)::value_type m{ "ʯ��", 1.0 };
	cout << m.first << m.second << endl;

	//�÷��������ڷ���lambda������(��������)
	auto cmp = [](const Person& p1, const Person& p2)
	{
		return p1.firstname > p2.lastname;
	};

	//����set���Ƚϴ�С�ķ�ʽ��cmp�ķ�ʽ
	//һ��Person��set����Ƚϴ�С����RB���������cmp���͵ķ���
	set<Person, decltype(cmp)> col(cmp);

}