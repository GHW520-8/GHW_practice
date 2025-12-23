#include<iostream>
class abs_stractDrinking {
public:
	//煮水								//因为基类中的虚函数实现毫无意义，主要作用就是调用派生的重写的函数
	virtual void boil() = 0;			//所以可以使用纯虚函数  "virtual 返回值类型 函数名(形参)=0;"
	//冲泡								//只要有一个纯虚函数，这个类就叫做抽象类，  抽象类无法实例化对象
	virtual void brew() = 0;			//派生类必须重写纯虚函数，否则会继承纯虚函数，导致无法实例化对象
	//倒水
	virtual void pour() = 0;
	//加入辅料
	virtual void put_something() = 0;
	//制作饮品							//当我们使用全局函数调用时会非常麻烦
	void make_drinking() {				//而定义成员函数再调用所有虚函数,此时就只需要调用成员函数即可
		boil();							//从而使代码变得简洁，这叫做 "模板方法模式"
		brew();
		pour();
		put_something();
	}
};
class coffee :public abs_stractDrinking {
	//煮水								
	virtual void boil()	{  //必须重写纯虚函数
		std::cout << "把水煮开" << std::endl;
	}
	//冲泡								
	virtual void brew() {
		std::cout << "冲泡咖啡" << std::endl;
	}
	//倒水
	virtual void pour() {
		std::cout << "倒入开水" << std::endl;
	}
	//加入辅料
	virtual void put_something() {
		std::cout << "加一块方糖和牛奶" << std::endl;
	}
};
class tea :public abs_stractDrinking {
	//煮水								
	virtual void boil() {
		std::cout << "把矿泉水煮开" << std::endl;
	}
	//冲泡								
	virtual void brew() {
		std::cout << "冲泡茶叶" << std::endl;
	}
	//倒水
	virtual void pour() {
		std::cout << "倒入开水" << std::endl;
	}
	//加入辅料
	virtual void put_something() {
		std::cout << "加入枸杞" << std::endl;
	}
};
void do_make(abs_stractDrinking* abs) {		//这里就相当于：abs_stractDrinking* abs= *coffee / *tea;											//注意: 向上类型转换不等于实例化抽象类对象	
	abs->make_drinking();					//它只是改变指针/引用的类型，指向已存在的对象
	delete abs;								//让基类接口可以操作派生类对象
}
void test01() {
	do_make(new coffee);
}
void test02() {
	do_make(new tea);
}
int main() {
	test01();
	std::cout << "---------------我是分割线--------------" << std::endl;
	test02();
	return 0;
}