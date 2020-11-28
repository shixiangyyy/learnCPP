#include "copyCon.h"

Clock::Clock(Clock& c)
{
	this->H = c.H;
	this->M = c.M;
	this->S = c.S;
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
	Clock c(0, 0, 0);
	c.setTime(22, 56, 22);
	c.showTime();
	Clock c1(c);
	c.showTime();

	system("pause");
	return 0;
}