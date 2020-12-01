//设计一个时间类Time,它能够完成秒钟的自增运算
#include <iostream>
using namespace std;

class Time
{
private:
	int hour, minu, seco;
public:
	Time(int h, int m, int s);
	void display();
	Time operator++();
	friend Time operator--(Time& t);
};

Time::Time(int h, int m, int s)
{
	hour = h; minu = m; seco = s;
	if (hour >= 24) hour = 0;
	if (minu >= 60) minu = 0;
	if (seco >= 60) seco = 0;
}

void Time::display()
{
	cout << hour << ":" << minu << ":" << seco << endl;
}

Time Time::operator++()
{
	seco++;
	if (seco >= 60)
	{
		seco = 0;
		if (++minu >= 60)
		{
			minu = 0;
			if (++hour >= 24)
				hour = 0;
		}
	}
	return *this;
}

Time operator--(Time& t)
{
	--t.seco;
	if (t.seco >= 60) {
		t.seco = 0;
		++t.minu;
		if (t.minu >= 60) {
			t.minu = 0;
			++t.hour;
			if (t.hour >= 24)
				t.hour = 0;
		}
	}
	return t;
}

int main()
{
	Time t1(23, 59, 59);
	t1.display();
	++t1; //隐式调用
	t1.display();
	t1.operator++(); //显式调用，把operator@()整体当作一个函数使用
	t1.display();
	--t1;
	t1.display();

	system("pause");
	return 0;
}

