#include<iostream>									//queue容器(队列容器)
#include<queue>							//队列是一种先进先出的数据结构，他有两个出口
							//他的队头队尾可以被访问，中间不能，因此也无法遍历，可以返回元素个数和判断是否为空
							//只能在队尾输入数据，队头删除数据(双端队列deque可以头尾都操作)    队列进入数据叫做入队，出数据叫做出队
void test01()
{
	std::queue<int> q;
	//queue容器的插入  push(elem) 向队尾添加数据
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	std::cout << "输出前元素个数：" << q.size() << std::endl;

	//back()返回队尾的元素
	std::cout << "back: " << q.back() << std::endl;

	while (!q.empty())
	{
		//front()返回队头的元素
		std::cout << "front: "<< q.front() << std::endl;		//可以发现是原来的顺序，因为先进入的数据会先输出 这就是先进先出 参考排队

		//pop()将队头移除一个元素
		q.pop();
	}

	std::cout << "输出后元素个数：" << q.size() << std::endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}