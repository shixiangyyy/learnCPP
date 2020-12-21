#include <iostream>
#include <unordered_set>
#include <complex>
using namespace std;

class Customer{};

//дhash����õ�һ�ַ�ʽ
//ͨ��һ���࣬����()���������γ�һ���º��������߽к�������
class CustomerHash
{
public:
	size_t operator()(const Customer& c)const {};
};

// ��ʽ�� 
//�������ʵ����ͨ��ָ����һ������ָ��ķ�ʽ��֪ͨ������
//��������Զ����ൽ��Ӧ��ʹ���ĸ�hash function
size_t customer_hash_func(const Customer &t) {
	//    return ...;
}

// ��ʽ�� ��struct hash ƫ�ػ���ʽʵ��hash function
namespace std {     // �������std����
	template<>
	struct hash<Customer> : public __hash_base<size_t, Customer> { 
		// �̳в��̳ж�����!
		size_t
			operator()(const Customer&s) const noexcept {
			//            return ...;
		}
	};
}

//����hash,ͨ��variadic templates������
// (4)
template<typename T>
inline void hash_combine(size_t& seed, const T& val) {
	seed = std::hash<T>()(val) + 0x9e3779b9
		+ (seed << 6) + (seed >> 2);
}

// (3)
template<typename T>
inline void hash_val(size_t& seed, const T& val) {
	hash_combine(seed, val);
}

// (2)
template<typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args) {
	hash_combine(seed, val);
	hash_val(seed, args...);
}
// (1),general
template<typename... Types>
inline size_t hash_val(const Types&... args) {
	size_t seed = 0;
	hash_val(seed, args...);
	return seed;
}

int main()
{
	//ͨ����ʵ�ַº���
	unordered_set<Customer, CustomerHash> st;
	//ͨ������ָ��
	unordered_set<Customer, size_t(*)(const Customer&)> st1(20, customer_hash_func);
	unordered_set<Customer> st2;

	int *p = reinterpret_cast<int *>(new Customer());
	cout << hash_val(p) << endl;

	system("pause");
	return 0;
}