**0、导语**

set/multi_set为C++关联式容器，底部以红黑树为底层结构，因此元素具有自动排序的特性。排序的依据是key键值，对于set/multi_set而言，key就是value，value也就是key。

需要注意的是，我们无法使用set/multi_set的iterator改变元素的值，因为set/multi_set本身就有严格的依赖于key的排序规则。从实现上，等会可知，set/multi_set的iterator是其底部rb_tree的const_iterator,也就是禁止通过iterator对元素进行赋值操作。

set的元素必须独一无二，因此其insert函数使用的是rb_tree的_M_insert_unique()，而multi_set的key可以重复，因此使用的insert函数是rb_tree的_M_insert_equal()。

**1、set**

set模板类：

    template <class _Kty, class _Pr = less<_Kty>, class _Alloc = allocator<_Kty>>
	class set : public _Tree<_Tset_traits<_Kty, _Pr, _Alloc, false>> {
	    // ordered red-black tree of key values, unique keys
	public:
	    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<_Kty, typename _Alloc::value_type>,
	        _MISMATCHED_ALLOCATOR_MESSAGE("set<T, Compare, Allocator>", "T"));
	
	    using _Mybase                = _Tree<_Tset_traits<_Kty, _Pr, _Alloc, false>>;
	    using key_type               = _Kty;
	    using key_compare            = _Pr;
	    using value_compare          = typename _Mybase::value_compare;
	    using value_type             = typename _Mybase::value_type;
	    using allocator_type         = typename _Mybase::allocator_type;
	    using size_type              = typename _Mybase::size_type;
	    using difference_type        = typename _Mybase::difference_type;
	    using pointer                = typename _Mybase::pointer;
	    using const_pointer          = typename _Mybase::const_pointer;
	    using reference              = value_type&;
	    using const_reference        = const value_type&;
	    using iterator               = typename _Mybase::iterator;
	    using const_iterator         = typename _Mybase::const_iterator;
	    using reverse_iterator       = typename _Mybase::reverse_iterator;
	    using const_reverse_iterator = typename _Mybase::const_reverse_iterator;
	
	    using _Alnode        = typename _Mybase::_Alnode;
	    using _Alnode_traits = typename _Mybase::_Alnode_traits;

模板要求三个模板参数，\_Kty键值类型，\_Pr为排序规则，默认为less<\_Kty>, \_Alloc为分配器，默认为allocator<_Kty>。

模板类共有继承自_Tree<_Tset_traits<_Kty, _Pr, _Alloc, false>>。

其中，除了常见的一些必须的数据类型的定义以外，注意如下_Mybase的类型定义：

    using _Mybase = _Tree<_Tset_traits<_Kty, _Pr, _Alloc, false>>;

\_Tset_traits的类型定义：

    template <class _Kty, // key/value type
    class _Pr, // comparator predicate type
    class _Alloc, // actual allocator type (should be value allocator)
    bool _Mfl> // true if multiple equivalent keys are permitted
	class _Tset_traits { // traits required to make _Tree behave like a set
	public:
	    using key_type       = _Kty;
	    using value_type     = _Kty;
	    using key_compare    = _Pr;
	    using allocator_type = _Alloc;
	#if _HAS_CXX17
	    using node_type = _Node_handle<_Tree_node<value_type, typename allocator_traits<_Alloc>::void_pointer>, _Alloc,
	        _Node_handle_set_base, _Kty>;
	#endif // _HAS_CXX17
	
	    static constexpr bool _Multi = _Mfl;
	
	    template <class... _Args>
	    using _In_place_key_extractor = _In_place_key_extract_set<_Kty, _Args...>;
	
	    using value_compare = key_compare;
	
	    static const _Kty& _Kfn(const value_type& _Val) { // extract key from element value
	        return _Val;
	    }
	};

从注释可知，_Tset_traits是一个类型萃取机，目的是使得基础数据类型_Tree表现得像一个set。

然后，转而看_Tree的初始化，为啥要接受一个_Tset_traits类型的类型萃取机作为参数：

    template <class _Traits>
	class _Tree { // ordered red-black tree for map/multimap/set/multiset
	public:
	    using value_type     = typename _Traits::value_type;
	    using allocator_type = typename _Traits::allocator_type;
	
	protected:
	    using _Alty          = _Rebind_alloc_t<allocator_type, value_type>;
	    using _Alty_traits   = allocator_traits<_Alty>;
	    using _Node          = _Tree_node<value_type, typename _Alty_traits::void_pointer>;
	    using _Alnode        = _Rebind_alloc_t<allocator_type, _Node>;
	    using _Alnode_traits = allocator_traits<_Alnode>;
	    using _Nodeptr       = typename _Alnode_traits::pointer;
	
	    using _Scary_val = _Tree_val<conditional_t<_Is_simple_alloc_v<_Alnode>, _Tree_simple_types<value_type>,
	        _Tree_iter_types<value_type, typename _Alty_traits::size_type, typename _Alty_traits::difference_type,
	            typename _Alty_traits::pointer, typename _Alty_traits::const_pointer, value_type&, const value_type&,
	            _Nodeptr>>>;
	
	    static constexpr bool _Multi = _Traits::_Multi;
	
	    enum _Redbl { // colors for link to parent
	        _Red,
	        _Black
	    };
	
	public:
	    using key_type      = typename _Traits::key_type;
	    using value_compare = typename _Traits::value_compare;
	
	    using key_compare = typename _Traits::key_compare;
	
	    using size_type       = typename _Alty_traits::size_type;
	    using difference_type = typename _Alty_traits::difference_type;
	    using pointer         = typename _Alty_traits::pointer;
	    using const_pointer   = typename _Alty_traits::const_pointer;
	    using reference       = value_type&;
	    using const_reference = const value_type&;
	
	    using iterator =
	        conditional_t<is_same_v<key_type, value_type>, _Tree_const_iterator<_Scary_val>, _Tree_iterator<_Scary_val>>;
	    using const_iterator            = _Tree_const_iterator<_Scary_val>;
	    using _Unchecked_iterator       = conditional_t<is_same_v<key_type, value_type>,
	        _Tree_unchecked_const_iterator<_Scary_val>, _Tree_unchecked_iterator<_Scary_val>>;
	    using _Unchecked_const_iterator = _Tree_unchecked_const_iterator<_Scary_val>;
	
	    using reverse_iterator       = _STD reverse_iterator<iterator>;
	    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;

这里是一个红黑树类型_Tree，具体的在rb_tree.md再说，此处只需要知道，在set的类型中，以_Tree类型为底层结构，并且在继承_Tree时传递由set的若干个参数构成的类型萃取机，从而辅助_Tree类型正确定义数据类型和数据。“traits required to make _Tree behave like a set”。

**1、set迭代器**

前面说过set的iterator不允许修改元素数值，因为set的value也是key，那么这个是如何实现的呢？

注意set使用的iterator:

    using iterator = typename _Mybase::iterator;

其中，_Mybase是特化的_Tree类型。那么看_Tree内部对iterator的定义：

    using iterator =
        conditional_t<is_same_v<key_type, value_type>, _Tree_const_iterator<_Scary_val>, _Tree_iterator<_Scary_val>>;

可见，_Tree内部选用的iterator类型会根据key_type和value_type是否是一样的来确定。如果是一样的类型，则选用_Tree_const_iterator，如果不是一样的类型，则选用_Tree_iterator<_Scary_val>。前者对应set/multi_set，后者对应map/multi_map？

**2、set insert**

与GNU4.9版本调用rb_tree内部_M_insert_unique()不同，查阅该版本VC代码后发现，set调用的insert()函数直接来自于公有继承的父类_Tree，而在_Tree中，实现了若干个适应不同输入、返回不同类型的insert()函数：

    template <bool _Multi2 = _Multi, enable_if_t<!_Multi2, int> = 0>
    pair<iterator, bool> insert(const value_type& _Val) {
        const auto _Result = _Emplace(_Val);
        return {iterator(_Result.first, _Get_scary()), _Result.second};
    }

    template <bool _Multi2 = _Multi, enable_if_t<_Multi2, int> = 0>
    iterator insert(const value_type& _Val) {
        return iterator(_Emplace(_Val).first, _Get_scary());
    }

    template <bool _Multi2 = _Multi, enable_if_t<!_Multi2, int> = 0>
    pair<iterator, bool> insert(value_type&& _Val) {
        const auto _Result = _Emplace(_STD move(_Val));
        return {iterator(_Result.first, _Get_scary()), _Result.second};
    }

    template <bool _Multi2 = _Multi, enable_if_t<_Multi2, int> = 0>
    iterator insert(value_type&& _Val) {
        return iterator(_Emplace(_STD move(_Val)).first, _Get_scary());
    }

	iterator insert(const_iterator _Where, const value_type& _Val) {
	        const auto _Scary = _Get_scary();
	#if _ITERATOR_DEBUG_LEVEL == 2
	        _STL_VERIFY(_Where._Getcont() == _Scary, "map/set insert iterator outside range");
	#endif // _ITERATOR_DEBUG_LEVEL == 2
	        return iterator(_Emplace_hint(_Where._Ptr, _Val), _Scary);
	}
	
	iterator insert(const_iterator _Where, value_type&& _Val) {
	        const auto _Scary = _Get_scary();
	#if _ITERATOR_DEBUG_LEVEL == 2
	        _STL_VERIFY(_Where._Getcont() == _Scary, "map/set insert iterator outside range");
	#endif // _ITERATOR_DEBUG_LEVEL == 2
	        return iterator(_Emplace_hint(_Where._Ptr, _STD move(_Val)), _Scary);
	}
	
    template <class _Iter>
    void insert(_Iter _First, _Iter _Last) {
        _Adl_verify_range(_First, _Last);
        auto _UFirst       = _Get_unwrapped(_First);
        const auto _ULast  = _Get_unwrapped(_Last);
        const auto _Myhead = _Get_scary()->_Myhead;
        for (; _UFirst != _ULast; ++_UFirst) {
            _Emplace_hint(_Myhead, *_UFirst);
        }
    }

    void insert(initializer_list<value_type> _Ilist) {
        insert(_Ilist.begin(), _Ilist.end());
    }

直观上看，set的insert函数是直接用的上述某一种，具体使用需要根据函数参数、返回值类型，依靠函数重载和模板特化实现。

**3、multi_set**

multi_set模板类同样位于头文件set.h,其模板类实现为：

    // CLASS TEMPLATE multiset
	template <class _Kty, class _Pr = less<_Kty>, class _Alloc = allocator<_Kty>>
	class multiset : public _Tree<_Tset_traits<_Kty, _Pr, _Alloc, true>> {
	    // ordered red-black tree of key values, non-unique keys
	public:
	    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<_Kty, typename _Alloc::value_type>,
	        _MISMATCHED_ALLOCATOR_MESSAGE("multiset<T, Compare, Allocator>", "T"));
	
	    using _Mybase                = _Tree<_Tset_traits<_Kty, _Pr, _Alloc, true>>;
	    using key_type               = _Kty;
	    using key_compare            = _Pr;
	    using value_compare          = typename _Mybase::value_compare;
	    using value_type             = typename _Mybase::value_type;
	    using allocator_type         = typename _Mybase::allocator_type;
	    using size_type              = typename _Mybase::size_type;
	    using difference_type        = typename _Mybase::difference_type;
	    using pointer                = typename _Mybase::pointer;
	    using const_pointer          = typename _Mybase::const_pointer;
	    using reference              = value_type&;
	    using const_reference        = const value_type&;
	    using iterator               = typename _Mybase::iterator;
	    using const_iterator         = typename _Mybase::const_iterator;
	    using reverse_iterator       = typename _Mybase::reverse_iterator;
	    using const_reverse_iterator = typename _Mybase::const_reverse_iterator;
	
	    using _Alnode        = typename _Mybase::_Alnode;
	    using _Alnode_traits = typename _Mybase::_Alnode_traits;

可见multi_set与set相比基本定义基本类似。唯一的区别在于：

    //set:
	template <class _Kty, class _Pr = less<_Kty>, class _Alloc = allocator<_Kty>>
		class set : public _Tree<_Tset_traits<_Kty, _Pr, _Alloc, false>> {};
	//multi_set:
	template <class _Kty, class _Pr = less<_Kty>, class _Alloc = allocator<_Kty>>
		class multiset : public _Tree<_Tset_traits<_Kty, _Pr, _Alloc, true>> {};

在继承_Tree时，针对_Tree进行特化时的模板参数的最后一位bool值一个是false，一个是true。

观察最后一个参数，查找_Tset_traits源码：

    // CLASS TEMPLATE _Tset_traits
	template <class _Kty, // key/value type
	    class _Pr, // comparator predicate type
	    class _Alloc, // actual allocator type (should be value allocator)
	    bool _Mfl> // true if multiple equivalent keys are permitted
	class _Tset_traits { // traits required to make _Tree behave like a set
	public:
	    using key_type       = _Kty;
	    using value_type     = _Kty;
	    using key_compare    = _Pr;
	    using allocator_type = _Alloc;
	#if _HAS_CXX17
	    using node_type = _Node_handle<_Tree_node<value_type, typename allocator_traits<_Alloc>::void_pointer>, _Alloc,
	        _Node_handle_set_base, _Kty>;
	#endif // _HAS_CXX17
	
	    static constexpr bool _Multi = _Mfl;

其中，static constexpr bool _Multi = _Mfl;

然后在_Tree的特化中使用到了\_Multi: static constexpr bool \_Multi = \_Traits::\_Multi;

然后在前述_Tree实现的多种insert函数中可以看到，有丰富地使用该_Multi参数，进行模板的定义和特化，并进而使用更底层的函数进行元素的插入，而这种插入根据_Multi的不同可能是unique，也可以是equal，因此和GNU4.9有一定的区别。

至于_Tree的细节，和插入方式的不同，在rb_tree.md中将进行探讨。





