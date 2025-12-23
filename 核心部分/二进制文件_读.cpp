#include<iostream>
#include<fstream>
class person
{
public:
	char m_name[64];
	int m_age;
};
void test01()
{
	//[1]创建读取流对象并打开
	std::ifstream ifs("person.txt", std::ios::in | std::ios::binary); //打开二进制文件并给予读的权限

	//[2]判断
	if (!(ifs.is_open()))		
	{
		std::cout << "文件打开失败-_-" << std::endl;
		return;
	}

	//[3]读取文件
	person p;
	ifs.read(reinterpret_cast<char*>(&p), sizeof(p)); //原型函数：istream& read(char* buffer,int len);
	//固定格式：对象.read(reinterpret_cast<char*>(&数据),字节);
	std::cout << "姓名：" << p.m_name << '\t' << "年龄：" << p.m_age << std::endl;
	
	//[4]关闭文件
		ifs.close();
}
int main()
{
	test01();
	system("pause");
	return 0;
}