#include<iostream>					//下面实现代码不能同时运行，没有注释掉是因为方便查看逻辑
#include<fstream>					//报错是正常的，不要改！！！要运行自己注释掉
#include<string>
void test()
{
	//[1]创建读的流对象
	std::ifstream ifs;

	//[2]打开文件并判断是否打开成功  打开格式：" ifs.open("文件路径",打开方式); "
	//打开  
	ifs.open("test.txt", std::ios::out | std::ios::in);
	//判断
	if (!(ifs.is_open()))		//语句 " ifs.is_open() "可以判断文件是否打开，并返回" bool "类型的值
	{
		std::cout << "文件打开失败-_-" << std::endl;
		return;
	}

	//[3]读数据
	//第一种方式 定义字符数组结合循环输出
	char arr[1024] = {};
	while (ifs >> arr)		//注意：这里的右移运算符" >> "是读取，读取完后返回假
	{
		std::cout << arr << std::endl;
	}

	//第二种方式 使用"ifs.getline()"函数结合循环输出
	char arr[1024] = {};					//这里使用的是ifstream类里的成员函数 ifs.getline()
	while (ifs.getline(arr, sizeof(arr)))   //"ifs.getline(数组名,读取的字符数)" 它每次读取一行的数据
	{									    //这里为了避免出错使用sizeof运算符准确返回长度
		std::cout << arr << std::endl;
	}
	
	//第三种方式  定义字符串使用全局函数getline()输出
	std::string arr;
	while (std::getline(ifs,arr))	//格式：" getline(输入流,字符串） "这里的输入流可以是std::cin...
	{							
		std::cout << arr << std::endl;
	}
	
	//第四种方式 通过get()函数单个字符输出 ( 不推荐使用！！！)
	char ch1;
	while ((ch1 = ifs.get()) != EOF)		//注意get()也是成员函数，" EOF "是判断是否到文件尾
	{
		std::cout<<ch1;						//不用加换行符endl 文件里有换行符会被读取
	}
	//[4]关闭文件
	ifs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}