#include"worker_manage.h"				
#include<conio.h>						//关于一些bug基本上解决了
//构造函数	 	                        //完结撒花！！！2025.10.29
w_manage::w_manage()                    //职工管理类，负责主要功能的实现
{
	std::ifstream ifs;
	ifs.open("worker_manage.txt", std::ios::in);
	//[1]文件不存在
	if (!ifs.is_open())
	{
		//将人数和数组指针初始化为零
		this->w_num = 0;
		this->w_array = nullptr;
		this->file_empty = true;		//为空时赋值为真
		ifs.close();
		return;
	}

	//[2]文件存在，但数据为空
	char ch;
	ifs >> ch;  //定义一个字符变量，在文件里右移一个字符，使用eof()函数判断是否到了文件末
	if (ifs.eof())
	{
		//将人数和数组指针初始化为零
		this->w_num = 0;
		this->w_array = nullptr;
		this->file_empty = true;		//为空时赋值为真
		ifs.close();
	}

	//[3]文件存在且不为空
	int num = this->get_num();		//将统计好的人数存储
	this->w_num = num;				//更新原人数
	this->w_array = new worker* [this->w_num];		//根据人数开辟新的空间
	this->w_init();					//文件存在时调用初始化函数初始化职工信息
}

//释放数据
void w_manage::delete_file()
{
	if (this->w_array != nullptr)
	{
		for (int i = 0; i < w_num; i++)
		{
			delete this->w_array[i];
		}
		delete[] this->w_array;
		this->w_array = nullptr;
		this->w_num = 0;
	}
}

//显示菜单
void w_manage::show_menu()
{
	std::cout << "####********************####" << std::endl;
	std::cout << "****欢迎使用职工管理系统****" << std::endl;
	std::cout << "####********************####" << std::endl;
	for (int i = 1; i < 10; i++)
	{
		for (int k = 0; k <= 10 - i; k++)
		{
			std::cout << ' ';
		}
		for (int j = 1; j < i * 2; j++)//输出等腰三角形
		{
			std::cout << '*';
		}
		for (int x = 1; x < 10 - i; x++)
		{
			std::cout << '#';
		}
		for (int y = 1; y < i; y++)//两个三角形合成一个平行四边形
		{
			std::cout << '#';
		}
		std::cout << std::endl;
	}
	std::cout << " **** (1) 添加职工信息 ####" << std::endl;//输出菜单，面向结果编程哈哈哈
	std::cout << " **** (2) 显示职工信息 ####" << std::endl;
	std::cout << " **** (3) 删除职工信息 **##" << std::endl;
	std::cout << " **** (4) 查找职工信息 ***#" << std::endl;
	std::cout << " **** (5) 修改职工信息 ****" << std::endl;
	std::cout << " **** (6) 职工记录排序 ****" << std::endl;
	std::cout << " **** (7) 清空全部文档 ****" << std::endl;
	std::cout << " **** (8) 恢复全部数据 ****" << std::endl;
	std::cout << " **** (0) 退出管理系统 ****" << std::endl;
	std::cout << " **************************" << std::endl;
	std::cout << " **************************" << std::endl;
}

//退出程序
void w_manage::exit_system()
{
	std::cout << "欢迎下次使用 >_< !" << std::endl;
	system("pause");
	exit(0);	//立即终止程序  使用0表示成功终止，非0则是异常终止
}				//因为系统隐式包含了头文件cstdlib,所以可以正常使用exit()函数

// 添加职工信息（修复：避免使用已释放的 this->w_array；先使用 new_array 进行检查，最后再释放旧数组）
void w_manage::addinfo()
{
	//定义一个基类指针方便后续向上类型转换
	worker* m_worker = nullptr;

	std::cout << "需要输入几个职工信息：" << std::endl;
	int new_num = 0;		//存储用户输入的记录数
	std::cin >> new_num;	
	if (new_num > 0)
	{
		//计算新空间大小
		int new_size = this->w_num + new_num;
		//动态分配，开辟新的空间
		worker** new_array = new worker * [new_size];
		//将原来的数组的数据拷贝到新数组里(如果存在）
		worker** old_array = this->w_array;
		if (old_array != nullptr)
		{
			for (int i = 0; i < this->w_num; i++)
			{
				new_array[i] = old_array[i];
			}
			// 注意：不要现在就释放旧数组，因为下面会在输入时检查
		}

		//用户输入数据
		for (int i = 0; i < new_num; i++)
		{
			std::cout << "请输入第" << i + 1 << "个职工的信息：" << std::endl;
			std::cout << "职工号：" << std::endl;
			int id = 0;
			while (std::cin >> id) //将用户输入的编号作为循环条件
			{
				//定义一个bool型变量判断值是否重复
				bool bl = false;
				//遍历已有记录，使用新数组已有记录判断
				for (int j = 0; j < this->w_num; j++)
				{
					if (new_array[j] != nullptr && id == new_array[j]->m_id)
					{
						bl = true;
						std::cout << "编号重复！！！请重新输入" << std::endl;
						break;
					}
				}
				//如果没有重复就跳出循环
				if (!bl)
				{
					break;
				}
			}
			std::string name;
			std::cout << "姓名：" << std::endl;
			std::cin >> name;

			int deptid = 0;
			std::cout << "岗位：" << std::endl << "[1]普通职工" << std::endl
				<< "[2]经理" << std::endl << "[3]总裁" << std::endl;
			std::cin >> deptid;
			//根据用户输入的代号判断数据存放在哪个子类里
			switch (deptid)
			{
				//普通职工
			case 1:m_worker = new employee(id, name, deptid);
				break;
				//经理
			case 2:m_worker = new manager(id, name, deptid);
				break;
				//总裁
			case 3:m_worker = new boss(id, name, deptid);
				break;
			default:
				m_worker = nullptr;
				break;
			}
			//将职工指针存放在指针数组里
			new_array[this->w_num + i] = m_worker;
		}

		// 释放旧的指针数组，然后替换为 new_array
		if (old_array != nullptr)
		{
			delete[] old_array;
		}
		this->w_array = new_array;
		this->w_num = new_size;
		this->file_empty = false;		//不为空时赋值为假
		std::cout << "成功添加" << new_num << "个职工的信息！" << std::endl;
		this->save();
	}
	else
	{
		std::cout << "输入有误！" << std::endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void w_manage::save()
{
	//定义文件输出流对象，并使用构造函数打开文件
	std::ofstream ofs("worker_manage.txt", std::ios::out);
	for (int i = 0; i < this->w_num; i++)
	{
		ofs << this->w_array[i]->m_id << '\t'
		<< this->w_array[i]->m_name << '\t'
		<< this->w_array[i]->m_deptid << std::endl;;
	}
	ofs.close();
}

//统计人数
int w_manage::get_num()
{
	std::ifstream ifs;
	ifs.open("worker_manage.txt", std::ios::in);  //打开文件
	//计数
	int num = 0;
	//定义三个变量存储读取到的记录
	int id;
	std::string name;
	int deptid;
	//读取记录，如果读到空格就会读下一个记录，直到本行的记录全部读完，只有读取到文件末才会返回假跳出循环
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		num++;
	}
	return num;
}

//初始化职工(将文件中的记录读取到数组里)
void w_manage::w_init()
{
	std::ifstream ifs("worker_manage.txt", std::ios::in);
	int index = 0;//记录人数
	//定义三个变量存储读取到的记录
	int id;
	std::string name;
	int deptid;
	//读取文件里的记录 读到文件末就退出循环
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		//根据编号判断记录从属，开辟堆区空间存放记录
		worker* m_worker = nullptr;
		//普通职工
		if (deptid == 1)
		{
			m_worker = new employee(id, name, deptid);
		}
		//经理
		else if (deptid == 2)
		{
			m_worker = new manager(id, name, deptid);
		}
		//总裁
		else
		{
			m_worker = new boss(id, name, deptid);
		}
		//将分类好的记录存放在指针数组里
		this->w_array[index] = m_worker;
		index++;
	}
	this->w_num = index;
	ifs.close();
}

//显示职工信息
void w_manage::show_emp()
{
	//判断文件是否为空
	if (this->file_empty)
	{
		std::cout << "文件不存在或记录为空！！！" << std::endl;
	}
	else
	{
		std::cout << "职工号\t" << "姓名\t" << "岗位" << std::endl;
		for (int i = 0; i < this->w_num; i++)
		{
			//因为数组里存放的是worker类的指针，所以可以直接使用多态调用接口
			this->w_array[i]->show_info();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
int w_manage::is_exist(int id)
{
	//定义一个变量存放返回的结果
	int index = -1;
	//遍历数组寻找id
	for (int i = 0; i < this->w_num; i++)
	{
		//如果找到了将位置返回
		if (this->w_array[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// 删除职工（修复：先释放对象，再移动指针，防止内存泄漏）
void w_manage::del_emp()
{
	//判断文件是否为空
	if (this->file_empty)
	{
		std::cout << "文件不存在或记录为空！！！" << std::endl;
	}
	else
	{
		int m_id = 0;//用户输入的编号
		std::cout << "请输入你要删除职工的编号：" << std::endl;
		std::cin >> m_id;
		int num = is_exist(m_id); //判断职工是否存在，存在就会返回下标
		if (num == -1)
		{
			std::cout << "职工不存在！！！" << std::endl;
		}
		else
		{
			// 先释放被删除的对象
			delete this->w_array[num];
			// 移动其余指针覆盖被删除的位置
			for (int i = num; i < this->w_num - 1; i++)
			{
				this->w_array[i] = this->w_array[i + 1];
			}
			// 将末尾指针设为 nullptr（避免悬空），然后人数-1
			this->w_array[this->w_num - 1] = nullptr;
			this->w_num--;		//更新数组下标

			this->save();		//删除后保存到文件里
			std::cout << "删除成功！！！" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void w_manage::find_emp()
{
	//判断文件是否为空
	if (this->file_empty)
	{
		std::cout << "文件不存在或记录为空！！！" << std::endl;
	}
	else
	{
		int select = 0;//用户输入选择
		std::cout << "请选择查找方式：[1] 按职工编号查找 [2] 按姓名查找" << std::endl;
		std::cin >> select;
		//按职工编号查找
		if (select == 1)
		{
			int m_id = 0;
			std::cout << "请输入职工编号：" << std::endl;
			std::cin >> m_id;
			int num = is_exist(m_id); //调用判断职工是否存在，存在就会返回下标
			if (num == -1)
			{
				std::cout << "职工不存在！！！" << std::endl;
			}
			else
			{
				std::cout << "职工号\t" << "姓名\t" << "岗位" << std::endl;
				this->w_array[num]->show_info();
			}
		}
		//按职工姓名查找
		else if (select == 2)
		{
			//判断是否找到 默认失败
			bool flag = false;

			std::string name;
			std::cout << "请输入职工姓名：" << std::endl;
			std::cin >> name;
			for (int i = 0; i < this->w_num; i++)
			{
				if (this->w_array[i]->m_name == name)
				{
					this->w_array[i]->show_info();
					flag = true;
				}
			}
			if (!flag)
			{
				std::cout << "职工不存在！！！" << std::endl;
			}
		}
		else {
			std::cout << "输入错误 ~" << std::endl;
		}

	}
	system("pause");
	system("cls");
}

//修改职工记录
void w_manage::mod_emp()
{
	//判断文件是否为空
	if (this->file_empty)
	{
		std::cout << "文件不存在或记录为空！！！" << std::endl;
	}
	else
	{
		int m_id = 0;//用户输入的编号
		std::cout << "请输入你要修改职工的编号：" << std::endl;
		std::cin >> m_id;
		int num = is_exist(m_id); //调用判断职工是否存在，存在就会返回下标
		if (num == -1)
		{
			std::cout << "职工不存在！！！" << std::endl;
		}
		else
		{
			delete this->w_array[num];
			std::cout << "请输入新职工的信息：" << std::endl;
			std::cout << "职工号：" << std::endl;
			int id;
			std::cin >> id;

			std::cout << "姓名：" << std::endl;
			std::string name;
			std::cin >> name;

			std::cout << "岗位：" << std::endl << "[1]普通职工" << std::endl
				<< "[2]经理" << std::endl << "[3]总裁" << std::endl;
			int deptid;
			std::cin >> deptid;
			//根据用户输入的代号判断数据存放在哪个子类里
			worker* m_worker = NULL;
			switch (deptid)
			{
				//普通职工
			case 1:m_worker = new employee(id, name, deptid);
				break;
				//经理
			case 2:m_worker = new manager(id, name, deptid);
				break;
				//总裁
			case 3:m_worker = new boss(id, name, deptid);
				break;
			default:
				break;
			}
			//将职工指针存放在数组里
			this->w_array[num] = m_worker;
			//将修改后的数据保存在文件里
			this->save();
			std::cout << "修改成功！！！" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//给记录排序
void w_manage::sort_emp()
{
	//判断文件是否为空
	if (this->file_empty)
	{
		std::cout << "文件不存在或记录为空！！！" << std::endl;
	}
	else
	{
		int index;
		std::cout << "需要升序还是降序：" << std::endl;
		std::cout << "[1]升序  [2]降序" << std::endl;
		std::cin >> index;
		if (index == 1)
		{
			worker* temp_array = NULL;
			//冒泡排序( 升序 )
			for (int i = 0; i < this->w_num-1; i++)
			{
				for (int j = 0; j < this->w_num - i - 1; j++)
				{
					if (this->w_array[j]->m_id > this->w_array[j + 1]->m_id)
					{
						temp_array = this->w_array[j];
						this->w_array[j] = this->w_array[j + 1];
						this->w_array[j + 1] = temp_array;
					}
				}
			}
		}
		else
		{
			//插入排序( 降序 )
			for (int i = 1; i < this->w_num; i++)	
			{
				int j = i;		//将当前值和下标存储
				worker* temp_array = this->w_array[i];
				//当前值比前值大就换位，当j从后往前遍历完数组后循环才会结束
				while (j > 0 && temp_array->m_id > this->w_array[j-1]->m_id)
				{
					//因为当前值先存储起来了，所以直接将前值赋给当前值
					this->w_array[j] = this->w_array[j-1];
					j--;   //将下标-1，此时就为前值的下标，方便赋值
				}
				//当前值放在前值的位置，完成换位
				this->w_array[j] = temp_array;
			}
		}
		//将排好序后的数据存放在文件里
		this->save();
		std::cout << "排序成功！！！" << std::endl;
	}
	system("pause");
	system("cls");
}

//清空记录					
//回收站功能					这里保证了回收站文件的唯一性，可以将不同文件的记录追加在回收站文件里
void w_manage::clean_file3()
{
	//判断回收站文件是否存在并打开
	if (std::ifstream("new_file.txt").is_open())
	{
		//存在就以追加方式打开
		std::ofstream ofs("new_file.txt", std::ios::app);
		//因为程序没有结束，数据还存储在动态数组里，可以直接存入文件
		for (int i = 0; i < this->w_num; i++)
		{
			ofs << this->w_array[i]->m_id << '\t'
				<< this->w_array[i]->m_name << '\t'
				<< this->w_array[i]->m_deptid << std::endl;;
		}
		//将职工文件移除并重新创建，防止系统创建副本
		remove("worker_manage.txt");
		ofs.close();
		std::ofstream ofs2("worker_manage.txt");
		ofs2.close();

		delete_file();
		//空时赋值为真
		this->file_empty = true;
		std::cout << "成功放入回收站 >_< !" << std::endl;
	}
	else
	{		//当文件不存在时，使用重命名直接将原职工文件更改为回收站文件
		if (rename("worker_manage.txt", "new_file.txt") == 0)
		{
			std::cout << "成功放入回收站 >_< !" << std::endl;
			//创建一个新的职工文件，防止系统创建副本
			std::ofstream ofs("worker_manage.txt");
			ofs.close();
			delete_file();
			this->file_empty = true;
		}
		else
		{
			std::cout << "放入失败-_-!" << std::endl;
		}
	}
}

void w_manage::clean_file2()
{
	std::cout << "真的还要继续清空吗 >_< !!!" << std::endl;
	std::cout << "按[0]存放在回收站 按[1]绝对要清空!!! (按任意键返回)" << std::endl;
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();		//按下键位后会产生相应的返回值
			if (key == 0 || key == 0xE0) {//功能键和方向键会返回0或0xE0
				std::cout << "下次看好再来 -_- ！" << std::endl;
				break;
			}
			if (key == '0')		//用户按下0后调用回收站函数
			{
				clean_file3();
				break;
			}
			else if (key=='1')	//绝对清空
			{
				//将文件以清空在打开
				std::ofstream ofs("worker_manage.txt", std::ios::trunc);
				ofs.close();	//关闭文件
				
				
				delete_file();
				//文件为空，赋值真
				this->file_empty = true;
				std::cout << "完成清空" << std::endl;
				break;
			}
			else
			{
				std::cout << "下次看好再来 -_- ！！！" << std::endl;
				break;
			}
		}
	}
}

void w_manage::clean_file()
{
	//判断文件是否为空
	if (this->file_empty)
	{
		std::cout << "文件不存在或记录为空！！！" << std::endl;
	}
	else
	{
		std::cout << "真的要清空记录吗 >_< ！" << std::endl;
		std::cout << "输入[0]确定，按任意键返回" << std::endl;
		while (true)
		{
			if (_kbhit())//这个函数是判断是否按下键位
			{
				int key = _getch();		//按下键位后会产生相应的返回值
				if (key == 0 || key == 0xE0) {//功能键和方向键会返回0或0xE0
					std::cout << "下次看好再来 -_- ！" << std::endl;
					break;
				}
				if (key == '0')
				{
					clean_file2();
					break;
				}		
				else                    //其他字符
				{
					std::cout << "下次看好再来噢 -_- ！" << std::endl;
					break;
				}
			}
		}
	}
	system("pause");
	system("cls");
}

//恢复记录(与读文件函数类似)  这里的缺陷基本解决
//修复：先统计要恢复的记录数并为临时数组分配空间，避免写入未分配内存
void w_manage::renew_file()
{
	//先统计回收站文件记录数
	std::ifstream ifs_count("new_file.txt", std::ios::in);
	if (!ifs_count.is_open())
	{
		std::cout << "恢复失败-_-!（回收站文件不存在）" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int count = 0;
	{
		int id;
		std::string name;
		int deptid;
		while (ifs_count >> id && ifs_count >> name && ifs_count >> deptid)
		{
			count++;
		}
	}
	ifs_count.close();

	if (count == 0)
	{
		std::cout << "回收站为空，恢复失败-_-!" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	// 分配临时数组并填充
	worker** new_array = new worker * [count];
	std::ifstream ifs("new_file.txt", std::ios::in);
	if (!ifs.is_open())
	{
		delete[] new_array;
		std::cout << "恢复失败-_-!（无法打开回收站）" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 0;
	int id;
	std::string name;
	int deptid;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		worker* m_worker = nullptr;
		if (deptid == 1)
		{
			m_worker = new employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			m_worker = new manager(id, name, deptid);
		}
		else
		{
			m_worker = new boss(id, name, deptid);
		}
		new_array[index++] = m_worker;
	}
	ifs.close();

	// 删除原有内存，并替换为新数组
	this->delete_file(); // 安全释放当前对象与数组

	// 将恢复的数据写入职工文件（追加方式）
	std::ofstream ofs("worker_manage.txt", std::ios::app);
	for (int i = 0; i < count; i++)
	{
		ofs << new_array[i]->m_id << '\t'
			<< new_array[i]->m_name << '\t'
			<< new_array[i]->m_deptid << std::endl;
	}
	ofs.close();

	// 删除回收站文件
	remove("new_file.txt");

	// 将数据重新赋值
	this->w_array = new_array;
	this->w_num = count;
	this->file_empty = false;
	std::cout << "成功恢复 >_< !" << std::endl;

	system("pause");
	system("cls");
}
						
//析构函数
w_manage::~w_manage()
{
	if (this->w_array != nullptr)
	{
		for (int i=0; i < w_num; i++)
		{
			delete this->w_array[i];
		}
		delete[] this->w_array;
		this->w_array = nullptr;
	}
}
