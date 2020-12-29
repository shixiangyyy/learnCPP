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