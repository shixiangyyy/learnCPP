#include <iostream>
using namespace std;

class Clock
{
public:
	Clock(int h, int m, int s) :H(h), M(m), S(s) {};
	~Clock() {};
	Clock(Clock& c);
	void operator()(int H, int M, int S);
	void operator++();
	void showTime();
	void setTime(int H, int M, int S);
private:
	int H, M, S;
};

Clock::Clock(Clock& c)
{
	this->H = c.H;
	this->M = c.M;
	this->S = c.S;
}

void Clock::operator()(int H, int M, int S)
{
	this->H = H;
	this->M = M;
	this->S = S;
}

void Clock::operator++()
{
	if (++this->S == 60)
	{
		this->S = 0;
		if (++this->M == 60)
		{
			this->M = 0;
			if (++this->H == 24)
			{
				this->H = 0;
			}
		}
	}
}

void Clock::showTime()
{
	cout << this->H << ":" << this->M << ":" << this->S << endl;
}

void Clock::setTime(int H, int M, int S)
{
	this->H = H;
	this->M = M;
	this->S = S;
}

int main()
{
	Clock c(23, 59, 59);
	c.showTime();
	++c;
	c.showTime();
	c.operator()(0, 0, 0);
	c.showTime();
	c(10, 10, 10);
	c.showTime();
	c.setTime(5, 5, 5);
	c.showTime();

	system("pause");
	return 0;
}