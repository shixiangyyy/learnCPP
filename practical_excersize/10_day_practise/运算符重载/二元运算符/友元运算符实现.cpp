//���ڲ�Ҫ����ֵ�ҿ��Խ�����������������
//���ʹ�÷ǳ�Ա����ʽ(������Ԫ����ͨ����)���������������ʵ��
#include <iostream>

class complex
{
private:
	double r, i;
public:
	complex(double R = 0, double I = 0) :r(R), i(I) {};
	void display();
	//�����ͨ����Ԫ��ʽʵ����������أ���ô���ڶ�Ԫ�����Ӧ�ö�����ȫ������������
	//��Եأ���������������ʽ����ô���൱�ڸ���������ԭ���ض�Ԫ��ʽ����Ϊ����һԪ�������
	friend complex operator + (complex a, complex b);
	friend complex operator - (complex a, complex b);
	friend complex operator * (complex a, complex b);
	friend complex operator / (complex a, complex b);
	friend complex operator + (complex a, double b);
	friend complex operator + (double b, complex a);
};

void complex::display()
{
	std::cout << r << "+" << i <<"i" << std::endl;
}

complex operator + (complex a, complex b)
{
	return complex(a.r + b.r, a.i + b.i);
}

complex operator-(complex a, complex b)
{
	return complex(a.r - b.r, a.i - b.i);
}

complex operator*(complex a, complex b)
{
	return complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}

complex operator/(complex a, complex b)
{
	double mom = 1 / (b.r * b.r + b.i * b.i);
	return complex(mom * (a.r * b.r + a.i * b.i), mom * (a.i * b.r - a.r * b.i));
}

complex operator + (complex a, double b)
{
	return complex(a.r + b, a.i);
}

complex operator + (double b, complex a)
{
	return complex(a.r + b, a.i);
}

int main()
{
	complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
	complex a, b(5, 6);
	a = b + 2;//ok,�������Զ���2תΪcomplex���ͣ��ڼ����complex���캯����R��ֵΪ2��IΪĬ�ϵ�0
	a = 2 + b;//OK,��Ϊʵ���˶�+�Ŀɽ�������
	c3 = c1 + c2; c3.display();
	c4 = c1 - c2; c4.display();
	c5 = c1 * c2; c5.display();
	c6 = c1 / c2; c6.display();

	system("pause");
	return 0;
}