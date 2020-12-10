#include <iostream>
using namespace std;

//cin.get(arrayname, size):将字符输入到arrayname中，长度不超过size
int main()
{
	//size是硬性条件，输入大于size时，截取size-1个字符，加上'\0'
	//无论是输入的，还是因为size截取后的，都讲究arrayname，小于时，直接存入，大于时，arrayname自动扩充

	////1、输入串长 < size && 输入串长 > arraylength时，会自动扩张arrayname的大小, 使能保存所有输入数据
	//char a[10];
	//cin.get(a, 20);
	//cout << a << endl;
	//cout << sizeof(a) << endl; //扩张以后a的size还是10，即使a已经扩张
	//cout << a[12] << endl; //能正常输出扩张后的内容
	////2、输入串长 < size && 输入串长 <arraylength时，把串全部输入，后面补'\0'
	//char b[10];
	//cin.get(b, 20);
	//cout << b << endl;
	//cout << sizeof(b) << endl;
	////3、输入串长 > size，先截取size - 1个字符，若还是大于arraylength,则执行类似1，自动扩张arrname，使能保存所有
	//char c[10];
	//cin.get(c, 15);
	//cout << c << endl;
	//cout << sizeof(c) << endl;
	////4、输入串长 > size，先截取size - 1个字符，如小于array length，则把截取的存入array，并补充'\0'
	//char d[20];
	//cin.get(d, 15);
	//cout << d << endl;
	//cout << sizeof(d) << endl;

	//get(arrayname, size, c)三字符
	//把数据先输入到arrayname中，当长度到达size或者遇到c字符时结束
	//其中arrayname必须是字符数组，不可以为string类型，c为控制，遇到输入c时放弃缓冲区
	char e[15];
	cin.get(e, 10, '\t'); //大于size时，截取size-1个，加上'\0'
	cout << e << endl;
	cout << sizeof(e) << endl;

	system("pause");
}