#include <iostream>
using namespace std;

template <class T>
T MAX(T t1, T t2)
{
	return t1 > t2 ? t1 : t2;
}

int main()
{
	//��ʽʵ����
	cout << "The maximum of 1 and 2: " << MAX(1, 2) << endl;
	cout << "The maximun of 'a' and 'b': " << MAX('a', 'b') << endl;
	//��ʽʵ����
	//�����Ͳ���ֱ���ж�ʱ����Ҫ�ֶ�ָ���ö��ı�׼
	cout << "The maximum of 1 and 'a': " << MAX<int>(1, 'a') << endl;

	system("pause");
	return 0;
}