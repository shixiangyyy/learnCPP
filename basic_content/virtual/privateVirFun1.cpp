//�麯�����Ա�˽�л���������Ҫע��һЩϸ�ڣ�
//����ָ��ָ��̳����������õ��Ǽ̳���ĺ�����
//���Ҫ��main������������麯������ָ����ָ�����Ļ�������Ҫ�ڻ�����������mainΪ��Ԫ
//���߽�������ʿ�����Ϊpublic��������������Ϊprivate����publicҲ��
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void fun() { cout << "Base virtual function." << endl; }
	//friend int main();//���뽫main��������Ϊbase����Ԫ����Ȼ�����޷�����fun
};

class Derived : public Base
{
public:
	void fun() { cout << "Derived virtual function." << endl; }
};

int main()
{
	Base* ptr = new Derived;
	ptr->fun();//ָ��ָ����ǻ��࣬���Ե��ú���ʱ����Ȼʱ�麯�������ǻ����麯����private���ʿ��ƻ��ǻ�ʹ�ñ���������

	system("pause");
	return 0;
}