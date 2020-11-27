https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/volatile

	volatile:修饰不稳定变量，使得程序在调用该变量时每次必须保证从内存中取值，而不是使用寄存器中的值；
	被volatile修饰的变量，在对其进行读写操作时，会引发一些可以观测的副作用。而这些可以观测的副作用，
是由程序之外的因素决定的。
	volatile关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素(操作系统、硬件、
其他线程)更改。所以使用volatile告诉编译器不应该针对这样的变量(对象)进行优化。
	volatile关键字声明的变量，每次访问都必须从内存中取值(相反，没有被volatile修饰的变量，可能由于编
译器的优化，从CPU寄存器中取值)。
	const可以是volatile(如只读的状态寄存器，是volatile因为可能被意想不到地改变，是const因为程序不应该
试图去修改它)。
	指针可以是volatile,如中断控制程序可能修改的指向缓存区域的指针等。