//noexcept()�п��Լ�����
//�쳣���Դ���
//�쳣�Ļش����ƣ�����foo����׳��쳣��foo����������׳�
//������ϲ�û�д�����쳣����ô�����std::terminate()
//terminate()�����ڲ�����abort(),������ֹ����

//��ʹ��vector��deque��������ʱ��C++2.0�д��ڵġ�move assignment��
//�͡�move copy�����ƣ�����ƶ�������ƶ���ֵû�м���noexcept
//�򵱷���ע��vector�������·���ռ�ʱ�����������move ctor����move
//assignment�������ò���C++2.0�ƶ�������ƶ���ֵ�ĸ�Ч��
//����������Զ����������ͺ������noexcept���Ը���vector������ģ��
//���ƶ���ֵ�����ƶ����첻���׳��쳣�������ʹ��

#include <iostream>
#include <vector>
using namespace std;

void foo()noexcept(true){}

int main()
{
	foo();
	vector<int> vec;
	return 0;
}