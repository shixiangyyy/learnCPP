//ʹ��dynamic_castʵ��RTTI��Ҫע����ǣ���ת������obj������T1�����Ƕ�̬���ͣ������빫�м̳���������(ע�⹫�м̳�)������T1ӵ���麯��
//��T1Ϊ�Ƕ�̬���ͣ�ʹ��dynamic_cast�ᱨ��

//�Ƕ�̬
class A 
{

};

//��̬
class B
{
public:
	virtual ~B() {};
};

//��̬���ͣ����м̳���������
class D :public A
{

};

//�Ƕ�̬��˽�м̳У���˲��Ƕ�̬����
class E :private A
{

};

//��̬��˽�м̳У�����B�����麯��
class F :private B
{

};