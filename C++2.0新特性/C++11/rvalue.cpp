#include <iostream>
#include <complex>
using namespace std;

int foo() { return 5; }

//rvalue references����Ǳ�Ҫ�Ŀ���
//����ֵ���ֱ���һ������ֵ�������ֱ߶������͵���ֱ߶���
//������Ҫ���·����ڴ棬ǳ����
class Foo
{
public:
	Foo() = default;
	Foo(const Foo& foo) = default;
	Foo(Foo&& foo)noexcept {};
};

//�ж����������ֵ������ֵ
void process(int& i) { cout << "��ֵ����" << endl; }
void process(int&& i) { cout << "��ֵ����" << endl; }

void UnPerfectForward(int&& i)
{
	cout << "forward(int&& i)" << endl;
	process(i);
}

void PerfectForward(int&& i)
{
	//��Ϊ��ʱ����i��������Ҫ������ʽ����ת��Ϊint&&����
	cout << "forward(int&& i)" << endl;
	process(static_cast<int&&>(i));
}

//Lvalue:����
//Rvalue:��ʱ������Ǹ���ֵ����ֵ�����Է����

int main()
{
	string s1("hello");
	string s2("world");
	s1 + s2 = s2;//ok
	string() = "ok";//ok
	//˵��string��ʵ������ֵ���ܣ�����+ʱӦ���з�����ֵ
	cout << "s1+s2:" << s1 + s2 << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	//���Ƶ���complex�࣬��׸��

	int x = foo();
	//    int *p=&foo(); //error!  Rvalue������ȡ��ַ
	//    foo()=7;  // error
	// Rvalue references
	//    vector<Foo> vec;
	//    vec.insert(vec.begin(), Foo());  // Rvalue references and Move Semantics
	//  ԭ�����������
	//  iterator insert(const_iterator __position, const value_type& __x);
	// �����������Move Semantics
	//  iterator insert(const_iterator __position, value_type&& __x) 
	//  { return emplace(__position, std::move(__x)); }
	// Foo()�����ʱ����Ϊ��ֵ����insert��move assignmentȻ���ٽ���Foo��move ctor

	int a = 1;
	process(a); //L
	process(1); //R
	process(move(a)); //R��ͨ��move��������ֵתΪ��ֵ
	UnPerfectForward(2); //L
	UnPerfectForward(move(a)); //L,��Ϊ��������ʱ����
	PerfectForward(2); //R
	PerfectForward(move(a)); //R

	system("pause");
	return 0;
}