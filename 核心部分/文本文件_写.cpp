#include<iostream>
#include<fstream>			//文本文件：文件以文本的ASCLL码存储在计算机中，用户可以读懂
void test01()				//头文件三大类："fstream"：读写操作  "ofstream"：写入操作  "ifstream"：读取操作
{
	//[1]创建流对象，写文件必备 ( 这里是写的流对象 )
	std::ofstream ofs;		

	//[2]指定打开方式			 //打开文件格式："ofs.open("文件路径",打开方式);"  （详细打开方式命令往下翻）
	ofs.open("test.txt", std::ios::out); //如果没有指定路径，默认和项目文件路径一致 路径例如：S:\VS\study\...

	//[3]写入数据						 //写入格式："ofs << "写入的数据";
	ofs << "姓名：小光" << std::endl;	 //注意：在这里左移运算符" << "是输入 换行符"endl"也能写入文件内
	ofs << "性别：男" << std::endl;		 
	ofs << "年龄：14" << std::endl;

	//[4]关闭文件						
	ofs.close();			//关闭文件固定代码  写入完一定要关闭文件，否则数据有可能会丢失
							//因为写入的数据是存放在缓存区里的，直到缓存区满或者关闭时才会存入磁盘
}
int main()					
{
	test01();
	system("pause");
	return 0;
}

/*  打开方式			解释  ( 如果文件不存在都会自动创建 )		    操作符位或 " | " 可以组合多个打开模式

	ios::in				为了读取而打开文件 ( 只有读取权限 )			     ios::in | ios::out

	ios::out			为了写入而打开文件 ( 在开头写入 )				 ios::out | ios::trunc...

	ios::ate			打开文件并移动到文件尾 ( 没有权限，需组合使用 )

	ios::app			追加到文件尾再写入 ( 在末尾写入 )

	ios::trunc			如果文件存在，清空后再创建 ( 没有权限，需组合使用 )

	ios::binary			二进制方式打开文件 ( 没有权限，需组合使用 )
*/