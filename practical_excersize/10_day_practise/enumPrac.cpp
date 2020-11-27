#include <iostream>
using namespace std;

//内部成员具有外部作用域
//注意将结构体、类、命名空间结合起来控制枚举类型的作用域
typedef enum
{
	s, m, t, w, thu, f, sat
}WEEKDAY;

int main()
{
	WEEKDAY week = s;
	for (int i = week; i != WEEKDAY::sat; i++)
	{
		cout << i << endl;
		cout << week + s << endl;
		cout << "game over!" << endl;
	}

	system("pause");
	return 0;
}