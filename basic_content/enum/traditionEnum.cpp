#include <iostream>
using namespace std;

//enum Color{ RED, BLUE };
//
//enum Feeling { EXCITED, BLUE };//�ض���

//���������ռ���Ա���ö��������ͻ
namespace Color
{
	enum Type
	{
		RED = 15,
		YELLOW, //Ĭ��16
		BLUE //Ĭ��17
	};
}

namespace Feeling
{
	enum  Feel
	{
		EXCITED,
		BLUE
	};
}

int main()
{
	Color::Type c = Color::BLUE;//17
	Feeling::Feel f = Feeling::BLUE;
	return 0;
}