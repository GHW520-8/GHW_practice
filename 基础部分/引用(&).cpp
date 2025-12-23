#include<iostream>
using namespace std;
int& test() {			//不要返回局部变量的引用,栈区的数据在局部范围运行完就释放
	int a = 10;			//局部变量存储在四区的"栈区"
	return a;		
}
int& test2() {			//全局区是在系统运行完释放，也就是所有程序运行完
	static int a = 10;	//当定义为静态变量的时候可以正常使用
	return a;			//因为静态变量存储在四区的"全局区"
}
void test3(const int &val) {	//用来修饰形参的场景，利用常量防止误操作
	//val = 888;
	cout << "val=" << val << endl;
}
int main() {			//引用就相当于一个指针常量，编译器会自动转换
	int a = 10;
	int& ref = a;//引用的普通写法和赋值
	ref = 0;
	cout << a << '\t'<<ref << endl;	//引用是一个别名，原变量和别名都会影响的内存中的数据
	const int& ref2 = 10;// 引用不能直接赋值，必须要分配一个合法的内存空间
	cout << "ref2=" << ref2 << endl;
	//加上const，其实就是编译器加了一个临时变量将值存储，再赋值给引用,并且不能修改
	//ref2 = 100;

	int& ref3 = test();
	cout << "ref3=" << ref3 << endl;//出现乱码
	int& ref4 = test2();
	cout << "ref4=" << ref4 << endl;//无论多少次都能正确输出
	cout << "ref4=" << ref4 << endl;
	cout << "ref4=" << ref4 << endl;

	test2() = 1000;		//如果函数的返回值是一个引用，那么这个函数也可以作为左值
	cout << "ref4=" << ref4 << endl;//可以发现数据发生了变化，其实就是对别名进行了操作
	cout << "ref4=" << ref4 << endl; 
	cout << "ref4=" << ref4 << endl;
	int val = 100;
	test3(val);
	system("pause");
	return 0;
}