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
