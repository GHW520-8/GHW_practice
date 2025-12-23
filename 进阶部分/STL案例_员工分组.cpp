#include<iostream>							//10名员工放在vector容器 取出每个员工进行随机分组
#include<string>							//分组后将部门编号作为key 具体员工作为value 放入multimap容器
#include<vector>							//最后分部门显示员工信息
#include<map>
#include<ctime>
//开发部
const int develop{ 0 };
//美术部
const int fine_arts{ 1 };
//策划部
const int plan{ 2 };

//定义一个员工类存储姓名和工资
class worker {
public:
	std::string m_name;
	int m_salary;
};

//创建员工和工资
void create_worker(std::vector<worker>& v)
{
	//员工名
	std::string name{ "ABCDEFGHIJ" };
	//插入十个员工的姓名和工资
	for (int i= 0; i < 10; i++)
	{
		worker m_worker;
		m_worker.m_name = "员工";
		m_worker.m_name += name[i];
		m_worker.m_salary = rand() % 10001 + 10000;
		v.emplace_back(m_worker);
	}
}
//给员工分组
void set_group(std::vector<worker>& v,std::multimap<int,worker>& m)
{
	for (const auto& it : v)
	{
		int num = rand() % 3;
		m.emplace(num, it);
	}
}
//分部门打印输出
void print_group(std::multimap<int, worker>& m)
{
	std::cout << "开发部：" << std::endl;
	std::cout << "姓名\t" << "工资" << std::endl;
	//查找函数判断所在部门
	auto it= m.find(develop);
	//计数函数统计部门人数
	int count = m.count(develop);
	//定义索引配合count遍历
	int index = 0;
	//遍历容器 同一个部门
	for (; it != m.end() && index <= count; it++, index++)
	{
		std::cout << (*it).second.m_name << '\t' << (*it).second.m_salary << std::endl;
	}

	std::cout << std::endl << "--------我是分割线-------" << std::endl << std::endl;

	std::cout << "美术部：" << std::endl;
	std::cout << "姓名\t" << "工资" << std::endl;
	it = m.find(fine_arts);
	count = m.count(fine_arts);
	index = 0;
	for (; it != m.end() && index <= count; it++, index++)
	{
		std::cout << (*it).second.m_name << '\t' << (*it).second.m_salary << std::endl;
	}

	std::cout << std::endl << "--------我是分割线-------" << std::endl << std::endl;

	std::cout << "策划部：" << std::endl;
	std::cout << "姓名\t" << "工资" << std::endl;
	it = m.find(fine_arts);
	count = m.count(fine_arts);
	index = 0;
	for (; it != m.end() && index <= count; it++, index++)
	{
		std::cout << (*it).second.m_name << '\t' << (*it).second.m_salary << std::endl;
	}
}
int main()
{
	//创建随机数种子
	srand((unsigned int)time(nullptr));
	//vector容器存储员工
	std::vector<worker> v;
	create_worker(v);
	//给员工分组
	std::multimap<int, worker> m;
	set_group(v,m);
	print_group(m);
	system("pause");
	return 0;
}