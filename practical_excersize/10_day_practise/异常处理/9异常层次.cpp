#include<iostream>
using namespace std;

//异常层次中，子类不能顶替父类异常被catch
//但是父类可以顶替子类异常被catch
class BasicException {
public:
	char* Where() { return "BasicException..."; }
};
class FileSysException :public BasicException {
public:
	char *Where() { return "FileSysException..."; }
};
class FileNotFound :public FileSysException {
public:
	char *Where() { return "FileNotFound..."; }
};
class DiskNotFound :public FileSysException {
public:
	char *Where() { return "DiskNotFound..."; }
};
int main() {
	try {
		//FileSysException
		throw FileSysException();
	}
	catch (DiskNotFound p) { cout << p.Where() << endl; }
	catch (FileNotFound p) { cout << p.Where() << endl; }//不能顶替父类被捕获
	catch (FileSysException p) { cout << p.Where() << endl; }
	catch (BasicException p) { cout << p.Where() << endl; }
	try {
		//BasicException
		throw DiskNotFound();
	}
	catch (BasicException p) { cout << p.Where() << endl; }//可以顶替子类被捕获
	catch (FileSysException p) { cout << p.Where() << endl; }
	catch (DiskNotFound p) { cout << p.Where() << endl; }
	catch (FileNotFound p) { cout << p.Where() << endl; }

	system("pause");
}