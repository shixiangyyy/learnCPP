#include <iostream>
using namespace std;

//������ֱ���޸ĳ���ָ��ָ���ֵ�����ǿ���ͨ��������ָ���޸���ָ���ֵ
int main()
{
	const int* ptr;
	//*ptr = 3;//error,���ʽ�����ǿ��޸���ֵ
	int val = 3;
	ptr = &val;
	//*ptr = 100;//error,���ʽ�����ǿ��޸���ֵ
	int* ptr1 = const_cast<int*>(ptr);//ͨ��ptr1����ȥ��
	*ptr1 = 100;
	cout << *ptr << endl;
	int* ptr2 = &val;
	*ptr2 = 200;//ok
	cout << *ptr << endl; //100
	cout << *ptr1 << endl;
	system("pause");
	return 0;
}