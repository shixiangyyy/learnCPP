//�����Circle, ��Ƹ��������ת����������circle����ת����int��ʱ
//����Բ�İ뾶����ת����double����ʱ������Բ���ܳ���
//����Circleת����float��ʱ���ͷ���Բ�����
#include <iostream>
using namespace std;

class Circle
{
private:
	double x, y, r;
public:
	Circle(double x, double y, double r) :x(x), y(y), r(r) {};
	//��������أ�ǿ������ת��
	operator int() { return int(r); }
	operator double() { return double(2 * r * 3.14); }
	operator float() { return float(3.14 * r * r); }
};

int main()
{
	Circle c(2.4, 3.4, 2.5);
	int r = c;
	double length = c;
	float area = c;
	double len = (double)c;

	cout << r << endl;
	cout << length << endl;
	cout << len << endl;
	cout << area << endl;

	system("pause");
	return 0;
}