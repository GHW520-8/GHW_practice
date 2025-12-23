//静态变量  在普通变量前加上 static 就属于静态变量
//静态变量是属于全局区里的，它的地址也是接近全局区

//代码区：存放函数的二进制代码，机器指令 由系统管理
//全局区(静态区/数据区)：全局变量，静态变量，字符串常量，const修饰的全局变量(全局常量) 程序运行完后自动释放
//栈区：局部变量，函数参数，被const修饰的局部变量(局部常量)	函数执行完自动释放
//堆区：动态分配对象 使用new关键字开辟内存 用户手动创建和释放(delete) 如果不释放可能会造成内存泄露
#include<iostream>
void t_static() {
	static int x = 10;//定义静态变量
}
int* test() {//指针函数，本质上是一个函数，返回值是一个指针  
	int* p=new int(10);//开辟堆区，注意格式：new 类型(值)
	return p;
}
void test3() {
	int* arr = new int[10];//在堆区里开辟一个数组，注意括号
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	delete[] arr;//注意和普通变量的释放方式的区别
}
int plus(int a, int b) {
	return a + b;
}
int minus(int a, int b) {
	return a - b;
}
int main() {
	int* p = test();
	std::cout << *p << std::endl;
	delete p;//释放堆区里的数据p
	int (*test2)(int, int)=NULL;//函数指针，本质上是一个指针，就是一个指向函数的指针
	test2 = plus;				//改变指向，相当于有了指向函数的功能
	int sum = test2(1, 2);		//调用函数
	test2 = minus;
	int pop = test2(5, 3);
	system("pause");
	return 0;
}