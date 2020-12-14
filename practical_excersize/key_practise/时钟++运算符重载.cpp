#include <iostream>
#include <cmath>
using namespace std;

//注意前缀++和后缀++的区别
//后缀++因为在语句中是先运算后++，所以先返回原始对象的深拷贝用于运算
//同时原始对象++，所以从外围看就是先运算，后++
class Clock
{
private:
	int hour, minute, second;
public:
	Clock(int h = 0, int m = 0, int s = 0) :hour(h), minute(m), second(s) {};
	void showTime();
	Clock& operator++();
	Clock operator++(int);
};

void Clock::showTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

//前缀++运算符
Clock& Clock::operator++()
{
	second++;
	if (second >= 60)
	{
		second = 0;
		minute++;
		if (minute >= 60)
		{
			minute = 0;
			hour++;
			if (hour >= 24) hour = 0;
		}
	}
	return *this;
}

//重载++后缀运算符
//需要保持后缀++运算符后于其他运算计算的特征
Clock Clock::operator++(int)
{
	Clock old = *this;
	++(*this);
	return old;//返回原始的没有++的时钟对象的拷贝，原始对象仍然++，二者不冲突
}

int main()
{
	Clock myClock(23, 59, 59);
	cout << "初始化显示时间为：\t\t";
	myClock.showTime();

	(++myClock).showTime();
	(myClock++).showTime();
	myClock.showTime();

	system("pause");
	return 0;
}