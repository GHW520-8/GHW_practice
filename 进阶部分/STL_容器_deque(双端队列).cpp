								//deque容器的操作与vector基本无异，主要就是多了头部(front)的操作	
										//下面为了偷懒，呃...不是...是简洁代码，就不写重复的了
#include<iostream>		//deque容器就是一个双端数组 (也可以叫双端队列），可以对头尾进行插入删除操作
#include<deque>			//他对头部插入删除的效率比vector高，但是访问比vector慢
#include<algorithm>		//因为他内部是一个中控器来维护缓冲区的内容，缓冲区存放的是真实数据
						//他维护的其实是每个缓冲区的地址，而这些地址是连续的存储在中控器里，
						//所以看起来像连续的空间，但缓冲区里的数据可能是不连续的
						//他会在头部预留内存空间供我们插入删除，数据就不必后移，这使得在头部比vector效率高
						//但是他访问需要通过中控器去查找缓冲区的地址，然后再在缓冲区去查找元素，需要二次寻址
//打印输出
void print_deque(const std::deque<int>& d) //定义常量防止修改值 
{
	//这里就相当于使用了只读权限的迭代器
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it = 100;
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
				
void test01()
{
	std::deque<int> d;
	for (int i = 10; i > 0; i--)
	{
		d.push_back(i);
	}
	std::cout << "原数据：" << std::endl;
	print_deque(d);

	//在头部插入单个数据
	d.push_front(666);
	print_deque(d);

	//删除头部数据
	d.pop_front();
	print_deque(d);

	//这里删除函数vector和deque都一致，注意的是，使用erase()函数删除完后会返回下一个数据的位置，返回的是迭代器
	std::deque<int>::iterator it=d.erase(d.begin(),d.begin()+2);
	print_deque(d);
	//此时迭代器指向第一个元素
	std::cout << "返回迭代器指向：" << std::endl;
	std::cout << *it << std::endl;

	//deque和vector都可以使用front()访问第一个元素
	std::cout << "front()函数：" << std::endl;
	std::cout << d.front() << std::endl;

	//排序算法，默认升序
	std::cout << "升序排序后数据：" << std::endl;
	sort(d.begin(), d.end());
	print_deque(d);
}
int main()
{
	test01();
	system("pause");
	return 0;
}