#include<iostream>
#include<string>
using namespace std;
int main() {
	struct student {//结构体定义关键字不可以省略
		string name;
		int age;
		double score;
	}s3;
	//赋值一
	student s1;//结构体变量创建时关键字可以省略
	s1.name = "张三";
	s1.age = 14;
	s1.score = 99.5;
	cout << s1.name << '\t' << s1.age << '\t' << s1.score << endl;//使用"."访问结构体成员
	//二
	struct student s2  { "李四",15,89.5 };//C++11标准往后，有花括号的赋值可以去掉等号
	//花括号里为空则全部默认为0
	cout << s2.name << '\t' << s2.age << '\t' << s2.score << endl;
	//三
	s3.name = "王五";
	s3.age = 16;
	s3.score = 100.0;
	cout << s3.name << '\t' << s3.age << '\t' << s3.score << endl;
	system("pause");
	return 0;
}