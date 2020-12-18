//C++11����lambda������inline functionality�Ķ��壬���ҿ�����һ����������һ���ֲ�����
//lambda�ı���C++��׼���ʹ�÷�ʽ

//ԭ���ĺ���������߷º��������ڿ���ͨ��lambdaʵ�֣�����֮ǰ��cmp������

////����ȥ��һ��������ʵ����һ�����󣬵�������д��û�������
//[] {std::cout << "hello world!" << std::endl; }

//�����������ͨ�����·�ʽֱ�ӵ���
//[] {std::cout << "hello lambda" << std::endl; }() //prints "hello lambda"
//typename�����С���ű�ʾֱ�ӵ���lambda��ʾʽ����

//or pass it to objects to get called
//���ݸ�������е���
//auto l = [] {
//	std::cout << "hello lambda" << std::endl;
//};
//l();

//�������Ϊһ����������(functionality)

//lambda is a definition of functionality, that can be defined inside
//statements and expressions.
//Thus, you can use a lambda as an inline function.

//������ʽ
//[...](...)mutable_opt throwSpec_opt ->retType_opt {...}
//mutable����()�в����Ƿ���Ա���д
//throwSpecָ���Ƿ��׳��쳣
//[]�з�capture��ָ����lambda�ڲ���ȡ�ⲿ�Ǿ�̬����nonstatic outside objects
//you can specify a capture to access data of outer scope that is not passed 
//as an argument

//[=]��ʾ�ⲿ������value����ʽ���ݸ�lambda
//[&]��ʾ�ⲿ������reference��ʽ���ݸ�lambda
//[=, &y]��ʾ����y�����ô��ݣ��������������Ķ����ǰ�ֵ����

//mutable������ͨ����ֵ�ķ�ʽ������lambda������ڲ����������У����жԴ��ݶ����д��Ȩ��

//*************************************************************
//*************************************************************
//The type of a lambda is an anonymous function object or functor that is unique for each
//lambda expression. Thus to declare objects of that type, you need templates or auto. If 
//you need the type, you can use decltype(), which is, for example, required to pass a lambda
//as hash function or ordering or sorting criterion to associative or unordered containers.

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Person
{
public:
	string firstName, lastName;
};

class UnNamedLocalFunction
{
	int localVal;
public:
	UnNamedLocalFunction(int val) :localVal(val) {};
	bool operator()(int val) { return val == localVal; }
};

class lambdaFunctor
{
	int _a, _b;
public:
	lambdaFunctor(int a, int b) :_a(a), _b(b) {};
	bool operator()(int n) const { return _a<n&&_b>n; };
};

class X
{
	int _x, _y;
public:
	X(int x, int y) :_x(x), _y(y) {};
	int operator()(int a) { return a; }
	int sum()
	{
		return [&]()->int {
			return operator()(_x + _y);
		}();
	}
	int ff()
	{
		return [this]() {
			return this->_x;
		}();
	}
};

int main()
{
	[] {cout << "Hello lambda!" << endl; }();

	auto I = [] {cout << "Hello lambda!" << endl; };
	I();
	//��ֵ����
	int id = 0;
	auto f = [id]()mutable {
		cout << "id = " << id++ << endl;
	};
	id = 42;
	f(); f(); f();
	cout << id << endl;
	//�����ô���
	int id1 = 0;
	auto f1 = [&id1] {
		cout << "id1 = " << id1++ << endl;
	};
	id1 = 42;
	f1(); f1(); f1();
	cout << id1 << endl;
	//�����뷵��
	int id2 = 0;
	auto f2 = [&id2](int& param) {
		cout << "id2 = " << id2++ << endl;
		++param;
		cout << "param = " << param << endl;
		static int x = 5;
		return id2;
	};
	int param = 1;
	f2(param);
	cout << "param = " << param << endl;
	//[=]:Ĭ����value���������ⲿ����
	//[&}:Ĭ����reference���������ⲿ����
	auto f3 = [&]() {
		cout << "id = " << id << endl;
		cout << "id1 = " << id1 << endl;
		cout << "id2 = " << id2 << endl;
		cout << "param = " << param << endl;
	};
	f3();

	//thisָ��
	X _x(1, 2);
	cout << "_x.sum() = " << _x.sum() << endl;
	cout << "_x.ff() = " << _x.ff() << endl;

	//�����lambda�����ȼ���������UnNamedLocalFunction
	int tobefound = 5;
	auto lambda1 = [tobefound](int val) {
		return val == tobefound;
	};
	UnNamedLocalFunction lambda2(tobefound);
	cout << lambda1(5) << " " << lambda2(5) << endl;

	auto ll1 = [](int x)->int { return x + 10; };
	//lambda��������
	function<int(int x)> l1 = [](int x)->float { return x + 10.0; };
	cout << l1(10.1) << endl; //ע�⣬���������int���ͣ���Ϊ����ʽת��Ϊfunction<int(int x)>����

	//decltype+lambda
	function<bool(const Person&p1, const Person&p2)> cmp = [](const Person&p1, const Person&p2) {
		return p1.lastName < p2.lastName;
	};

	//��lambda functor��Ϊset������sorting criterion������setģ�壬���ڶ���ʵ����ʱ��Ϊcmp����
	set<Person, decltype(cmp)> coll(cmp); //set��һ�����캯����������cmp׼��Ϊ��������˴���lambda����cmp

	// ���������Ǻ�ǿ��ģ���װ������������Զ����׼�����Ϊ������Ҫд������������Ҫд������class�����ǲ�����ģ�
	//�����ǷǱ��صģ�������Ҳ�鷳����Ҫȥ������ʹ�ã��������������ϢҲ���Ѻã��������ǲ���inline�ģ�Ч�ʻ��һЩ
	//���㷨Ч�ʻ�������Ҫ�ģ���

	vector<int> vec{ 5,23,4,234,234,22,2,2,5,6 };
	int x = 4, y = 22;
	vec.erase(remove_if(vec.begin(), vec.end(), [x, y](int n) {return x < n&&n < y; }), vec.end());
	for_each(vec.begin(), vec.end(), [](int i) {cout << i << " "; });
	cout << endl;

	system("pause");
	return 0;
}