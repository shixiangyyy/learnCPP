//����һ��������counter�������Ա�������������ʵ�ּ�����������������Ԫ����ʵ�ּ��������Լ�
#include <iostream>
using namespace std;

class Counter
{
private:
	int count;
public:
	Counter(int i = 0) :count(i) {};
	void getCount() { cout << count << endl; }
	Counter operator++();//ǰ׺
	Counter operator++(int);//��׺
	friend Counter operator--(Counter& c);//ǰ׺
	friend Counter operator--(Counter& c, int);//��׺
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
