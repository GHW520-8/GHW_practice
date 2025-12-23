#include<iostream>
#include<fstream>
class person
{
public:
	char m_name[64];	//字符数组它的内存布局，大小都是是固定的，方便快速直接的读写
	int m_age;			//而C++字符串是不固定的，包含指针，可能会涉及堆的问题，比较慢
};
void test01()
{
	//[1]创建写入流对象  使用构造函数
	std::ofstream ofs("person.txt", std::ios::out | std::ios::binary); //打开二进制文件并给予写的权限

	//[2]打开文件
	//ofs.open("person.txt", std::ios::out | std::ios::binary);
	
	//[3]写入数据
	person p = { "小亮",15 };						//原型函数：ostream& write(const char* s,streamsize n);
	ofs.write(reinterpret_cast<const char*>(&p), sizeof(person));  
					      //输入固定格式：对象.write(reinterpret_cast<const char*>(&数据),长度);
						  //这里也可以使用C风格的(const char*)强制转换，但不建议，因为不够安全
	//[4]关闭文件
	ofs.close();
}
int main()
{
	test01();
	system("pause");
	return 0;
}