//设计一个字符串类String，通过运算符重载实现字符串的：
//输入、输出、以及+=、==、!=、!、<、>、>=、[]等运算
#include <iostream>
#include <cstring>
using namespace std;

class String
{
	int len;
	char* sptr;
	void setString(const char*);
	friend istream& operator >> (istream& is, String& s);
	friend ostream& operator << (ostream& os, const String& s);
public:
	String(const char* cs = "");
	const String& operator =(const String& s);
	const String& operator += (const String& s);
	bool operator == (const String& s);
	bool operator != (const String& s);
	bool operator ! ();
	bool operator < (const String& s);
	bool operator > (const String& s);
	bool operator >= (const String& s);
	bool operator <= (const String& s);
	bool operator <= (const String& s) const;
	char& operator [] (int n);
	~String();
};

void String::setString(const char* s)
{
	const char* temp = s;
	this->len = strlen(s);
	this->sptr = const_cast<char*>(temp);
	delete[] temp;
}

String::String(const char* cs)
{
	this->len = strlen(cs);
	this->sptr = new char[this->len + 1];
	strcpy(this->sptr, cs);
}

String::~String() { delete[] sptr; }

const String& String::operator = (const String& s)
{
	this->len = s.len;
	this->sptr = s.sptr;
	return *this;
}

const String& String::operator+=(const String& s)
{
	char* temp = sptr;
	this->len += s.len;
	sptr = new char[len + 1];
	strcpy(sptr, temp);
	strcat(this->sptr, s.sptr);
	delete[] temp;
	return *this;
}

istream& operator >> (istream& is, String& s) { return is >> s.sptr; }

ostream& operator << (ostream& os, const String& s) { return os << s.sptr; }

bool String::operator==(const String& s) { return strcmp(this->sptr, s.sptr) == 0; }

bool String::operator!=(const String& s) { return !(sptr == s.sptr); }

bool String::operator!() { return this->len == 0; }

bool String::operator<(const String& s){ return strcmp(this->sptr, s.sptr) < 0; }

bool String::operator<=(const String& s) { return strcmp(sptr, s.sptr) <= 0; }

bool String::operator<=(const String& s) const { return strcmp(sptr, s.sptr) <= 0; }

bool String::operator>(const String& s) { return strcmp(sptr, s.sptr) > 0; }

bool String::operator>=(const String& s) { return strcmp(sptr, s.sptr) >= 0; }

char& String::operator[](int n) { return *(sptr + n); }

int main()
{
	String s1("Xiang Shi"), s2("Xiao Ye Zi"), s3;
	cout << "s1 is: " << s1 << "\ns2 is: " << s2 << "\ns3 is: " << s3
		<< "\n比较s1和s2:"
		<< "\ns2 == s1结果是 " << (s2 == s1 ? "true" : "false")
		<< "\ns2 != s1结果是 " << (s2 != s1 ? "true" : "false")
		<< "\ns2 >= s1结果是 " << (s2 >= s1 ? "true" : "false")
		<< "\ns2 <= s1结果是 " << (s2 <= s1 ? "true" : "false");
	cout << "\n\n测试s3是否为空：" << std::endl;
	if (!s3)
	{
		cout << "s3是空串" << std::endl;
		cout << "把s1赋值给s3结果是："
			<< (s3 = s1) << endl;
		cout << "s3 = " << s3 << endl;
	}
	cout << ("s1 += s2结果是：")
		<< (s1 += s2) << endl;
	cout << "s1 += to you的结果是："
		<< (s1 += "to you") << endl;
	cout << "s1 = " << s1 << endl;
	s1[0] = 'H';
	s1[1] = 'N';
	s1[2] = 'W';
	cout << "s1 = " << s1 << endl;

	system("pause");
	return 0;
}