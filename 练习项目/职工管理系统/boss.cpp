#include"boss.h"
//使用构造函数给成员变量赋值
boss::boss(int id, std::string name, int deptid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = deptid;
}
//重写显示函数和岗位名称函数
void boss::show_info()
{
	std::cout << this->m_id << '\t' << this->m_name << '\t'
	<< this->get_postname()<<std::endl;
}

//获取岗位名称
std::string boss::get_postname()
{
	return static_cast<std::string>("总裁");
}