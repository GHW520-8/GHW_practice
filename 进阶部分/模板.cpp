#include<iostream>				   					//函数模板----最下面还有！！！
									//template 翻译为：模板   声明创建模板
//用于交换的函数模板				//typename 翻译为：类型名  代表后面的符号为数据类型，可以使用class代替
template<typename T>				//T-- 通用的数据类型，可替换，通常为大写字母
void my_swap(T & a,T & b) {						//普通函数可以发生隐式类型转换
	T temp = a;		//注意写法					//函数模板： 自动类型推导不能发生隐式类型转换
	a = b;										//显示指定类型可以发生隐式类型转换
	b = temp;
}
//在使用函数模板前必须声明模板
template<typename T>
void my_sort(T arr[], int len) {
	//选择排序
	for (int i = 0; i < len; i++) {
		//假设第一个数为最小值
		int min = i;
		for (int j = i + 1; j < len; j++) {
			//依次往后遍历数组，直到找到比它小的数
			if (arr[min] > arr[j]) {
				//存储最小值下标
				min = j;
			}
		}
		if (min != i) {
			//只要值发生了改变就说明找到了，调用换位函数
			my_swap(arr[min],arr[i]);
		}
	}
}
//打印模板函数
template<typename T>
void print(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

//字符串数组排序
void test01() {
	char arr[] = "cabdegf";
	//这里-1是因为最后有个'\0'结束符实际上是8位
	int len = sizeof(arr) / sizeof(char)-1;
	my_sort(arr, len);				//自动类型推导 因为定义了实参的类型，编译器会根据参数自己判断
	print(arr, len);				//必须推导出一致的数据类型T才能使用
}									//假如形参是T&a T&b  实参为(int) a,(char) b 此时编译器就无法判断

//整型数组排序
void test02() {
	int arr[] = { 2,4,5,3,1,6,7 };
	int len = sizeof(arr) / sizeof(int);
	my_sort(arr, len);				//显式指定类型格式：" 函数名<数据类型>(参数); 例：myswap<int>(a,b); "
	print(arr, len);				//显式指定必须明确指定出T的数据类型才能使用
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
//如果函数模板和普通函数重载时，如果两个函数都能实现，优先调用普通函数

//如果函数模板能更好的匹配实参，优先调用函数模板  比如我普通函数的形参是整型类型，实参却是字符型
//那么编译器会调用函数模板，就不必去做隐式类型转换了(聪明的编译器宝宝，学会偷懒了)

//也可以使用" 空模板参数列表(<>) "来强制调用函数模板，例：myint<>(a, b);

//函数模板也可以发生重载，重载规则和函数重载规则一致
