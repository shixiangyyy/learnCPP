#include <iostream>

//::ð�ŷ�Χ���������
//:: ȫ�������������ʾ������Ϊȫ�������ռ�
//class::name����ʾ��������Χ
//namespace::name����ʾ�����ռ��ڲ�������Χ

int count = 1;

class A
{
public:
	static int count;
};

int A::count = 2;

int main()
{
	::count = 0;
	A::count = 5;
	std::cout << "Global count: " << ::count << std::endl;
	std::cout << A::count << std::endl;

	system("pause");
	return 0;
}