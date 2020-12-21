//C++11�е�constexprָ���ĺ����ͷ���ֵ������Ҫ��֤������ֵ
//���ұ�������ֻ��һ��return����
//C++14��ֻҪ��֤����ֵ�Ͳ���������ֵ����

//const & constexpr
//const���ܴ��������������ǶԱ�����һ������
//���߱������ñ���ֻ�ܱ���ʼ�������ܱ�ֱ���޸�
//�����������ֵ������������ʱҲ�����ڱ���ʱָ��
//constexpr�����������α��������������캯��
//һ�������κ�Ԫ�ر�constexpr����
//��ô�����Ǹ��߱�����
//����󵨵Ľ��ҿ��ɱ���ʱ���ܵó�����ֵ�ı��ʽȥ�����Ż���

//�ܽ᣺
//��������object��˵
//const��û�����ֱ����ڳ����������ڳ���
//constexpr�޶����˱����ڳ�����Ŀ�������Ż�
//constexpr���εĺ������䷵��ֵ��һ���Ǳ����ڳ���
//const���ε������ͣ���constexpr���ε������ֵ�ó���Σ��ڱ�����ִ��

//constexpr���εú������򵥶��ԣ��������ò��������ڱ����ڼ��������
//��ô��������ͻ��������ʱ�ڵ�ֵ
//���ǣ��������ò��������ڱ����ڼ����������ôcosntexpr���εú����ͺ���ͨ����һ��
#include <iostream>
#include <array>
using namespace std;

const int foo(int i)
{
	return i + 10;
}

//����constexprǰ׺����ʾ���ѱ������ڱ����ھ���ȷ�����øú�����ֵ
//�൱��һ���Ż�
constexpr int foo_constexpr(int i)
{
	return i + 10;
}

int main()
{
	int i = 10;
	//error, the value of i is not usable in a constant expression
	//std::array<int, i + 10> arr2; //���i�滻Ϊconst int��ͨ��
	//error, call to non-constexpr function "const int foo(int)"
	//std::array<int, foo(10)> arr; //array�ĳ��ȶ�����������ȷ��
	//OK���൱��array<int, 20>,�����ڼ�������;����Դ˽����Ż�
	std::array<int, foo_constexpr(10)> arr1;
	
	//OK
	foo_constexpr(i);
	//OK
	foo_constexpr(10);

	return 0;
}

