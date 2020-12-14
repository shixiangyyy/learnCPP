cout usage:
cout是C++中的标准输入输出流“对象”；
配合流插入运算符，将运算符右侧的项目插入到输出流中。

以不同进制输出数字：
引入iomanip库
cout << dec << i << endl;
cout << oct << i << endl;
cout << hex << i << endl;

C++中cout.setf()的用法：
setf() setiosflag()：设置输出格式状态，括号中应该给出格式状态，内容与控制符setiosflag()括号中内容相同
https://blog.csdn.net/SMF0504/article/details/51469300

ios::left
ios::right
ios::internal 数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充
ios::dec
ios::oct 8进制
ios::hex 16
ios::showbase 强制输出整数的基数，八进制以0开头，十六进制以0x开头
ios::showpoint 强制输出浮点数的小点和尾数0
ios::uppercase 在以科学计数法输出E和十六进制输出字母X时，以大写表示
ios::showpos 输出正数时，给出+号
ios::scientific 设置浮点数以科学计数法显示
ios::fixed 设置浮点数以固定位数显示
ios::unitbuf 每次输出后刷新所有的流
ios::stdio 每次输出后清楚stdout和stderr