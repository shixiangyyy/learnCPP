#include <iostream>
using namespace std;

//a.��C++����ĳ�Ա�����У�����ֱ�ӷ��ʸ�������˽�г�Ա����
//b.����ĳ�Ա�����п��Է���ͬ����ʵ����˽�б���
//c.�ڿ������캯���У�����ֱ�ӷ�����һ��ͬ�����(����)��˽�г�Ա
//d.��ĳ�Ա��������ֱ�ӷ�����Ϊ�������ͬ���Ͷ����˽�г�Ա
class Application
{
public:
	static void f(Application a);
	void g(Application a);
private:
	int x;
};

void Application::f(Application a)
{
	//��̬��Ա����ֻ��ֱ���������ڸ���ľ�̬���ݳ�Ա���߾�̬��Ա����
	//����ͨ������Ķ������ö���ĳ�Ա
	//cout << x << end; //error����x�������Ǵ����
	cout << a.x << endl; //Ĭ��0
}

void Application::g(Application a)
{
	cout << a.x << endl; //�����˽�г�Ա���ڸö���������ĺ����п�������
}

int main()
{
	Application a;
	//cout << a.x << endl; //�˴�a�����x˽�г�Ա���ܷ��ʣ�����������f�����Ķ����п��Է���

	Application::f(a);
	a.g(Application());

	system("pause");
	return 0;
}