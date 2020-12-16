//variadic5.cpp������Ϊ�ݹ����
//������Ϊ�ݹ�̳�
#include <iostream>
#include <string>
using namespace std;

namespace light
{
	//��ģ��
	template <typename...Values> class tuple;
	//�ػ�ģ�壬û�в���
	template <> class tuple<> {};

	//�ػ�ģ�壬1+N��ģ�����
	//���ػ�ģ����̳�N��ģ�������tupleģ��
	template <typename Head, typename...Tail>
	class tuple<Head, Tail...> :private tuple<Tail...>
	{
	private:
		typedef tuple<Tail...> inherited;
	protected:
		Head m_head;
	public:
		tuple() {};
		//������ʼ���Ժ󣬱�ݹ����tupleģ���ֱ࣬��������Ϊ0
		tuple(Head h, Tail...tail) :m_head(h), inherited(tail...) {}
		Head head() { return m_head; }
		//����ǰ���͵Ķ���תΪһ��inherited���͵Ķ���
		//�ڲ�ʲô���ƣ�Ϊ�ο����Զ�ʶ����𣬲��ҿ���ʶ���Ӧ�Ĵ���
		//���ģ���������Ϊint,int,int������Ҳ������ȷȷ��tail�����Ĳ���
		inherited& tail() { return *this; }
	};
}

int main()
{
	using light::tuple;
	tuple<int, float, string> t(41, 5.6, "phanteks");
	//��С�����ͬ��������ͬ��VS2015���56��g++���40
	cout << sizeof(t) << endl;
	cout << t.head() << endl;
	cout << t.tail().head() << endl;
	cout << t.tail().tail().head() << endl;

	system("pause");
	return 0;
}