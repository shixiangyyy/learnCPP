#include <iostream>
using namespace std;

//union��һ�ֽ�ʡ�ռ���������
//Ĭ�Ϸ��ʿ���Ϊpublic
//���������������͹��캯��
//������������ĳ�Ա�����ڴ棬��˲��ܺ��о�̬���������ͳ�Ա
//�������治���д��й��졢�������������캯�����࣬��Ϊ���ǹ����ڴ棬�������޷���֤��Щ���󲻱��ƻ���Ҳ�޷���֤�뿪ʱ��ȷ������������
//���ܰ�����
//���ܼ̳��뱻�̳�
//���ܺ����麯��
//����union�ڶ������ڵ����������ֱ�ӷ���union��Ա
//�������ϲ����԰���protected��Ա����private��Ա
//ȫ���������ϱ����Ǿ�̬static�ģ�����ͱ�������������ֿռ���
//�������ϲ�ʹ�õ�����������԰��������������ڵ����ݱ��������ݣ����������Ա������Ҳ���ܰ���˽�С������ĳ�Ա

union UnionTest
{
	//Ĭ��public
	int i;
	UnionTest() :i(10) { print(i); };
	~UnionTest() {};
private:
	void print(int i) { cout << i << endl; };
};

//ȫ���������ϣ�������static
//������:namespace-scope anonymous aggregates�����ϣ� must be static
static union
{
	int i;
	double d;
};

int main()
{
	UnionTest ut;

	//�ֲ���������
	union
	{
		//����main�����������򣬲��ܳ�ͻ
		int i;
		double d;
	};

	cout << ut.i << endl;

	//ȫ����������
	::i = 20;
	cout << ::i << endl;

	//�ֲ���������
	i = 30;
	cout << i << endl;

	system("pause");
	return 0;
}