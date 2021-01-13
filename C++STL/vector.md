**0、导语**

相对array，vector具有类似的数据存储结构和操作方式，二者从物理含义上而言都叫做数组。不同的是，array是静态数组，vector是动态数组，具有一定的自动扩充以满足更大数据存储空间要求的性质。

**1、vector**

模板类vector的部分定义：

    template <class _Ty, class _Alloc = allocator<_Ty>>
	class vector { // varying size array of values
	private:
	    template <class>
	    friend class _Vb_val;
	    friend _Tidy_guard<vector>;
	
	    using _Alty        = _Rebind_alloc_t<_Alloc, _Ty>;
	    using _Alty_traits = allocator_traits<_Alty>;
	
	public:
	    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<_Ty, typename _Alloc::value_type>,
	        _MISMATCHED_ALLOCATOR_MESSAGE("vector<T, Allocator>", "T"));
	
	    using value_type      = _Ty;
	    using allocator_type  = _Alloc;
	    using pointer         = typename _Alty_traits::pointer;
	    using const_pointer   = typename _Alty_traits::const_pointer;
	    using reference       = _Ty&;
	    using const_reference = const _Ty&;
	    using size_type       = typename _Alty_traits::size_type;
	    using difference_type = typename _Alty_traits::difference_type;

在上述定义中，包括STL容器类定义中通常需要的value_type、(const_)pointer、(const_)reference、allocator_type、difference_type以及size_type。

作为数据的基础，需要注意上述两行代码：

    using _Alty        = _Rebind_alloc_t<_Alloc, _Ty>;
	using _Alty_traits = allocator_traits<_Alty>;

其中，_Rebind_alloc_t<_Alloc, _Ty>的声明如下：

    template <class _Alloc, class _Value_type>
	using _Rebind_alloc_t = typename allocator_traits<_Alloc>::template rebind_alloc<_Value_type>;

因此_Alty的定义相当于：

    using _Alty = typename allocator_traits<_Alloc>::template rebind_alloc<_Ty>;

然后，继续查找rebind_alloc的定义，发现：

    template <class _Other>
    using rebind_alloc = allocator<_Other>;

所以：

    using _Alty = allocator<_Ty>;

因此，绕了一圈，_Alty意思就是allcator_ty的意思。

与此相对的，_Alty_traits就是_Alty的类型萃取机。

在此基础上，vector类定义中对(const_)pointer的定义采用如下方式：

    using pointer = typename _Alty_traits::pointer;

又找到pointer的定义：

    using pointer = value_type*;
	using const_pointer = const value_type*;

因此，(const_)pointer实际上就是(const) value_type*;

需要注意的是，vector模板类实现了对数据类型为bool型的偏特化：

    template <class _Alloc>
	class vector<bool, _Alloc> : public _Vb_val<_Alloc> {
	public:
	    static_assert(!_ENFORCE_MATCHING_ALLOCATORS || is_same_v<bool, typename _Alloc::value_type>,
	        _MISMATCHED_ALLOCATOR_MESSAGE("vector<bool, Allocator>", "bool"));
	
	    using _Mybase          = _Vb_val<_Alloc>;
	    using _Alvbase_wrapped = typename _Mybase::_Alvbase_wrapped;
	    using _Alvbase         = typename _Mybase::_Alvbase;
	    using _Alvbase_traits  = typename _Mybase::_Alvbase_traits;
	
	    using size_type       = typename _Alvbase_traits::size_type;
	    using difference_type = typename _Alvbase_traits::difference_type;
	    using allocator_type  = _Alloc;
	
	    using reference       = _Vb_reference<_Alvbase_wrapped>;
	    using const_reference = bool;
	    using value_type      = bool;
	
	    using _Reft          = reference;
	    using iterator       = _Vb_iterator<_Alvbase_wrapped>;
	    using const_iterator = _Vb_const_iterator<_Alvbase_wrapped>;
	
	    using pointer                = iterator;
	    using const_pointer          = const_iterator;
	    using reverse_iterator       = _STD reverse_iterator<iterator>;
	    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;

在看的这个VC版本中，vector模板类内部定义了一个友元类：

     template <class>
	 friend class _Vb_val;

继续查看源码，发现友元类_Vb_val的定义：

    template <class _Alloc>
	class _Vb_val : public _Container_base {
	public:
	    using _Alvbase         = _Rebind_alloc_t<_Alloc, _Vbase>;
	    using _Alvbase_traits  = allocator_traits<_Alvbase>;
	    using _Vectype         = vector<_Vbase, _Alvbase>;
	    using _Alvbase_wrapped = _Wrap_alloc<_Alvbase>;
	    using size_type        = typename _Alvbase_traits::size_type;

发现友元类\_Vb\_val公有继承自\_Container\_base。并且内部\_Alvbase、\_Alvbase\_traits、\_Vectype、\_Alvbase\_wrapped、size\_type等以、\_Vbase为基础。而\_Vbase:

    using _Vbase = unsigned int;

**2、vector迭代器**

vector类内部实现了两种迭代器模板类：

1. class \_Vector_const_iterator
2. class \_Vector_iterator

在该两种基础迭代器模板类的基础上，vector内部定义了四个迭代器，两个正向，两个反向：

    using iterator               = _Vector_iterator<_Scary_val>;
    using const_iterator         = _Vector_const_iterator<_Scary_val>;
    using reverse_iterator       = _STD reverse_iterator<iterator>;
    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;

以_Vector_const_iterator为例：

    template <class _Myvec>
	class _Vector_const_iterator : public _Iterator_base {
		public:
		#ifdef __cpp_lib_concepts
	    using iterator_concept = contiguous_iterator_tag;
		#endif // __cpp_lib_concepts
	    using iterator_category = random_access_iterator_tag;
	    using value_type        = typename _Myvec::value_type;
	    using difference_type   = typename _Myvec::difference_type;
	    using pointer           = typename _Myvec::const_pointer;
	    using reference         = const value_type&;
	
	    using _Tptr = typename _Myvec::pointer;

其中iterator_category为random_access_iterator_tag，符合预期；
value_type为模板参数_Myvec(某种特化的vector)的value_type;
difference_type类似；
pointer需要注意的是，是_Myvec的const_pointer，因为这里是const_iterator;
reference是value_type类型的引用；
将_Tptr定义为_Myvec的pointer。

对于const_iterator而言，其在实现operator function时有尽可能地体现const属性：

        _NODISCARD reference operator*() const noexcept {
	#if _ITERATOR_DEBUG_LEVEL != 0
	        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
	        _STL_VERIFY(_Ptr, "can't dereference value-initialized vector iterator");
	        _STL_VERIFY(
	            _Mycont->_Myfirst <= _Ptr && _Ptr < _Mycont->_Mylast, "can't dereference out of range vector iterator");
	#endif // _ITERATOR_DEBUG_LEVEL != 0
	
	        return *_Ptr;
	    }
	
	    _NODISCARD pointer operator->() const noexcept {
	#if _ITERATOR_DEBUG_LEVEL != 0
	        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
	        _STL_VERIFY(_Ptr, "can't dereference value-initialized vector iterator");
	        _STL_VERIFY(
	            _Mycont->_Myfirst <= _Ptr && _Ptr < _Mycont->_Mylast, "can't dereference out of range vector iterator");
	#endif // _ITERATOR_DEBUG_LEVEL != 0
	
	        return _Ptr;
	    }

如上示例operator*()和operator->()函数，都被定义为const函数，使得其内部不允许对数据的修改，以实现const_itertor只遍历取值而不进行修改的特性，是一种数据保护机制。

对于_Vector\_iterator来说，前述操作符函数实现如下：

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return _Const_cast(_Mybase::operator->());
    }

其中_Mybase为：

    using _Mybase = _Vector_const_iterator<_Myvec>;

所以实际上是调用父类\_Vector_base_iterator的同名操作符函数，之后对获取的reference或者pointer进行const_cast。

其他：前++后++前--后--：

	//前--需要进行范围检查
      _Vector_const_iterator& operator--() noexcept {
	#if _ITERATOR_DEBUG_LEVEL != 0
	        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
	        _STL_VERIFY(_Ptr, "can't decrement value-initialized vector iterator");
	        _STL_VERIFY(_Mycont->_Myfirst < _Ptr, "can't decrement vector iterator before begin");
	#endif // _ITERATOR_DEBUG_LEVEL != 0
	
	        --_Ptr;
	        return *this;
	    }
	//后--直接调用前--
     _Vector_const_iterator operator--(int) noexcept {
        _Vector_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

后--直接调用前--，方法是先记录当前迭代器的位置，--当前的位置，并返回被记录的位置，从而实现后--的效果：先返回位置再转移位置。前后++类似。

operator+():实现批量迭代器转移。使用时写为iter+n。n使用时为整数，但是内部实现为difference_type:

    template <class _Myvec>
	_NODISCARD _Vector_const_iterator<_Myvec> operator+(
	    typename _Vector_const_iterator<_Myvec>::difference_type _Off, _Vector_const_iterator<_Myvec> _Next) noexcept {
	    return _Next += _Off;
	}


**3、vector的内存管理**

有所不同的是，VC这个版本的vector模板类，并不存在如_Vector_base和_Vector_impl等vector基类和内存管理器。因而相对避免了较为复杂的多层继承关系等。

对于该VC版本的vector类的内存管理而言，目前通过看源码发现，vector在定义四种迭代器类型时，使用的类型是\_Scary\_val:

    private:
	    using _Scary_val = _Vector_val<conditional_t<_Is_simple_alloc_v<_Alty>, _Simple_types<_Ty>,
	        _Vec_iter_types<_Ty, size_type, difference_type, pointer, const_pointer, _Ty&, const _Ty&>>>;
	
	public:
	    using iterator               = _Vector_iterator<_Scary_val>;
	    using const_iterator         = _Vector_const_iterator<_Scary_val>;
	    using reverse_iterator       = _STD reverse_iterator<iterator>;
	    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;

注意其中对_Scary_type的定义。其中conditional_t的定义如下：

    // STRUCT TEMPLATE conditional
	template <bool _Test, class _Ty1, class _Ty2>
	struct conditional { // Choose _Ty1 if _Test is true, and _Ty2 otherwise
	    using type = _Ty1;
	};
	
	template <class _Ty1, class _Ty2>
	struct conditional<false, _Ty1, _Ty2> {
	    using type = _Ty2;
	};
	
	template <bool _Test, class _Ty1, class _Ty2>
	using conditional_t = typename conditional<_Test, _Ty1, _Ty2>::type;

从中可知，conditional_t根据第一个bool型参数的类型确定最后选择的type是type1还是type2。由此以来，_Simple_types的定义如下：

    template <class _Value_type>
	struct _Simple_types { // wraps types from allocators with simple addressing for use in iterators
	                       // and other SCARY machinery
	    using value_type      = _Value_type;
	    using size_type       = size_t;
	    using difference_type = ptrdiff_t;
	    using pointer         = value_type*;
	    using const_pointer   = const value_type*;
	};

因此，_Simple_type是对_Ty的五种衍生类型的结构体封装，而_Vec_iter_types的定义为：

    // vector TYPE WRAPPERS
	template <class _Value_type, class _Size_type, class _Difference_type, class _Pointer, class _Const_pointer,
	    class _Reference, class _Const_reference>
	struct _Vec_iter_types {
	    using value_type      = _Value_type;
	    using size_type       = _Size_type;
	    using difference_type = _Difference_type;
	    using pointer         = _Pointer;
	    using const_pointer   = _Const_pointer;
	};

相对来说，经过简单分析，下面的迭代器类型封装更加复杂，比如采用的difference_type相对simple_type的int类型更加复杂，因此_Scary_val根据实际情况，选择对应的迭代器类型wrapper进行对类型_Vector_val的重定义。其中，_Vector_val是一个类：

    emplate <class _Val_types>
	class _Vector_val : public _Container_base {
	public:
	    using value_type      = typename _Val_types::value_type;
	    using size_type       = typename _Val_types::size_type;
	    using difference_type = typename _Val_types::difference_type;
	    using pointer         = typename _Val_types::pointer;
	    using const_pointer   = typename _Val_types::const_pointer;
	    using reference       = value_type&;
	    using const_reference = const value_type&;
	
	    _Vector_val() noexcept : _Myfirst(), _Mylast(), _Myend() {}
	
	    void _Swap_val(_Vector_val& _Right) noexcept {
	        this->_Swap_proxy_and_iterators(_Right);
	        _Swap_adl(_Myfirst, _Right._Myfirst);
	        _Swap_adl(_Mylast, _Right._Mylast);
	        _Swap_adl(_Myend, _Right._Myend);
	    }
	
	    void _Take_contents(_Vector_val& _Right) noexcept {
	        this->_Swap_proxy_and_iterators(_Right);
	        _Myfirst = _Right._Myfirst;
	        _Mylast  = _Right._Mylast;
	        _Myend   = _Right._Myend;
	
	        _Right._Myfirst = pointer();
	        _Right._Mylast  = pointer();
	        _Right._Myend   = pointer();
	    }
	
	    pointer _Myfirst; // pointer to beginning of array
	    pointer _Mylast; // pointer to current end of sequence
	    pointer _Myend; // pointer to end of array
	};

如上可知，在class _Vector_val中，通过接收由conditional_t判断得到的实际迭代器类型封装，来生成诸如：

    pointer _Myfirst; // pointer to beginning of array
    pointer _Mylast; // pointer to current end of sequence
    pointer _Myend; // pointer to end of array

等指示存储位置的数据封装。

而在vector类中，通过：

     _Compressed_pair<_Alty, _Scary_val> _Mypair;

封装了_Mypair来实现数据的封装，从而进一步结合allocator等实现vector的内存管理。


**4、数据结构--空间扩充插入等**

vector模板类这一块实现很复杂，具体来说，实现的函数或者模板函数包括:

    template <class... _Valty>
    pointer _Emplace_reallocate(const pointer _Whereptr, _Valty&&... _Val){};
	//
	template <class... _Valty>
    iterator emplace(const_iterator _Where, _Valty&&... _Val){};
	//
	//各种insert()函数
	//各种insert_range()函数
	//各种assign()和assign_range()函数
	//各种copy_assign()函数
	//_Resize_reallocate();
	//_Resize():
	template <class _Ty2>
    void _Resize(const size_type _Newsize, const _Ty2& _Val) { // trim or append elements, provide strong guarantee
        auto& _My_data      = _Mypair._Myval2;
        pointer& _Myfirst   = _My_data._Myfirst;
        pointer& _Mylast    = _My_data._Mylast;
        const auto _Oldsize = static_cast<size_type>(_Mylast - _Myfirst);
        if (_Newsize < _Oldsize) { // trim
            const pointer _Newlast = _Myfirst + _Newsize;
            _Orphan_range(_Newlast, _Mylast);
            _Destroy(_Newlast, _Mylast);
            _Mylast = _Newlast;
            return;
        }

        if (_Newsize > _Oldsize) { // append
            const auto _Oldcapacity = static_cast<size_type>(_My_data._Myend - _Myfirst);
            if (_Newsize > _Oldcapacity) { // reallocate
                _Resize_reallocate(_Newsize, _Val);
                return;
            }

            const pointer _Oldlast = _Mylast;
            _Mylast                = _Ufill(_Oldlast, _Newsize - _Oldsize, _Val);
            _Orphan_range(_Oldlast, _Oldlast);
        }

        // if _Newsize == _Oldsize, do nothing; avoid invalidating iterators
    }
	//_Reallocate_exactly();
	//_Clear_and_reserve_geometric();
	size_type _Calculate_growth(const size_type _Newsize) const {
        // given _Oldcapacity and _Newsize, calculate geometric growth
        const size_type _Oldcapacity = capacity();
        const auto _Max              = max_size();

        if (_Oldcapacity > _Max - _Oldcapacity / 2) {
            return _Max; // geometric growth would overflow
        }

        const size_type _Geometric = _Oldcapacity + _Oldcapacity / 2;

        if (_Geometric < _Newsize) {
            return _Newsize; // geometric growth would be insufficient
        }

        return _Geometric; // geometric growth is sufficient
    }

