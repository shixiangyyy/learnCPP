#include <iostream>
using namespace std;

//位域在内存中布局是与机器相关的
//取地址运算符&不能作用于位域，任何指针都无法指向类的位域
//一个位域成员不允许跨越两个unsign int的边界，比如30，4的位域，第二个元素将从第二个unsigned int的位置开始
//可以通过指针、联合体等实现位域的重映射

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

	//位域归零的方法。思考为啥要位域归零
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