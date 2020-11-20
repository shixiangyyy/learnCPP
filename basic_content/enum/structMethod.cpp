#include <iostream>
using namespace std;

namespace Color
{
	enum Type
	{
		RED = 15,
		YELLOW,
		BLUE
	};
}

struct Color1
{
	enum Type
	{
		RED = 102,
		YELLOW,
		BLUE
	};
};

//c++11ö����
//ö������enum����������ȫ�ֵ�
//���Ҳ��ܹ���ʽת��Ϊ��������
//��ͬ�ڣ�enum class Color2:int
enum class Color2
{
	RED = 1002,
	YELLOW,
	BLUE
};

enum class Color3:char//����ָ�����ض����������洢enum
{
	RED = 'r',
	BLUE //'s'
};

//ͨ��ö�ٳ����������������ж��㶨�ĳ���
//ע��ʹ��const��Ա�����ܱ�֤�����඼�㶨
//ö�ٳ�����ȱ���ǣ������������������������ֵ���ޣ����Ҳ��ܱ�ʾ������
class Person
{
public:
	typedef enum {
		BOY = 0,
		GIRL
	}Sextype;
};

int main()
{
	Color::Type c = Color::RED;
	cout << c << endl;

	Color1 c1;
	cout << c1.RED << endl;

	Color2 c2 = Color2::RED;
	//Error,����ֱ�����Color2���͵�c2,��ΪC++11ö���಻����ʽת������������
	//cout << c2 << endl;
	cout << static_cast<int>(c2) << endl;//����ʹ��static_cast��ʽת������

	char c3 = static_cast<char>(Color3::BLUE);//ͬ��
	cout << c3 << endl;

	system("pause");
	return 0;
}