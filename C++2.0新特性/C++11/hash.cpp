#include <iostream>
#include <unordered_set>
#include <complex>
using namespace std;

class Customer{};

//写hash规则得第一种方式
//通过一个类，重载()操作符，形成一个仿函数，或者叫函数对象
class CustomerHash
{
public:
	size_t operator()(const Customer& c)const {};
};

// 形式二 
//这个方法实际是通过指定了一个函数指针的方式来通知容器，
//对于这个自定义类到底应该使用哪个hash function
size_t customer_hash_func(const Customer &t) {
	//    return ...;
}

// 形式三 以struct hash 偏特化形式实现hash function
namespace std {     // 必须放在std里面
	template<>
	struct hash<Customer> : public __hash_base<size_t, Customer> { 
		// 继承不继承都可以!
		size_t
			operator()(const Customer&s) const noexcept {
			//            return ...;
		}
	};
}

//万能hash,通过variadic templates（抄）
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
	//通过类实现仿函数
	unordered_set<Customer, CustomerHash> st;
	//通过函数指针
	unordered_set<Customer, size_t(*)(const Customer&)> st1(20, customer_hash_func);
	unordered_set<Customer> st2;

	int *p = reinterpret_cast<int *>(new Customer());
	cout << hash_val(p) << endl;

	system("pause");
	return 0;
}