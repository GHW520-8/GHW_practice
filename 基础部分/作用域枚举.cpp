#include<iostream>
//颜色枚举
enum struct color {
	red,
	yellow,
	green
};
//信号灯枚举
enum struct traffic : uint8_t {
	red,
	yellow,
	green
};

int main()
{
	//给枚举变量赋值必须加上枚举类型的作用域
	color c = color::red;
	//可以发现没有出现命名冲突
	traffic t = traffic::red;
	//作用域枚举不支持隐式转换,必须类型转换后才能赋值
	int value = (int)c;
	return 0;
}