#ifndef _INLINE
class A
{
private:
	int A_x;
	int A_y;
public:
	A(int x, int y):A_x(x), A_y(y){}
	void f1(int x);
	void Foo(int x, int y);//隐式内联函数定义
};
#endif // !_INLINE
