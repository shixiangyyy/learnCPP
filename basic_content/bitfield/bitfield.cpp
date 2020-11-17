#include <iostream>
using namespace std;

//λ�����ڴ��в������������ص�
//ȡ��ַ�����&����������λ���κ�ָ�붼�޷�ָ�����λ��
//һ��λ���Ա�������Խ����unsign int�ı߽磬����30��4��λ�򣬵ڶ���Ԫ�ؽ��ӵڶ���unsigned int��λ�ÿ�ʼ
//����ͨ��ָ�롢�������ʵ��λ�����ӳ��

struct _PRBOX
{
	unsigned int toy1 : 2;
	unsigned int toy2 : 8;
	unsigned int box0 : 22;
};

int main()
{
	_PRBOX prbox = { 3, 200, 999 };
	cout << "The size of prbox: " << sizeof(prbox) << endl;
	cout << "toy1: " << prbox.toy1 << endl;
	cout << "toy2: " << prbox.toy2 << endl;
	cout << "box0: " << prbox.box0 << endl;

	//λ�����ķ�����˼��ΪɶҪλ�����
	/*cout << "Using re-mapping to make bitfield return to 0>>" << endl;
	int* p = (int*)&prbox;
	*p = 0;
	cout << "The size of prbox: " << sizeof(prbox) << endl;
	cout << "toy1: " << prbox.toy1 << endl;
	cout << "toy2: " << prbox.toy2 << endl;
	cout << "box0: " << prbox.box0 << endl;*/

	cout << "Using Union to make bitfield return to 0>>" << endl;
	union remap
	{
		struct _PRBOX pbox;
		unsigned int anInteger;
	};
	remap u_box;
	u_box.pbox = _PRBOX{ 3, 200, 999 };
	u_box.anInteger = 0;
	cout << "The size of prbox: " << sizeof(u_box) << endl;
	cout << "toy1: " << u_box.pbox.toy1 << endl;
	cout << "toy2: " << u_box.pbox.toy2 << endl;
	cout << "box0: " << u_box.pbox.box0 << endl;
	return 0;
}