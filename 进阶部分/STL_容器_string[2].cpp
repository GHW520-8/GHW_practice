#include<iostream>											//字符串的查找 替换 比较
#include<string>											//具体原型和介绍往下翻 要运行自己注释掉介绍

//常用的查找
void test01()
{
	std::string str1 = "abcdefgde";
	//find() 查找字符串出现的位置，可以指定从哪里开始找，默认为 0 (从左往右找)
	int pos = str1.find("de");
	//如果找到了字符串，返回位置，没找到返回-1
	if (pos == -1)
	{
		std::cout << "没找到 pos=" << pos << std::endl;
	}
	else
	{
		std::cout << "找到了 pos=" << pos << std::endl;
	}
	//rfind() 和find()基本一致，但是它是从右往左赵
	pos=str1.rfind("de");
	std::cout << "rfind  pos=" << pos << std::endl << std::endl;
}

//常用的替换
void test02()
{
	std::string str = "abcdefg";
	//从第1个位置(下标为1)开始的3个字符替换为字符串
	str.replace(1, 3, "1111");
	std::cout << "repalce " << str << std::endl << std::endl;
}

//字符串之间的比较
void test03()
{
	std::string str1 = "abc";
	std::string str2 = "abcd";
	//如果相同返回 0，如果当前比传入的大 返回 1，小返回 -1 (它是逐位使用ASCLL码比较的)
	int num = str1.compare(str2);
	std::cout << "比较结果 "<< num << std::endl;
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
	/
	"查找和替换"
		"左到右"  找到返回下标  找不到返回-1
		--int find(const string & str, int pos = e) const		  查找str第一次出现位置, 从pos开始查找
		--int find(const char* s, int pos = e)					  const查找s第一次出现位置, 从pos开始查找
		--int find(const char* s, int pos, int n)				  const从pos位置查找s的前n个字符第一次位置
		--int find(const char c, int pos = e)					  const查找字符c第一次出现位置
		"右到左"
		--int rfind(const string& str, int pos = npos)			  const查找str最后一次位置, 从pos开始查找
		--int rfind(const char* s, int pos = npos)				  const查找s最后一次出现位置, 从pos开始查找
		--int rfind(const char* s, int pos, int n)				  const从pos查找s的前n个字符最后一次位置
		--int rfind(const char c, int pos = e)					  const查找字符C最后一次出现位置

		"替换"   
		--std::string& replace(int pos, int n, const string& str) 替换从pos开始n个字符为字符串str
		--string& replace(int pos, int n, const char* s)		  替换从pos开始的n个字符为字符串S

	"字符串比较"   等于返回0  小于返回 - 1  大于返回1
		--int cpmpare(const string &s) const                      当前字符串与传入的字符串比较(string)
		--int compare(const char*s) const						  当前字符串与传入的字符串比较(char*)
	*/
