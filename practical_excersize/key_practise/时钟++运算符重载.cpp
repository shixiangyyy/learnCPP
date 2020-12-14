#include <iostream>
#include <cmath>
using namespace std;

//ע��ǰ׺++�ͺ�׺++������
//��׺++��Ϊ����������������++�������ȷ���ԭʼ����������������
//ͬʱԭʼ����++�����Դ���Χ�����������㣬��++
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

//ǰ׺++�����
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

//����++��׺�����
//��Ҫ���ֺ�׺++�������������������������
Clock Clock::operator++(int)
{
	Clock old = *this;
	++(*this);
	return old;//����ԭʼ��û��++��ʱ�Ӷ���Ŀ�����ԭʼ������Ȼ++�����߲���ͻ
}

int main()
{
	Clock myClock(23, 59, 59);
	cout << "��ʼ����ʾʱ��Ϊ��\t\t";
	myClock.showTime();

	(++myClock).showTime();
	(myClock++).showTime();
	myClock.showTime();

	system("pause");
	return 0;
}