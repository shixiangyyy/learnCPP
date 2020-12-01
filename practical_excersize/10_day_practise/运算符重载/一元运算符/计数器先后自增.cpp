//重载一个计数器counter，用类成员重载自增运算符实现计数器的自增，用友元重载实现计数器的自减
#include <iostream>
using namespace std;

class Counter
{
private:
	int count;
public:
	Counter(int i = 0) :count(i) {};
	void getCount() { cout << count << endl; }
	Counter operator++();//前缀
	Counter operator++(int);//后缀
	friend Counter operator--(Counter& c);//前缀
	friend Counter operator--(Counter& c, int);//后缀
};

Counter Counter::operator++()
{
	count++;
	return *this;
}

Counter Counter::operator++(int)
{
	count++;
	return *this;
}

Counter operator--(Counter& c)
{
	c.count--;
	return c;
}

Counter operator--(Counter& c, int)
{
	c.count--;
	return c;
}

int main()
{
	Counter c1;
	c1++;
	c1.getCount();
	++c1;
	c1.getCount();
	--c1;
	c1.getCount();
	c1--;
	c1.getCount();

	system("pause");
	return 0;
}
