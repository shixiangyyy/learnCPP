#include <iostream>
#include <algorithm>
using namespace std;

//�ڵ���initializer_list˽�й���֮ǰ
//������׼����arrayͷ��len�����ݸù���
//ָ��ֻ��ָ��array��ֻ��ǳ����
//���������������������������ֵ��insert����assign

//The initializer_list object refers to the elements
//of this array without containing them:copying a 
//initializer_list object produces another object referring
//to the same underlying elements, but not to new copies of them

//ע����һ�λ�˵��refer to,ָ��ָ����ʽ��ָ�򣬶�����������ݸ���

void print(int a, int b)
{
	cout << "print(int, int), a = " << a << ",b = " << b << endl;
}

template <typename T>
void print(initializer_list<T> vals)
{
	for (const auto p:vals) cout << p << "\n";
}

int main()
{
	int i; //û�г�ʼ��,�������Ϊ0�����ܸ��������й�
	int j{}; //c��ʼ��Ϊ0
	int* p; //p��ֵδ����
	int* q{}; //Ĭ�϶���Ϊnullptr

	cout << i << endl; //0
	cout << j << endl; //0
	cout << p << endl; //0x8
	cout << q << endl; //0

	cout << max({ 1,2,3,4 }) << endl;
	print({ 's', 'i','x' });

	//��ͬʱ���ھ������͵ĺ����Լ�����Ϊinitializer_list���͵�ͬ������ʱ
	//����initializer_list�İ汾����
	print(1, 2);
	print({ 1,2 });

	system("pause");
	return 0;
}