#include <iostream>
#include <vector>
using namespace std;

//����ͳһʹ�ô����Ž��б�����ʼ��
//������ô����ԭ���ǣ����������������Ű������б�״��
//������һ��initializer_list<T>,
//��������һ��array<T,n>
//���ú���ʱ����array�ڵ�Ԫ�ؿɱ��������ֽⲢ��һ���ݸ�����
//�������������Ǹ�initializer_list<T>
//������ȴ���ܸ�������T������Ȼ����Ϊ���ǻᱻ�Զ�תΪһ��initializer_list<T>
//����Ĭ�ϴ�����תΪinitializer_list<T>������ԭʼ�Ĳ�ҪҲ����������
int main()
{
	int values[]{ 1,2,3 };
	vector<int> v{ 2,3,3,45,53,45,2 };
	vector<string> cities{ "Beijing", "New york" };
	
	return 0;
}