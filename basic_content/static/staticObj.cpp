#include <iostream>
using namespace std;

class Apple
{
public:
	int i;
	Apple()
	{
		i = 0; 
		cout << "Inside Constructor!" << endl;
	}
	virtual ~Apple()
	{
		cout << "Inside Destructor!" << endl;
	}
};

int main()
{
	if (true)
	{
		//����staticʱ���������ڹ��졢������
		//Inside Constructor->Inside Destructor->End of main
		//Apple obj;
		//��staticʱ��������ᴩ�������������
		//Inside Constructor->End of main->Inside Destructor
		//ʵ������ʱ��û��Inside Destructor.ֱ��main������ֹ
		static Apple obj;
	}
	cout << "End of main." << endl;
	system("pause");
	return 0;
}
