#include<iostream>										//评委打分
#include<vector>								//十个评委分别给选手ABCDE打分
#include<deque>									//去除最高和最低，取平均
#include<string>								//分别使用vector容器和deque容器
#include<algorithm>
#include<ctime>
//选手类，定义并初始化姓名，分数
class person
{
public:
	person(std::string name,double score): m_name(name),m_score(score){}
	std::string m_name;
	double m_score;
};

//打印最后每个选手的分数
void print_score(std::vector<person>& v)
{
	for (std::vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << "姓名：" << it->m_name << '\t' << "分数：" << it->m_score << std::endl;
	}
}

//创建
void create_person(std::vector<person>& v)
{
	std::string p_name = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		//使用string容器的字符串拼接拼接姓名
		std::string name = "选手";
		name += p_name[i];
		int score = 0;
		//利用构造函数将姓名和分数初始化封装
		person p(name, score);
		//将person类的对象放入容器
		v.push_back(p);
	}
}

//设置分数
void set_score(std::vector<person>& v)
{
	//外层循环控制 使每个选手都要被打十次分
	for (std::vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//使用deque容器存放分数
		std::deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			//使用随机数打十次分
			int score = rand() % 41 + 60;
			//每次分数放入deque容器
			d.push_back(score);
		}
		//将deque容器里的分数升序排序
		sort(d.begin(), d.end());
		//删除最高分和最低分
		d.pop_front();
		d.pop_back();
		int sum = 0;
		//遍历数据存放总和
		for (std::deque<double>::iterator it = d.begin(); it != d.end(); it++)
		{
			sum += *it;
		}
		//求取平均分
		double ave= sum / d.size();
		//将平均分存入person类
		it->person::m_score = ave;
	}
	
}
int main()
{
	//使用随机数种子保证每次随机数都不同
	srand((unsigned int)time(NULL));
	std::vector<person> v;
	create_person(v);
	set_score(v);
	print_score(v);
	system("pause");
	return 0;
}