**0、导语**

使用的IDE为visual studio 2019, 支持CPP17.

**1、std::array**

    template <class _Ty, size_t _Size>
	class array { // fixed size array of values
	public:
	    using value_type      = _Ty;
	    using size_type       = size_t;
	    using difference_type = ptrdiff_t;
	    using pointer         = _Ty*;
	    using const_pointer   = const _Ty*;
	    using reference       = _Ty&;
	    using const_reference = const _Ty&;
	
	    using iterator       = _Array_iterator<_Ty, _Size>;
	    using const_iterator = _Array_const_iterator<_Ty, _Size>;
	
	    using reverse_iterator       = _STD reverse_iterator<iterator>;
	    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;
	}
    
其中，reverse_iterator使用迭代器适配器实现，并作为rbegin和rend操作的迭代器。


**2、assignment**

array源码中提供assign函数和fill函数，涉及对array的赋值操作，但是没有找到array类的ctor。

    #if _HAS_TR1_NAMESPACE
    _DEPRECATE_TR1_NAMESPACE void assign(const _Ty& _Value) {
        _STD fill_n(_Elems, _Size, _Value);
    }
	#endif // _HAS_TR1_NAMESPACE

    _CONSTEXPR20 void fill(const _Ty& _Value) {
        _STD fill_n(_Elems, _Size, _Value);
    }

由上可见，array源码中通过调用std::fill\_n函数实现对array的赋值和填充。打开fill_n函数所述文件xutility:

    #if _HAS_IF_CONSTEXPR
	template <class _OutIt, class _Diff, class _Ty>
	_CONSTEXPR20 _OutIt fill_n(_OutIt _Dest, const _Diff _Count_raw, const _Ty& _Val) {
    // copy _Val _Count times through [_Dest, ...)
    _Algorithm_int_t<_Diff> _Count = _Count_raw;
    if (0 < _Count) {
        if constexpr (_Is_vb_iterator<_OutIt, true>) {
            const auto _Last = _Dest + static_cast<typename _OutIt::difference_type>(_Count);
            _Fill_vbool(_Dest, _Last, _Val);
            return _Last;
        } else {
            auto _UDest = _Get_unwrapped_n(_Dest, _Count);
            if constexpr (_Fill_memset_is_safe<decltype(_UDest), _Ty>) {
	#ifdef __cpp_lib_is_constant_evaluated
                if (!_STD is_constant_evaluated())
	#endif // __cpp_lib_is_constant_evaluated
                {
                    _Fill_memset(_UDest, _Val, static_cast<size_t>(_Count));
                    _UDest += _Count;
                    _Seek_wrapped(_Dest, _UDest);
                    return _Dest;
                }
            }

            for (; 0 < _Count; --_Count, (void) ++_UDest) {
                *_UDest = _Val;
            }

            _Seek_wrapped(_Dest, _UDest);
        }
    }
    return _Dest;
	}

从上述代码中，fill_n函数内部计算一个_Diff类型的位置指示，类型为：typename _OutIt::difference_type。

计算得到该类型后，进一步使用更底层的函数进行数值填充，并返回填充后得到的新的迭代器。

**3、对size为0的特化**

对于array的size初始化为0时，该编译器版本对其实现如下特化版本array：

    template <class _Ty>
	class array<_Ty, 0> {
	public:
	    using value_type      = _Ty;
	    using size_type       = size_t;
	    using difference_type = ptrdiff_t;
	    using pointer         = _Ty*;
	    using const_pointer   = const _Ty*;
	    using reference       = _Ty&;
	    using const_reference = const _Ty&;
	
	    using iterator               = _Array_iterator<_Ty, 0>;
	    using const_iterator         = _Array_const_iterator<_Ty, 0>;
	    using reverse_iterator       = _STD reverse_iterator<iterator>;
	    using const_reverse_iterator = _STD reverse_iterator<const_iterator>;
	
		#if _HAS_TR1_NAMESPACE
	    _DEPRECATE_TR1_NAMESPACE void assign(const _Ty&) {}
		#endif // _HAS_TR1_NAMESPACE
	
	    _CONSTEXPR20 void fill(const _Ty&) {}

在该特化版本中，需要注意的是，_Array_iterator、_Array_const_iterator以及另外两种反向迭代器的size均为0。

并且， 前述assign和fill函数没有实现。

此外，运算符函数operator[]直接返回_Elems[0]的引用(reference或者const_reference)。

