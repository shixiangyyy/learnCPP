#include <vector>
using namespace std;

//C++11�����Զ�alias template��ƫ�ػ�����ȫ�ػ�
//Because an alias-declaration cannot declare a template-id, 
//it is not possible to partially or explictly specialize an 
//alias template
template <typename T>
using Vec = vector<T, allocator<T>>;
//ʹ�ú궨�岻��
//#define Vec<T> template<typename T> vector<T,allocator<T>>;
//���Ǽ򵥵��滻

int main()
{
	Vec<int> col;
	//���ʹ�ú�#define�Ļ��������ᱻ�滻Ϊ��
	//template <typename int> vector<int, allocator<int>>;error
	//ʹ��typedefҲ�޷�������û��ָ��ģ�����

	return 0;
}