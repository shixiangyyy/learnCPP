#include <iostream>
using namespace std;

//ͨ�������鹹�������û����޷���ʵ������ֻ��ͨ������ʵ����ʵ�ֽӿ�
//��������OK����Ϊ��������������ʵ��
//�����麯����Ĭ��ʵ�֣��������������������в������塱
class Abs
{
public:
	virtual ~Abs() = 0
	{
		cout << "~Abs" << endl;//���Բ����о������
	}
};

class interfAbs:public Abs
{

};

int main() {
	interfAbs* p = new interfAbs;
	delete p;
	Abs* p2 = new interfAbs;
	delete p2;

	return 0;
}

//�������뷢������ʱ���⣬����˵�Ҳ���Abs����������ʵ��
//ԭ����Abs�Ĵ��麯���Ǵ���ģ���ָ��?
//�����������һ�δ��룬ͨ����������������ʵ�֣�ʹ�ü���˸���Ĳ���ʵ�������Լ��ӿ��߼���ʵ��
//class Abs
//{
//public:
//	virtual ~Abs() = 0;
//};
//
//class interfAbs :public Abs
//{
//
//};
//
//int main() {
//	interfAbs* p = new interfAbs;
//	delete p;
//	Abs* p2 = new interfAbs;
//	delete p2;
//
//	return 0;
//}