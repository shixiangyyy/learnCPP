#include <iostream>
using namespace std;

struct Base
{
private:
	int v1;
	int v2;
public:
	int v3;
	virtual void print()
	{
		cout << "Hello world!" << endl;
	};
};

struct Derived :public Base
{
public:
	int v4;
	void print()
	{
		cout << "Hello world in derived!" << endl;
	}
};

int main()
{
	Base* bptr = new Derived();
	bptr->print(); //�������virtual����print���������õ���base��print����
	//��print����Ϊ�麯����ǰ���£����õ����������print����
	system("pause");
	return 0;
}