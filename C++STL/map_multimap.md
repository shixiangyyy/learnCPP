**0、导语**

与set/multi\_set类似，map/multi\_map同属于关联式容器，并且底部实现为红黑树，元素具有自动排序的特征。对于map/multi\_map来说，排序的依据是key键值，key和value搭配起来构成键值对，C++实现为pair<\_Ty1, _Ty2>。

对于map/multi\_map容器来说，我们可以通过其iterator改变元素键值对的value，但是无法通过iterator改变键值对的key，从逻辑上说也好理解，因为map/multi\_map的排序依据便是多个键值对的key。

类似地，map的元素的key必须独一无二，因此在侯捷老师课程所说的GNU4.9版本中insert操作调用的是rb\_tree的_M\_insert\_unique()函数，而multi\_map的key不必要独一无二，因此采用的insert操作调用的是rb\_tree的\_M\_insert\_equal()。

除了与set/multi_set一节类似的内容探讨外，本节还将探讨map和multi\_map对操作符函数operator[]的支持(map支持operator[],而multi\_map不支持operator[])。

**1、map**

map模板类：

    template <class _Kty, class _Ty, class _Pr = less<_Kty>, class _Alloc = allocator<pair<const _Kty, _Ty>>>
	class map : public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, false>> {
	    // ordered red-black tree of {key, mapped} values, unique keys
	public:
	    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<pair<const _Kty, _Ty>, typename _Alloc::value_type>,
	        _MISMATCHED_ALLOCATOR_MESSAGE("map<Key, Value, Compare, Allocator>", "pair<const Key, Value>"));
	
	    using _Mybase                = _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, false>>;
	    using _Nodeptr               = typename _Mybase::_Nodeptr;
	    using key_type               = _Kty;
	    using mapped_type            = _Ty;
	    using key_compare            = _Pr;
	    using value_compare          = typename _Mybase::value_compare;
	    using value_type             = pair<const _Kty, _Ty>;
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

其中，map模板类继承一个接受\_Tmap\_traits<\_Kty, \_Ty, \_Pr, \_Alloc, false>作为模板参数进行特化的_Tree类。其中，\_Tmap\_traits类似\_Tset\_traits定义如下：

    template <class _Kty, // key type
    class _Ty, // mapped type
    class _Pr, // comparator predicate type
    class _Alloc, // actual allocator type (should be value allocator)
    bool _Mfl> // true if multiple equivalent keys are permitted
	class _Tmap_traits { // traits required to make _Tree behave like a map
	public:
	    using key_type       = _Kty;
	    using value_type     = pair<const _Kty, _Ty>;
	    using key_compare    = _Pr;
	    using allocator_type = _Alloc;

这个\_Tmap\_traits的作用便是，工作为一个包装特定类型map的类型萃取机，使得接受该traits的_Tree类可以像一个map一样工作。该\_Tmap\_traits内部可见封装了map类型包含的key、value、key\_compare、allocator等类型，还有只是是map还是multi\_map的bool _Mfl参数(指示元素key是否可以重复)。

还需要注意的是，这里的value_type定义如下：

    using value_type = pair<const _Kty, _Ty>;

这印证了之前的说法，map通过将每个元素键值对中的键key定义为const类型，以避免iterator在进行各种操作时对元素键值对的key进行修改；相对地，value的类型并没有被定义为const类型，这暗示可以通过iterator对元素键值对的value进行修改。除此以外，还需要注意在模板类map的模板参数列表中，\_Alloc的默认值：

    class _Alloc = allocator<pair<const _Kty, _Ty>>;

这也是前述将key固定的实现细节之一。

**2、map迭代器**

map内部支持的四种功能的迭代器隶属于类:

    _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, false>>

转向_Tree内部：

    // CLASS TEMPLATE _Tree
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

这里可转向set\_multiset.md，可以看到这里是使用了conditional\_t根据key_type和value_type是否相同判断使用的迭代器是\_Tree\_const\_iterator还是\_Tree\_iterator。除此以外，这里还需要注意，\_Tree中定义的iterator并不仅仅是常见的四种迭代器。除了iterator、const\_iterator、reverse\_iterator、const\_reverse\_iterator四种STL常用迭代器以外，这里还有\_Unchecked\_iterator和\_Unchecked\_const\_iterator。具体后面这两种迭代器的作用在rb_tree.md中将说到。

**3、map insert**

与set/multi\_set直接使用父类\_Tree的insert函数有所不同，除上述以外，map自己实现了如下insert函数：

    using _Mybase::insert;

    template <class _Valty, enable_if_t<is_constructible_v<value_type, _Valty>, int> = 0>
    pair<iterator, bool> insert(_Valty&& _Val) {
        return this->emplace(_STD forward<_Valty>(_Val));
    }

    template <class _Valty, enable_if_t<is_constructible_v<value_type, _Valty>, int> = 0>
    iterator insert(const_iterator _Where, _Valty&& _Val) {
        return this->emplace_hint(_Where, _STD forward<_Valty>(_Val));
    }

其中，enable\_if\_t实现如下：

    / STRUCT TEMPLATE enable_if
	template <bool _Test, class _Ty = void>
	struct enable_if {}; // no member "type" when !_Test
	
	template <class _Ty>
	struct enable_if<true, _Ty> { // type is _Ty for _Test
	    using type = _Ty;
	};
	
	template <bool _Test, class _Ty = void>
	using enable_if_t = typename enable_if<_Test, _Ty>::type;

就是，当enable\_if\_t<bool \_Test, class \_Ty = void>的第一个bool参数为true时，激活第二个参数的type,在模板里面默认为void类型，并作为一种类型返回，因为 `using enable_if_t = typename enable_if<_Test, _Ty>::type`。

然后，is\_constructible\_v用于判断第一个类型是否可以被第二个类型初始化，如果可以，返回true。

因此，上述两个insert模板函数可以理解为，当\_Valty类型可以用于value\_type类型的初始化时，模板将具有两个模板参数，其中第二个参数为int = 0;否则当value\_type不可以被\_Valty类型初始化时，模板就只有一个模板参数。

forward函数将一个右值或者左值转移为左值或者右值：

    // FUNCTION TEMPLATE forward
	template <class _Ty>
	_NODISCARD constexpr _Ty&& forward(
	    remove_reference_t<_Ty>& _Arg) noexcept { // forward an lvalue as either an lvalue or an rvalue
	    return static_cast<_Ty&&>(_Arg);
	}
	
	template <class _Ty>
	_NODISCARD constexpr _Ty&& forward(remove_reference_t<_Ty>&& _Arg) noexcept { // forward an rvalue as an rvalue
	    static_assert(!is_lvalue_reference_v<_Ty>, "bad forward call");
	    return static_cast<_Ty&&>(_Arg);
	}

然后，map的insert函数调用emplace()或者emplace\_hint()两个函数进行数据插入。然而，对于map来说，emplace和emplace_hint两个函数隶属于父类\_Tree：

    template <class... _Valtys>
    iterator emplace_hint(const_iterator _Where, _Valtys&&... _Vals) { // insert value_type(_Val...) at _Where
        const auto _Scary = _Get_scary();
	#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(_Where._Getcont() == _Scary, "map/set insert iterator outside range");
	#endif // _ITERATOR_DEBUG_LEVEL == 2
        return iterator(_Emplace_hint(_Where._Ptr, _STD forward<_Valtys>(_Vals)...), _Scary);
    }

    template <class... _Valtys>
    pair<iterator, bool> emplace(_Valtys&&... _Vals) {
        const auto _Result = _Emplace(_STD forward<_Valtys>(_Vals)...);
        return {iterator(_Result.first, _Get_scary()), _Result.second};
    }

然后进一步结合更底层的\_Emplace(\_hint)函数进行数值的插入。更深一层就是_Tree在实现时的数据结构。

**4、multi_map**

multi_map的模板类：

    // CLASS TEMPLATE multimap
	template <class _Kty, class _Ty, class _Pr = less<_Kty>, class _Alloc = allocator<pair<const _Kty, _Ty>>>
	class multimap : public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, true>> {
	    // ordered red-black tree of {key, mapped} values, non-unique keys
	public:
	    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<pair<const _Kty, _Ty>, typename _Alloc::value_type>,
	        _MISMATCHED_ALLOCATOR_MESSAGE("multimap<Key, Value, Compare, Allocator>", "pair<const Key, Value>"));
	
	    using _Mybase                = _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, true>>;
	    using key_type               = _Kty;
	    using mapped_type            = _Ty;
	    using key_compare            = _Pr;
	    using value_compare          = typename _Mybase::value_compare;
	    using value_type             = pair<const _Kty, _Ty>;
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

与map基本一致，不同之处在于给_Tmap_traits指定的static constexpr bool \_Multi = \_Mfl;而该\_Mfl在multi_map模板类中默认为true,而map为false。

