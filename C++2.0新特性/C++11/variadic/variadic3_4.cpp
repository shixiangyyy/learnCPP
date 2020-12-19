#include <iostream>
using namespace std;

//ֻ��һ��������maximum����
int maximum(int n) { return n; }

//�ݹ����
template <typename...Args>
int maximum(int n, const Args&...args)
{
	return std::max(n, maximum(args...));
}

//����type��ͬ��max����
//C++11�����캯�������������ѳ�ʼ���б�������
//���԰������ô���
//���û�еݹ���ã�Ч�ʸ���
int max(initializer_list<int> initializerList)
{
	int res = *initializerList.begin();
	for (auto elem : initializerList)
		res = max(res, elem);
	return res;
}

int main()
{
	cout << max({ 10,8,100,1 }) << endl;
	cout << maximum(57, 2342, 234924, 4234, 2) << endl;
	system("pause");
	return 0;
}