STL六大部件：
1、容器
2、分配器
3、算法
4、迭代器
5、适配器
6、仿函数

list内部是双向环形链表，forward-list是单向链表；

C++标准库并没有规定set和map这种数据结构一定要通过红黑树实现，
但是，由于红黑树良好的性质，目前各家编译期都是使用红黑树实现。

multiset和multimap键值可以重复，set和map不可以重复。

unordered_set/map通过hash_table实现，目前采用性质最好的哈希方式：
	hashtable separate chaining,链表式存储的哈希

stack和queue从技术上叫deque的容器适配器container adapter

使用分配器allocator
    应该在程序里面直接使用容器，小量的分配直接使用new或者malloc，分配器不好用
	
OOP是将data和method包装在一起，GP(泛型编程)却是将data和method分离开处理
generic programming，采用GP的方式，使得算法和容器两个团队可以分开闭门造句
STL采用GP编程的方式，将容器和算法分开，并通过迭代器联系在一起

但是STL list不采用全局的sort排序。有一定的原因。因为list里面的排序算法使用了迭代器加减
所以对于STL的容器，自己有这种sort函数，就尽量不要用全局的算法函数。

分配器allocator原理
    VC6 STL对allocator的使用。
	allocator调用allocate函数，allocate函数调用operator new，最终调用malloc函数
	deallocate函数调用delete，后者调用free
	“VC6+的allocator只是以::operator new和::operator delete完成对allocate和的deallocate
	函数的调用，没有任何特殊涉及”
	例子：int* p = allocator<int>().allocate(512, (int*)0);
		  allocator<int>.deallocate(p, 512);这里对size的要求制约了对allocator的直接使用
	GNC2.9编译期提供了一种特殊地用于节省cookie空间地分配器，可以大大节约分配所得空间。
	但是GNU4.9版本用回了原始的版本，但是提供了pool_alloc实现了好的高效率的分配器
	https://www.bilibili.com/video/BV1zt411V7Ye?p=11
	
继承VS对象组合

list
    list的iterator是一个__list_iterator类。实现类似指针的功能。
	typedef __list_iterator<T, T&, T*> iterator;
	
C++后++返回的是一个右值
C++后++返回的是一个右值

Iterator需要遵循的原则
	是算法和容器的桥梁：算法提问->迭代器回答
	Iterator必须提供的5中associated type:
		iterator_catagory 
		value_type 
		pointer 
		reference 
		difference_type(两个迭代器之间的距离)

traits作为一个一个人为设计的机制，用于从迭代器中获取前述五种类型(类型萃取机)
	因为iterator不一定是一个class，还有可能是一种指针，所以traits:
	必须有能力分辨它所获得的iterator是class还是一种指向T的原生指针。利用偏特化即可实现
	iterator traits用以分离class iterator和non-class iterator
	
map允许元素的data被改变，只有元素的key是不可以改变的。如果要改变键值对，可以采用insert函数
	rb_tree提供两种insertion操作：insert_unique()和insert_equal();
	前者表示节点的key一定独一无二，后者表示可以重复。

stack和queue底层默认使用deque作为底部支撑
	但是除了deque以外，也可以使用list作为底部支撑，但是默认的一般性能更好
queue和stack都没有实现迭代器的功能
queue不可以选择vector作为底层结构, vector没有pop操作，使用时有可能出错；
stack可以使用vector作为底层结构；
stack和queue都不可以选择set或者map作为底层结构。
总结：编译器不会完整地检查模板类中的模板参数，只是会在运行时出现特定的错误。

从语言层面讲
	容器、迭代器、仿函数、适配器、分配器 都是class template
	但是算法是个function template
	算法本身是看不到容器的，算法只知道依据自身的逻辑，借助迭代器处理容器
	
迭代器的分类
	五种iterator categories：
		struct input_iterator_tag{};
		struct output_iterator_tag{};
		struct forward_iterator_tag: public input_iterator_tag {};
		struct bidirectional_iterator_tag: public forward_iterator_tag {};
		struct random_access_iterator_Tag: public bidirectional_iterator_tag {};
		
算法：
	实例：
		accumulate，两个版本:
			template <class InputIterator, class T> 
				accumulate(InputIterator first, InputIterator last, T init);
			template <class InputIterator, class T, class BinaryOp> 
				accumulate(InputIterator first, InputIterator last, T init, BinaryOp binary_op);
		for_each:
			template <class InputIterator, class Function> 
			Function for_each(InputIterator first, InputIterator last, Function f);
		replace, replace_if, replace_copy
		count, count_if:注意容器里面有没有带同名的算法函数
		find, find_if
		sort:只有容器list和forward_list具有内置算法sort，像vector array这些都是用公用的sort函数
			因为sort要求Random_access_iterator
		binary_search: test if value exists in sorted sequence.
		
仿函数
	是个对象，像个函数的功能
	算术类：plus, minus
	逻辑运算类：logical_and
	相对关系类：equal_to, less, greater
	GNU C++独有，非标准，identity， select1st, select2nd
仿函数functors的可适配条件：
	STL标准库往往会继承binary_function等类，以融入STL的体系结构，类似的还有unary_function；
    STL规定，每个adaptable function都应该挑选适当者继承之，因为function adapter将会提问红色问题。
	unary：argument_type, result_type
	binary:first_argument_type, last_argument_type, result_type
	
适配器(改造器)
	存在多种适配器：
		容器适配器
		仿函数适配器
		迭代器适配器
	A取用B的功能，比如set和map就可以说是rb_tree的一种容器适配器，stack和queue就是deque的一种容器适配器
		就是取用其部分功能，并对部分功能的一些标记等进行修改，相当于一种重新封装+完善。
	
	function adapter:
		bind2nd, not1, 新型适配器bind
	iterator adapter:
		iterator_reverser:
			逆向的++就是正向的--
			逆向的--就是正向的++
		inserter
	X adapter：未知适配器
		ostream_iterator
			std::ostream_iterator<int> out_it(std::cout, ","); //","作为分隔符
			std::copy(myVec.begin(), myVec.end(), out_it);
			cout是一个basic_ostream
		istream_iterator
		
类型萃取机type traits
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	