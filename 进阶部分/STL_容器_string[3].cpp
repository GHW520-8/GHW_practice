#include<iostream>											//字符串的插入 删除 读取 子串获取
#include<string>
//字符串的插入和删除
void test01()
{
	std::string str = "Hello ";							
	//插入 在第6个位置插入字符串               原型：--string& insert(int pos,const char* s)       在第pos个位置插入字符串(char*)
	str.insert(6, "world!");					 //	 --string& insert(int pos, const string& str)  在第pos个位置插入字符串(string)
	std::cout << str << std::endl;				 //  --string& insert(int pos,int n,char c)		   在第pos个位置插入n个单字符

	//删除										     --string& erase(int pos,int n = npos)         删除从pos个位置开始的n个字符
	str.erase(6, 4);							
	std::cout << str << std::endl;
}

//字符串的读取
void test02()
{
	std::string str = "hello world";
	//size() 返回字符串的长度
	for (int i = 0; i < str.size(); i++)
	{
		//通过[] 读取单个字符
		std::cout<<str[i] << " ";			//	原型：--char& operator[](int n) 通过[]方式读取
	}
	std::cout << std::endl;

	for (int i = 0; i < str.size(); i++)
	{
		//通过at(下标) 读取单个字符
		std::cout << str.at(i) << " ";      //  原型：--char& at(int n) 通过at方式读取
	}
	std::cout << std::endl;					//  同时他们也可以修改 str[0]='q' str.at(0)='w'

}

//字符串的获取(求子串)
void test03()
{
	//截取邮箱的用户名
	std::string str1 = "厉飞雨@163.com";
	//通过find()函数找到@的下标返回
	int pos=str1.find('@');
	//截取字符，他是截取的个数而不是下标
	std::string str2 = str1.substr(0,pos);	//  原型：string& substr(int pos=0,int  n = npos) const 返回pos位置开始的n个字符
	std::cout << str2 << std::endl;
}

int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}