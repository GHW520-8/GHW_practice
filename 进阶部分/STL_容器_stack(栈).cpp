#include<iostream>								//stack容器(栈容器)
#include<stack>						//栈是一种先进后出的数据结构，他只有一个出入口
						//他只有顶部的数据才能被外部访问，因此无法遍历，但是可以返回元素个数和判断是否为空
						//栈进入数据叫做进栈，出数据叫做出栈
void test01()
{									//注意：stack容器返回头部使用的是top() 不是front()!!!
	std::stack<int> s;
	//stack容器的插入  push(elem) 向栈顶添加数据
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	std::cout << "输出前元素个数：" << s.size() << std::endl;
	while (!s.empty())
	{
		//top()返回栈顶的元素
		std::cout << s.top() << std::endl;		//可以发现是倒序，因为后加入的数据会先被输出 这就是先进后出

		//pop()将栈顶的第一个元素移除
		s.pop();
	}

	std::cout << "输出后元素个数：" << s.size() << std::endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}