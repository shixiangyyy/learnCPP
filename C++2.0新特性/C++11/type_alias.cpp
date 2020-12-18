//template template parameter��ģ��ģ�����
//����һ��ģ��Ĳ�������Ҳ��һ��ģ��
//�ڴ�����£�����ʹ�ø�ģ��ģ�������type alias����ȡ����
//���Ǳ���alias��һ�ּ���Ӧ��
//type alias,���ͻ�����������typedef

//There is no difference between a type alias declaration and typedef declaration.
//This declaration may appear in block scope, class scope, or namespace scope

//using�ؼ��ֵ�������;
//using-directives for namespaces and using-declaration for namespace members
	//using namespace std; using std::vector;
//using-declaration for class members
	//using _Base::M_allocate;
	//using _Base::M_deallocate;
//type alias and alias template declaration(since C++11)

#include <iostream>
#include <vector>
using namespace std;

//using��һ��ʹ��
//�൱��typedef
using func = void(*)(int, int);
//�൱��typedef void (fun*)(int, int) func

void example(int, int ){}

//using�ڶ���ʹ��
//����type alias,����ģ�����
template <typename T>
struct Container
{
	using value_type = T;
};

//ģ��ģ�����
//��ģ���ģ�����Ҳ��һ��ģ��
//������£�ͨ������Ϊ������ģ����ʹ��using����type alias
//�����ڸ�ģ�����淽��ػ�ȡ��������
template <typename Cn>
void func2(const Cn& cn)
{
	Cn m; //Cn���͵�m�������Զ��壬����Cn�����ں����������Ͳ�����ֱ�Ӷ���
	typename Cn::value_type n;//������Ի�ȡ����Cn::value_type
	//Ȼ����һ��value_type���͵�n
}

template <typename Container, typename T>
void func3(const Container& cn, T elem)
{
	//Container<T> cn; //Error, Container is not a template
	Container n; //OK
}

//template template parameter
template <typename T, template <class> class Cont>
class XCL
{
	Cont<T> c;
};

//������ʹ�ã�alias template
template <typename CharT>
using string = basic_string<CharT, char_traits<CharT>>;

//ʹ��alias template��vector����������ʹ��Vecģ����Ա�����
//Containerģ����Ĳ���
template <typename T>
using Vec = vector<vector<T>>;

//���ϣ�type alias�൱��typedef��ûʲô��ͬ
int main()
{
	func fn = example;

	Container<int> cn;
	//ʹ��type alias��Ŀ�ģ����ǵ�����Ϊ����д�������
	//���Ǳ����ڸ�����£�Ϊ�˴ﵽҪ��ļ��ĵ�����ʽ
	func2(cn);

	//XCL<int, vector> cl; //Error,type/value mismatch(ԭ����XCLģ��ڶ���
	//����ģ��ֻ��һ��ģ�����������vector����ʵ��������������)
	XCL<int, Container> xcl; //OK
	XCL<int, Vec> xcl1; //OK

	return 0;
}

