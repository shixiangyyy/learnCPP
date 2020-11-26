//ʹ��C++dynamic_castʵ��RTTI��RunTime Type Identification
#include <iostream>
#include <typeinfo>
using namespace std;

class B { virtual void fun() {}; };
class D:public B{};

int main()
{
	B* b = new D; //����ת��
	B& obj = *b;
	D *d = dynamic_cast<D*>(b); //����ת�ͣ�����ת�Ͳ�һ���ܳɹ�
	if (d != NULL)
		cout << "works!" << endl;
	else
		cout << "Cannot cast B* to D*!" << endl;

	try
	{
		D& dobj = dynamic_cast<D&>(obj);
		cout << "Works!" << endl;
	}
	catch (bad_cast bc)
	{
		cout << bc.what() << endl;
	}

	system("pause");
	return 0;
}