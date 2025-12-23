#include<iostream>
#include"Sing_manager.h"   //分文件实现
//构造函数
sing_manager::sing_manager()
{
	//固定输出时浮点数的小数位数为 2
	std::cout << std::fixed << std::setprecision(2);

	//利用默认构造函数调用初始化函数
	this->init_sing();

	//自动创建选手
	this->create_singer();
}

//显示菜单
void sing_manager::show_menu()
{
	for (int i = 0; i < 2; i++)
	{
		std::cout << '\t';
		for (int j = 0; j < 40; j++)
		{
			std::cout << '-';
		}
		std::cout << std::endl;
	}
		std::cout << " \t  **欢迎使用校园歌唱比赛流程管理系统**" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << '\t';
		for (int j = 0; j < 40; j++)
		{
			std::cout << '-';
		}
		std::cout << std::endl;
	}
	   	  std::cout << "\t  ||||||||| [1] 开始歌唱比赛 |||||||||" << std::endl;
		  std::cout << "\t  ||||||||| [2] 查看往届记录 |||||||||" << std::endl;
		  std::cout << "\t  ||||||||| [3] 清空比赛记录 |||||||||" << std::endl;
		  std::cout << "\t  ||||||||| [0] 退出管理系统 |||||||||" << std::endl;
	std::cout << "      ============================================" << std::endl;
	std::cout << "    ================================================" << std::endl;
}

//退出管理系统
void sing_manager::exit_system()
{
	std::cout << "欢迎下次使用 >_< ! !" << std::endl;
	system("pause");
	exit(0);
}

//初始化容器和成员变量
void sing_manager::init_sing()
{
	//使容器保持为空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->v_victory.clear();
	this->ten_record.clear();
	this->victory_record.clear();
	//初始化比赛轮数 第一轮
	this->s_count = 1;
}

//初始化创建100名选手
void sing_manager::create_singer()
{
	for (int i = 0; i < 100; i++)
	{
		//创建歌手类的对象
		singer sg;
		//初始化array容器的得分 
		for (int j = 0; j < 3; j++)
		{
			sg.s_score[j] = 0;
		}
		//将编号存入v1
		this->v1.emplace_back(10001 + i);
		//使用随机姓名生成器 初始化姓名
		sg.s_name = random_name();
		//最后将编号和歌手类对象(歌手姓名，本轮分数)存入map容器
		this->m_singer.emplace(10001 + i, sg);
	}
}

//随机姓名生成器
std::string sing_manager::random_name()
{
	//姓氏
	std::vector<std::string> last_name{ 
		"王","李","张","刘" ,"陈" ,"杨" ,"赵" ,"黄" ,"周" ,"吴" ,
		"徐","孙" ,"胡" ,"朱" ,"高" ,"林" ,"何" ,"郭" ,"马" ,"罗" };

	//第二个名 当为两个字的姓名时 只需要将 last_name和first_name 组合成名字就行
	std::vector<std::string> first_name{
		"云","明","飞","雨","羽","薇","亮","华","暧","文","风","凤",
		"峰","洪","武","鸿","丽","书","树","剑","舒","巳","玉","立" };

	//第三个名 当为三个字的姓名时先随机将两个名组合 再和姓组合
	std::vector<std::string> double_first_name{
		"昭","寒","励","昊","冠","洋","昌","炎","玚","璟","璥","瑜",
		"生","琸","瑎","玚","璟","璥","溯","湔","书","树","剑","立" };

	//static 使这些变为静态 程序运行完释放 保证只运行一次
	//创建一个真随机数设备
	static std::random_device n_rd;

	//创建一个随机数生成器，使用上面的设备作为种子
	static std::mt19937 n_gen(n_rd());

	//创建0 到 (姓氏数量-1)的均匀分布 这里有20个姓 生成0-19的随机数 因为使用的vector容器 从0开始
	std::uniform_int_distribution<> n_dist(0, static_cast<int>(last_name.size()) - 1);  

	//static_cast<int>类型转换是因为vector容器的size()返回的是size_t(无符号) 类型不匹配的隐式转换，最好显式转换类型避免数据丢失

	//创建一个姓名类型 用于判断两个字还是三个字 0--两个  1--三个 也是均匀分布
	std::uniform_int_distribution<> or_name(0, 1);

	//生成一个随机数作为索引(下标) 实现随机选择一个姓
	std::string name = last_name[n_dist(n_gen)];

	//因为双字和三字都会使用到第二个字 将第二个字的均匀分布作为公有接口使用
	std::uniform_int_distribution<> public_dist(0, static_cast<int>(first_name.size()) - 1);

	//随机生成 0 或 1
	if (or_name(n_gen) == 0)
	{	//两个字
		//将姓名拼接 
		name += first_name[public_dist(n_gen)];
	}
	else {		//三个字
				//创建第三个字的均匀分布 0 - 23
		std::uniform_int_distribution<> double_dist2(0, static_cast<int>(double_first_name.size()) - 1);
		//将姓 名 名2 拼接  还是利用的随机数作为索引
		name += first_name[public_dist(n_gen)] + double_first_name[double_dist2(n_gen)];
	}
	//将随机出来的姓名返回
	return name;
}

//初始化容器和成员变量
void sing_manager::init_sing()
{
	//使容器保持为空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->v_victory.clear();
	this->ten_record.clear();
	this->victory_record.clear();
	//初始化比赛轮数 第一轮
	this->s_count = 1;
}

//开始比赛
void sing_manager::start_match()
{
	
	//第一轮海选 (100进50)
	//[1] 抽签
	this->random_draw();
	//[2] 比赛
	this->sing_match();
	//[3] 显示最终结果
	this->show_score();

	//第二轮十佳 (50进10)
	this->s_count++;
	//[1] 抽签
	this->random_draw();
	//[2] 比赛
	this->sing_match();
	//[3] 显示最终结果
	this->show_score();

	//最终回冠军争夺 (10进3)
	this->s_count++;
	//[1] 抽签
	this->random_draw();
	//[2] 比赛
	this->sing_match();
	//[3] 显示最终结果
	this->show_score();
	//[4] 保存分数到文件中
	this->save_record();

	//调用初始化函数
	this->init_sing();

	//自动创建选手
	this->create_singer();
}

//抽签   使用std::shuffle()洗牌
void sing_manager::random_draw()
{
	//创建一个真随机设备
	static std::random_device rd;

	//创建一个随机生成器，使用上面的设备作为种子
	static std::mt19937 gen(rd());

	//使用洗牌函数打乱容器次序
	if (this->s_count == 1)     //第一轮
	{
		std::cout << "第一轮  海选正式开始     选手正在抽签..." << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::shuffle(v1.begin(), v1.end(), gen);

		system("pause");
		system("cls");

		std::cout << "抽签完成！" << std::endl;
		std::cout << "请以下编号的同学按顺序开始演唱(每人只有45秒)..." << std::endl;
		this->show_draw(v1);
	}
	else if (this->s_count == 2)  //第二轮
	{
		std::cout << "第二轮  十佳歌手争霸赛正式开始     选手正在抽签..." << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::shuffle(v2.begin(), v2.end(), gen);

		system("pause");
		system("cls");

		std::cout << "抽签完成！" << std::endl;
		std::cout << "请以下编号的同学按顺序开始演唱(每人只有1分45秒)..." << std::endl;
		this->show_draw(v2);
	}
	else						   //第三轮
	{
		std::cout << "最终回  冠军争夺赛正式开始     选手正在抽签..." << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::shuffle(v3.begin(), v3.end(), gen);

		system("pause");
		system("cls");

		std::cout << "抽签完成！" << std::endl;
		std::cout << "请以下编号的同学按顺序开始演唱(每人一首歌时间)..." << std::endl;
		this->show_draw(v3);
	}
	system("pause");
	system("cls");
}

//显示抽签结果
void sing_manager::show_draw(const std::vector<int>& show_v) const
{
	int index = 1;
	int i = 1;
	if (this->s_count < 3)
	{
		std::cout << "第1组：";
		for (const auto& sw_it : show_v)
		{
			std::cout << sw_it << '\t';
			if (i % 10 == 0 && &sw_it != &show_v.back())
			{
				if (index < 10)
				{
					std::cout << std::endl << std::endl << "第" << index + 1  << "组：";
					index++;
				}
			}
			i++;
		}
	}
	else {
		std::cout << "决赛歌唱顺序如下..." << std::endl;
		for (const auto& sw_it : show_v)
		{
			std::cout << sw_it << '\t';
		}
	}
	std::cout << std::endl;
}

//比赛中
void sing_manager::sing_match()
{
	std::cout << "---------------第" << this->s_count << "轮比赛正式开始------------" << std::endl;
	//创建一个局部vector容器 根据轮数获取对应的竞赛容器
	std::vector<int> v_temp;
	if (this->s_count == 1)
	{
		v_temp = v1;
	}
	else if (this->s_count == 2)
	{
		v_temp = v2;
	}
	else
	{
		v_temp = v3;
	}

	//创建临时multimap容器存放10人小组的比赛成绩  使用multimap容器是因为成绩有可能出现重复
	std::multimap<double, int, std::greater<double>> group_show;  //使用降序
	
	//定义一个相同类型的multimap容器用于将所有人排序 取出最后晋级的人选
	std::multimap<double, int, std::greater<double>> group_sort;  //使用降序

	//int i = 1;
	int index = 0;

	//遍历对应轮数的vector容器----编号
	for (const auto& s_it : v_temp)
	{
		double ave = this->judge_score();

		//测试代码
		/*std::cout << ave << '\t';
		if (i % 10 == 0) { std::cout << std::endl; }
		i++;*/

		//将最终分数插入对应编号的位置  这里相当于下标使用的编号
		this->m_singer[s_it].s_score[this->s_count - 1] = ave;

		//输出每组人员的信息成绩
		group_show.emplace(ave,s_it);
		index++;
		if (index % 10 == 0)
		{
			if (this->s_count < 3)
			{
				std::cout << std::endl << "==================各小组成绩==================" << std::endl;
				std::cout << "第" << index / 10 << "组：" << std::endl;
				std::cout << std::endl << "编号\t" << "姓名\t" << "分数" << std::endl;
				//遍历容器输出
				for (const auto& m_it : group_show)
				{
					std::cout << std::endl << m_it.second << '\t' << this->m_singer[m_it.second].s_name
						<< '\t' << m_it.first << std::endl;
				}
				system("pause");
				system("cls");
			}
			else {
				std::cout << std::endl << "编号\t" << "姓名\t" << "分数" << std::endl;
				//遍历容器输出
				for (const auto& m_it : group_show)
				{
					std::cout << std::endl << m_it.second << '\t' << this->m_singer[m_it.second].s_name
						<< '\t' << m_it.first << std::endl;
				}
				system("pause");
				system("cls");
			}
			//将所有元素存储 方便统计晋级
			group_sort.insert(group_show.begin(), group_show.end());
			//每显示一组都要清空容器 否则会重复输出
			group_show.clear();
		}
	}

	//最后遍历排序好的group_sort容器 将晋级的人员编号放入对应轮数的容器
	int count = 0;
	for (const auto& m_it : group_sort)
	{
		if (this->s_count == 1)  //海选晋级
		{
			if (count < 50) {
				v2.emplace_back(m_it.second);
				count++;
			}
		}
		else if (this->s_count == 2) {
			if (count < 10) {   //十佳晋级
				v3.emplace_back(m_it.second);
				count++;
			}
		}
		else {
			if (count < 3) {	//冠 亚 季
				this->v_victory.emplace_back(m_it.second);
				count++;
			}
		}
	}
	//清空临时排序容器
	group_sort.clear();
	std::cout << "===============第" << this->s_count << "轮比赛结束===============" << std::endl;

}

//评委打分
double sing_manager::judge_score()
{
	//创建真随机数设备
	static std::random_device score_rd;

	//创建随机数生成器并将设备作为种子
	static std::mt19937 score_gen(score_rd());

	//设置均匀分布  这里使用的是浮点型的均匀分布
	static std::uniform_real_distribution<> score_dist(4.0, 10.0);

	//定义一个deque容器 (双端队列) 临时存储分数(每次循环自动清除) 方便头删和尾删 
	std::deque<double> score_d;

	//十个评委打分
	for (int i = 0; i < 10; i++)
	{
		// std::round()四舍五入 先乘以100再做四舍五入为了保证是个三位数 然后再除以100.0这样小数位数固定在两位
		double new_score = std::round(score_dist(score_gen) * 100) / 100.0;

		//将分数插入临时容器
		score_d.emplace_back(new_score);
	}
	//降序排序 头部和尾部就分别是最大值和最小值了
	std::sort(score_d.begin(), score_d.end(), std::greater<double>());

	//头删和尾删
	score_d.pop_front();
	score_d.pop_back();

	//累加算法
	double sum = std::accumulate(score_d.begin(), score_d.end(), 0.0);
	double ave = sum / static_cast<double>(score_d.size());

	//最后返回最终分数
	return ave;
}

//显示晋级选手
void sing_manager::show_score()
{
	int i = 1;
	if (this->s_count == 1)
	{
		std::cout << "海选晋级人员如下..." << std::endl << std::endl;
		for (const auto& v2_it : v2)
		{
			std::cout << v2_it << '\t' << this->m_singer[v2_it].s_name << '\t' 
				<< this->m_singer[v2_it].s_score[s_count - 1] << '\t';

			if (i % 5 == 0) { std::cout << std::endl << std::endl; }
			i++;
		}
	}
	else if(this->s_count == 2){
		std::cout << "十佳歌手如下..." << std::endl << std::endl;
		for (const auto& v3_it : v3)
		{
			std::cout << v3_it << '\t' << this->m_singer[v3_it].s_name << '\t'
				<< this->m_singer[v3_it].s_score[s_count - 1] << '\t';

			if (i % 5 == 0) { std::cout << std::endl << std::endl; }
			i++;
		}
	}
	else {		//使用string存放字符 再使用substr()截取
		std::cout << "校园歌唱比赛完美结束 >_< !  以下是三强..." << std::endl << std::endl;
		std::string title{ "冠军亚军季军" };
		int name = 0;
		int len = 4;
		for (const auto& victory_it : v_victory)
		{
			std::cout << title.substr(name, len) << "：\t" << victory_it << '\t' << this->m_singer[victory_it].s_name << '\t'
				<< this->m_singer[victory_it].s_score[s_count - 1] << std::endl << std::endl;
			name += len;
		}
	}
	system("pause");
	system("cls");
	this->show_menu();
}

//保存到文件里
void sing_manager::save_record()
{
	//以追加的方式打开文件
	std::ofstream victory_ofs("match_victory.csv", std::ios::out | std::ios::app);
	victory_ofs << "选手编号" << "," << "选手姓名" << "," << "选手成绩" << std::endl;
	//固定文件里成绩的小数位数为 2
	victory_ofs << std::fixed << std::setprecision(2);

	std::ofstream ten_ofs("match_ten.csv", std::ios::out | std::ios::app);
	ten_ofs << "选手编号" << "," << "选手姓名" << "," << "选手成绩" << std::endl;
	//固定文件里成绩的小数位数为 2
	ten_ofs << std::fixed << std::setprecision(2);
	
	//将十佳歌手放入文件
	for (const auto& t_it : v3)
	{
		ten_ofs << t_it << ',' << this->m_singer[t_it].s_name << ','
			<< this->m_singer[t_it].s_score[1] << std::endl;
	}
	this->file_empty_ten = false;

	//前三名放入文件
	if (this->s_count == 3)
	{
		for (const auto& v_it : v_victory)
		{
			victory_ofs << v_it << ',' << this->m_singer[v_it].s_name << ','
				<< this->m_singer[v_it].s_score[2] << std::endl;
		}
		this->file_empty_victory = false;
	}
	//一定要记得关闭文件！！！
	ten_ofs.close();
	victory_ofs.close();
}

//判断两个文件是否为空
bool sing_manager::is_singer(const int& select)
{
	std::ifstream ten_ifs("match_ten.csv", std::ios::in);
	std::ifstream victory_ifs("match_victory.csv", std::ios::in);

	//读取字符用于判断文件是否已被清空
	char ch;
	ten_ifs >> ch;
	//十佳
	if (select == 1)
	{
		//使用is_open()判断文件是否打开
		if (!ten_ifs.is_open())
		{
			std::cout << "十佳歌手文件不存在或其他错误..." << std::endl;
			this->file_empty_ten = true;
			return true;
		}//使用右移运算符可以读取一个字符 判断内容是否为空 注意：他会跳过空白
		else if(ten_ifs.eof()){
			std::cout << "十佳歌手文件内容为空..." << std::endl;
			this->file_empty_ten = true;
			return true;
		}
		else {
			//因为使用>>会读走文件中的一个字符 可以使用putback()存放回来 
			ten_ifs.putback(ch);
			this->file_empty_ten = false;
			return false;
		}
	}			//三强
	else if (select == 2) {
		if (!victory_ifs.is_open())
		{
			std::cout << "三强文件不存在或者其他错误..." << std::endl;
			this->file_empty_victory = true;
			return true;
		}	//使用peek()判断(推荐)
		else if(victory_ifs.peek() == EOF){
			std::cout << "三强文件内容为空..." << std::endl;
			this->file_empty_victory = true;
			return true;
		}
		else {
			this->file_empty_victory = false;
			return false;
		}
	}
	else {
		std::cout << "输入有误" << std::endl;
		return true;
	}
}

//读取文件里面的数据
void sing_manager::read_file(const int& select)
{
	//将大容器初始化
	this->ten_record.clear();
	std::ifstream ten_ifs("match_ten.csv", std::ios::in);
	std::ifstream victory_ifs("match_victory.csv", std::ios::in);

	//存放读取到的数据数据
	std::string date;
	//届数
	int index = 0;

	if (select == 1)  //十佳
	{
		while (std::getline(ten_ifs, date))
		{
			//因为存入的时候每届都有标题 可以根据标题判断届数  
			if (date == "选手编号,选手姓名,选手成绩")
			{
				index++;
				continue;  //将标题跳过
			}
			if (date.empty()) continue;
			//将读取到的数据包括逗号插入map容器
			this->ten_record[index].emplace_back(date);
		}
		ten_ifs.close();
	}
	else if (select == 2)  //三强
	{
		while (std::getline(victory_ifs, date))
		{
			if (date == "选手编号,选手姓名,选手成绩")
			{
				index++;
				continue;
			}
			if (date.empty()) continue;
			this->victory_record[index].emplace_back(date);
		}
		victory_ifs.close();
	}
	else {
		return;
	}
}

//显示往届记录
void sing_manager::show_record()
{
	std::cout << "你要查看哪个往届记录" << std::endl;
	std::cout << "[1] 十佳歌手  [2] 三强" << std::endl;
	//用户选择 
	int sh_select;
	std::cin >> sh_select;
	//调用判断函数判断文件是否存在或为空
	if (!this->is_singer(sh_select))
	{
		//将数据读取到map容器里
		this->read_file(sh_select);
		if (sh_select == 1)				//十佳
		{
			//外层循环遍历map容器  注意容器嵌套就类似于二维数组
			for (const auto& ten_it:this->ten_record)
			{
				std::cout << std::endl << "第" << ten_it.first << "届校园歌唱比赛十佳歌手..." << std::endl;
				//内存循环遍历嵌套内的vector容器
				for (const auto& v_it : ten_it.second)
				{
					//临时容器 用于存储和输出记录
					std::vector<std::string> temp;
					size_t len = 0;
					//查找","位置(下标)
					size_t pos = v_it.find(",");
					//find()函数如果没找到会返回无符号整型 size_t npos 也是 -1  
					while (pos != std::string::npos)	//截取字符 
					{
						//将截取的字符插入临时容器  截取的是个数，不是下标
						temp.emplace_back(v_it.substr(len, pos - len));
						len = pos + 1;
						pos = v_it.find(",", len);
					}
					//因为最后一个元素没有"," 所以直接插入
					temp.emplace_back(v_it.substr(len));
					//temp容器里的元素个数大于等于三时输出 这里的元素是字符串 不是单个字符
					if (temp.size() >= 3)
					{
						std::cout << temp[0] << '\t' << temp[1] << '\t' << temp[2] << std::endl;
					}
				}
			}
		}
		else if (sh_select == 2)    //三强 和十佳同理
		{
			for (const auto& victory_it : this->victory_record)
			{
				std::cout << std::endl << "第" << victory_it.first << "届校园歌唱比赛三强..." << std::endl;
				std::string title{ "冠军亚军季军" };
				int name = 0;
				int start = 4;
				//记录输出次数
				int count = 1;
				for (const auto& v_it : victory_it.second)
				{
					std::vector<std::string> temp;
					size_t len = 0;
					size_t pos = v_it.find(",");
					while (pos != std::string::npos)
					{
						temp.emplace_back(v_it.substr(len, pos - len));
						len = pos + 1;
						pos = v_it.find(",", len);
					}
					temp.emplace_back(v_it.substr(len));
					if (temp.size() >= 3)
					{
						std::cout <<title.substr(name,start)<<"：\t" << temp[0] << '\t' << temp[1] 
							<< '\t' << temp[2] << std::endl;
						//当输出了3个选手后 全部初始化 开始下一届
						if (count == 3)
						{
							name = 4;
							start = 0;
							count = 1;
						}
						name += start;
						count++;
					}
				}
			}
		}
		else {
			std::cout << "输入有误..." << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//清空文件里所有记录
void sing_manager::clear_record()
{
	std::cout << "需要清空哪个文件的记录?" << std::endl;
	std::cout << "[1] 往届十佳记录 [2] 往届三强记录 [3] 一起清空" << std::endl;
	std::cout << "按其余任意键返回..." << std::endl << std::endl;
	while (true)
	{
		if (_kbhit())//这个函数是判断是否按下键位
		{
			int key = _getch();		//按下键位后会产生相应的返回值
			if (key == 0 || key == 0xE0) {//功能键和方向键会返回0或0xE0
				std::cout << "下次看好再来 -_- ！" << std::endl;
				break;
			}
			if (key == '1')
			{
				if (this->is_singer(1)) { break; }
				std::ofstream ten_ofs("match_ten.csv", std::ios::trunc);
				ten_ofs.close();

				this->file_empty_ten = true;
				std::cout << "已清空十佳歌手" << std::endl;
				break;
			}
			else if (key == '2')                 //其他字符
			{
				if (this->is_singer(2)) { break; }
				std::ofstream victory_ofs("match_victory.csv", std::ios::trunc);
				victory_ofs.close();
				this->file_empty_victory = true;
				std::cout << "已清空三强歌手" << std::endl;
				break;
			}
			else if (key == '3')
			{
				if (this->is_singer(1) && this->is_singer(2)) { break; }

				std::ofstream ten_ofs("match_ten.csv", std::ios::trunc);
				ten_ofs.close();
				this->file_empty_ten = true;

				std::ofstream victory_ofs("match_victory.csv", std::ios::trunc);
				victory_ofs.close();
				this->file_empty_victory = true;
				std::cout << "两个均已清空" << std::endl;
				break;
			}
			else {
				std::cout << "下次看好再来 -_- ！" << std::endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

//析构函数
sing_manager::~sing_manager() {}