#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <typeinfo>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
using namespace std;

class MyStringNoMove
{
public:
	static size_t DCtor; //defaut ctor
	static size_t Ctor;
	static size_t CCtor; //copy ctor
	static size_t CAsgn; //copy assignment
	static size_t MCtor; //move ctor
	static size_t MAsgn; //move assignment
	static size_t Dtor;
private:
	char* str;
	size_t _len;
	void _init_data(const char* s)
	{
		str = (char*)malloc((_len + 1) * sizeof(char));
		strcpy(str, s);
		str[_len] = '\0';
	}
public:
	MyStringNoMove() :str(NULL), _len(0) { ++DCtor; } //default
	MyStringNoMove(const char* cp) :_len(strlen(cp)) //ctor
	{
		++Ctor;
		_init_data(cp);
	}
	MyStringNoMove(const MyStringNoMove& cp) //copy ctor
	{
		++CCtor;
		_len = cp._len;
		_init_data(cp.str);
	}
	MyStringNoMove& operator=(MyStringNoMove& cp)//copy assignment
	{
		++CAsgn;
		if (this != &cp)
		{
			if (str) delete str; //清除原始指针，防止内存泄漏
			_len = cp._len;
			_init_data(cp.str);
		}
		return *this;
	}
	~MyStringNoMove() {
		++Dtor;
		if (str) delete str;
	}
	bool operator<(const MyStringNoMove& tocmp) const
	{
		return strcmp(str, tocmp.str) < 0;
	}
	bool operator==(const MyStringNoMove& tocmp) const
	{
		return strcmp(str, tocmp.str) == 0;
	}
	char* getStr()const
	{
		return str;
	}
};

//类的静态数据成员必须在类外进行初始化
size_t MyStringNoMove::DCtor = 0; //defaut ctor
size_t MyStringNoMove::Ctor = 0;
size_t MyStringNoMove::CCtor = 0; //copy ctor
size_t MyStringNoMove::CAsgn = 0; //copy assignment
size_t MyStringNoMove::MCtor = 0; //move ctor
size_t MyStringNoMove::MAsgn = 0; //move assignment
size_t MyStringNoMove::Dtor = 0;

class MyString
{
public:
	static size_t DCtor; //defaut ctor
	static size_t Ctor;
	static size_t CCtor; //copy ctor
	static size_t CAsgn; //copy assignment
	static size_t MCtor; //move ctor
	static size_t MAsgn; //move assignment
	static size_t Dtor;
private:
	char* str;
	size_t _len;
	void _init_data(const char* s)
	{
		str = (char*)malloc((_len + 1) * sizeof(char));
		strcpy(str, s);
		str[_len] = '\0';
	}
public:
	MyString() :str(NULL), _len(0) { ++DCtor; } //default
	MyString(const char* cp) :_len(strlen(cp)) //ctor
	{
		++Ctor;
		_init_data(cp);
	}
	MyString(const MyString& cp) //copy ctor
	{
		++CCtor;
		_len = cp._len;
		_init_data(cp.str);
	}
	MyString& operator=(MyString& cp)//copy assignment
	{
		++CAsgn;
		if (this != &cp)
		{
			if (str) delete str; //清除原始指针，防止内存泄漏
			_len = cp._len;
			_init_data(cp.str);
		}
		return *this;
	}
	MyString(MyString&& cp)noexcept :_len(cp._len), str(cp.str)//move ctor
	{
		++MCtor;
		cp._len = 0;
		cp.str = nullptr;
	}
	MyString& operator=(MyString&& cp) //move assignment
	{
		++MAsgn;
		if (this != &cp)
		{
			if (str) delete str;
			str = cp.str;
			_len = cp._len;
			cp._len = 0;
			cp.str = nullptr;
		}
		return *this;
	}
	~MyString() {
		++Dtor;
		if (str) delete str;
	}
	bool operator<(const MyString& tocmp) const
	{
		return strcmp(str, tocmp.str) < 0;
	}
	bool operator==(const MyString& tocmp) const
	{
		return strcmp(str, tocmp.str) == 0;
	}
	char* getStr()const
	{
		return str;
	}
};

size_t MyString::DCtor = 0; //defaut ctor
size_t MyString::Ctor = 0;
size_t MyString::CCtor = 0; //copy ctor
size_t MyString::CAsgn = 0; //copy assignment
size_t MyString::MCtor = 0; //move ctor
size_t MyString::MAsgn = 0; //move assignment
size_t MyString::Dtor = 0;

//抄
namespace std
{
	template<>
	struct hash<MyStringNoMove> :public  _Bitwise_hash<MyStringNoMove>
	{
		size_t operator()(const MyStringNoMove& s) const noexcept
		{
			return hash<string>()(string(s.getStr()));
		}
	};

	template<>
	struct hash<MyString> :public _Bitwise_hash<MyString>
	{
		size_t operator()(const MyString& s) const noexcept
		{
			return hash<string>()(string(s.getStr()));
		}
	};
}

template<typename T>
void output_static_data(const T& mystr)
{
	//meta programming
	cout << typeid(mystr).name() << endl;
	cout << "CCtor=" << T::CCtor
		<< ",MCtor=" << T::MCtor
		<< ",CAsgn=" << T::CAsgn
		<< ",MAsgn=" << T::MAsgn
		<< ",Dtor=" << T::Dtor
		<< ",Ctor=" << T::Ctor
		<< ",DCtor=" << T::DCtor
		<< endl;
}

//抄
template<typename M, typename NM>
void test_moveable(M c1, NM c2, long &value) {
	cout << "\n\ntest, with moveable elements" << endl;
	typedef typename iterator_traits<typename M::iterator>::value_type V1type;
	clock_t timeStart = clock();
	for (long i = 0; i < value; i++) {
		string buf = to_string(i);
		auto ite = c1.end();
		c1.insert(ite, V1type(buf.c_str()));
	}
	cout << "construction,milli-seconds:" << clock() - timeStart << endl;
	cout << "size()=" << c1.size() << endl;
	output_static_data(*(c1.begin()));

	// 容器本身操作
	timeStart = clock();
	M c11(c1);
	cout << "copy, milli-seconds: " << (clock() - timeStart) << endl;
	timeStart = clock();
	M c12(move(c1));
	cout << "move copy, milli-seconds: " << (clock() - timeStart) << endl;
	timeStart = clock();
	c11.swap(c12);
	cout << "swap, milli-seconds: " << (clock() - timeStart) << endl;

	//測試 non-moveable
	cout << "\n\ntest, with non-moveable elements" << endl;
	typedef typename iterator_traits<typename NM::iterator>::value_type V2type;
	timeStart = clock();
	for (long i = 0; i < value; ++i) {
		string buf = to_string(i);
		auto ite = c2.end();
		c2.insert(ite, V2type(buf.c_str()));
	}

	cout << "construction, milli-seconds : " << (clock() - timeStart) << endl;
	cout << "size()= " << c2.size() << endl;
	output_static_data(*(c2.begin()));

	// 容器本身操作
	timeStart = clock();
	NM c21(c2);
	cout << "copy, milli-seconds : " << (clock() - timeStart) << endl;

	timeStart = clock();
	NM c22(std::move(c2));
	cout << "move copy, milli-seconds : " << (clock() - timeStart) << endl;

	timeStart = clock();
	c21.swap(c22);
	cout << "swap, milli-seconds: " << (clock() - timeStart) << endl;
}

int main() {
	long value = 30000;           
	// vector 测试结果的MCtor与CCtor结果大于3000000,是因为vector的动态扩容,当容量不够的时候,会动态分配并进行拷贝。	
	cout << "============TEST WITH VECTOR=============\n";
	test_moveable(vector<MyString>(), vector<MyStringNoMove>(), value);
	cout << "============TEST WITH LIST=============\n";
	test_moveable(list<MyString>(), list<MyStringNoMove>(), value);
	cout << "============TEST WITH DEQUE=============\n";
	test_moveable(deque<MyString>(), deque<MyStringNoMove>(), value);
	cout << "============TEST WITH MULTISET=============\n";
	test_moveable(multiset<MyString>(), multiset<MyStringNoMove>(), value);
	cout << "============TEST WITH UNORDERED_SET=============\n";
	test_moveable(unordered_multiset<MyString>(), unordered_multiset<MyStringNoMove>(), value);

	system("pause");
	return 0;
}