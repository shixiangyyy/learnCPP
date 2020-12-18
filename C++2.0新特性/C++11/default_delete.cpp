#include <iostream>
using namespace std;

//=default����big-five֮��û�����壬����ᱨ��
//=delete�������κκ������ϣ�(=0ֻ�����ڴ�virtual����)��=delete��=0û��ϵ

class Foo
{
	int _i;
public:
	//ctor
	Foo(int i) :_i(i) { cout << "with param ctor.\n"; };
	Foo() = default; //����һ�����棬ctor���Զ������

	//copy ctor,ֻ����һ��
	Foo(const Foo& x) :_i(x._i) {};
	//Foo(const Foo&) = default; //Error�����ܴ��ڣ���Ϊ�Ѿ����ڴ�copy ctor
	//Foo(const Foo&) = delete; //Error�����ܴ��ڣ��Ѿ�������copy ctor��������=delete
	//use of deleted function Foo::Foo(const Foo&)

	Foo(Foo&&) = default; //move ctor

	//copy assignment ctor,ֻ����һ��
	Foo& operator=(const Foo& x) = default;
	//Foo& operator=(const Foo& x) = default; //Error
	//Foo& operator=(const Foo& x) = delete; //Error
	//use of deleted function Foo& Foo::operator=(const Foo&)
	Foo& operator=(const Foo&& x) = delete;

	//void fun1() = default;//Error,��ͨ����������default
	void fun1() = delete;//Ok,��ͨ��������delete,����ûɶ����

	~Foo() = default;
	//~Foo() = delete; // Error��������ʹ��Foo objectʱ����
	//use of deleted  function Foo::~Foo()
}; 

class Empty{};
//�ȼ��� �����������ĵ�Ĭ�ϰ汾��������public��inline��
class Empty1
{
public:
	Empty1() {};
	Empty1(const Empty1& rhs) {};
	~Empty1() {};
};

struct NoCopy
{
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;//���ÿ���
	NoCopy& operator=(const NoCopy&) = delete;//���ÿ���
	~NoCopy() = default;
};

struct NoDtor
{
	NoDtor() = default;
	~NoDtor() = delete;//��������
};

//��NoCopy���иĽ�����copy ctor��copy assignment�Ž�private
//����ⲿ�����ܽ��п�����ֵ�����ǿ���ͨ��friend��members����
//boost::noncopyable���õ���privatecopy
class PrivateCopy
{
private:
	PrivateCopy(const PrivateCopy&) {};
	PrivateCopy& operator=(const PrivateCopy&) {};
public:
	PrivateCopy() = default;
	~PrivateCopy() = default;
};

class Zoo :public PrivateCopy {};

int main()
{
	Foo f;
	Foo f1(1);
	f = f1;

	Zoo zoo;
	Zoo zoo1;
	//zoo = zoo1;//�̳��˶�ӵ��privateCopy�����ʣ��ⲿ�����ܽ��п�����ֵ
	//����friend��members����

	//NoDtor nd; //error. NoDtor dtor is deleted
	//NoDtor* p = new NoDtor(); //Ok, but we can't delete p
	//delete p; //Error, NoDtor dtor is deleted

	system("pause");
	return 0;

}