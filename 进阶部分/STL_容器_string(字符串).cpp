#include<iostream>											//string 容器
#include<string>							//string是一个c++风格的字符串，他本质上就是一个类				
											//他内部封装了char*,管理这个字符串，是一个char*型的容器
											//内部有许多成员方法 例如：find查找 copy拷贝 delete删除 repalce替换 insert插入等
												//他管理char*分配的内存，我们不需要对他任何操作，他内部会负责
int main()
{
/
	"string的构造函数"
	--string() 创建空的字符串 string str(默认构造)   --string(const char* s) 使用字符串s初始化 string str("111") (有参构造)
	--string(const string & str)  string str1(str)(拷贝构造)    --string(int n, char c) 使用"n"个字符"c"初始化 string str(4, "w")  wwww

	"string的赋值操作"
	--string & operator=(const char* s)      char* 类字符串给当前字符串赋值		    str = "hello world"
	--string & operator=(const string & s)   字符串赋值(string)						str1 = str2
	--string & operator=(char c)             将单个字符赋给字符串					str = 'c'

	--string & assign(const char* s)         字符串赋值(char)						str.assign("hello world")
	--string & assign(const char* s, int n)  把字符串s的前n个字符赋给当前字符串		str1.assign("hello world", 5)  hello
	--string & assign(const string & s)      字符串赋值给当前的字符串(string)		str.assign(str1) hello
	--string & assign(int n, char c)         将n个字符c赋值							str.assign(5, 'w') wwwww

	"string的字符串拼接"
	--string & operator+=(const char* str)             重载 += 操作符(字符串)			string str1 = "你" str1 += "是大聪明"  你是大聪明
	--string & operator+=(const char c)				   重载 += 操作符(单个字符)			stl += '：' 你是大聪明：
	--string & operator+=(const string & str)          重载 += 操作符					string str2 = "c++" str1 += str2  你是大聪明：c++

	--string& append(const char* s)					   把字符串s连接到结尾				string str3="I LOVE" str3.append("python") I LOVE python
	--string& append(const char* s，int n)			   把字符串s的前n个字符连接到结尾	str3.append("and llll",3) I LOVE python and
	--string& append(const string & s)                 同operator +=(const string& str) str3.append(str2) I LOVE python and c++
	--string& append(const string & s, int pos, int n) 字符串s的第pos位置取n个字符      str4.append(str3,6,6)  python
/
	system("pause");
	return 0;
}