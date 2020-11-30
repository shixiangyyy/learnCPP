#include <iostream>
using namespace std;

class Base
{
public:
	Base(int i) :crt(i) {};
	int getCRT() { return crt; }
	void base() {};
protected:
	void changeCRT(int i) { crt = i; };
	void basepro() {};
private:
	int crt;
};

class derpub :public Base
{
public:
	derpub(int i, int b) :crt(i), Base(b) { cout << "derpub constructed." << endl; }
	int getCRT() { return crt; };
	int getBaseCRT()
	{
		//return Base::crt;//error,����˽�г�Ա������ֱ�ӷ���
		return Base::getCRT();//OK,����ͨ�����๫�г�Ա��������
	}
	void change(int i) { changeCRT(i); } //����ͨ��������ù��к������ñ��
protected:
	void changeCRT(int i) { crt = i; } //�����в�����ֱ�ӵ���
private:
	int crt;
};

class derpro :protected Base
{
public:
	derpro(int i, int b) :crt(i), Base(b) { cout << "derpro constructed." << endl; }
	int getCRT() { return crt; };
	int getBaseCRT()
	{
		//return Base::crt;//error,����˽�г�Ա������ֱ�ӷ���
		return Base::getCRT();//OK,����ͨ�����๫�г�Ա��������
	}
	void change(int i) { changeCRT(i); } //����ͨ��������ù��к������ñ��
protected:
	void changeCRT(int i) { crt = i; } //�����в�����ֱ�ӵ���
private:
	int crt;
};

class derpri : private Base
{
public:
	derpri(int i, int b) :crt(i), Base(b) { cout << "derpri constructed." << endl; }
	int getCRT() { return crt; };
	int getBaseCRT()
	{
		//return Base::crt;//error,����˽�г�Ա������ֱ�ӷ���
		return Base::getCRT();//OK,����ͨ�����๫�г�Ա��������
	}
	void change(int i) { changeCRT(i); } //����ͨ��������ù��к������ñ��
protected:
	void changeCRT(int i) { crt = i; } //�����в�����ֱ�ӵ���
private:
	int crt;
};

int main()
{
	//public�̳�
	derpub dpub(1, 2);
	dpub.base();//OK������ͨ�������������û��๫�к���
	//dpub.basepro();//ERROR,����protected��Ա��������������������
	dpub.change(5);
	cout << dpub.getBaseCRT() << endl;
	//dpub.changeCRT();//ERROR,protected��Ա�ڶ����в��ɷ���
	cout << dpub.getCRT() << endl;

	//protected�̳�
	derpro dpro(10, 100);
	cout << dpro.getCRT() << endl;
	cout << dpro.getBaseCRT() << endl;
	//dpro.base();//ERROR�����ܵ��û���public��Ա����Ϊ���������̳����Ա�Ϊprotected
	//dpro.basepro();//ERROR,��Ϊprotected
	dpro.change(1000);
	cout << dpro.getCRT() << endl;

	//private�̳�
	derpri dpri(1000, 10000);
	//dpri.base();//ERROR,���û���public��Ա
	cout << dpri.getCRT() << endl;
	cout << dpri.getBaseCRT() << endl;

	system("pause");
	return 0;
}