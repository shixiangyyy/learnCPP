#include <iostream>
using namespace std;

class R
{
public:
	R(int r1, int r2) :R1(r1), R2(r2) {};
	void print();
	void print() const;//������
private:
	int R1, R2;
};

void R::print()
{
	cout << "��ͨ����" << endl;
	cout << R1 << " " << R2 << endl;
}


//��������Ĭ�ϳ��������
//const�Ǻ������͵�һ����ɲ��֣������ʵ�ֲ���ҲҪ��osnt�ؼ���
//const�ؼ��ֿ��Ա����ڲ�������غ���������
//ͨ��������ֻ�ܵ������ĳ���Ա����(���ñ�����޸Ķ����Ա��Σ��)
void R::print() const
{
	cout << "������������" << endl;
	//R1++; //��ʾR1��read-only���ͣ������Խ����޸ģ���ΪĬ�ϳ������ǳ��������
	//R2++;
	cout << R1 << " " << R2 << endl;
}

int main()
{
	R a(5, 4);
	a.print();

	const R b(8, 9);
	b.print();

	system("pause");
	return 0;
}