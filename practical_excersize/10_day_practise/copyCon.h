#ifndef copyCon
#define copyCon
#include <iostream>
using namespace std;

class Clock
{
public:
	Clock(int NewH, int NewM, int NewS) :H(NewH), M(NewM), S(NewS) {};
	Clock(Clock& c);//¿½±´¹¹Ôìº¯Êý
	void showTime();
	void setTime(int NewH, int NewM, int NewS);
	~Clock() {};
private:
	int H, M, S;
};

#endif // !copyCon
