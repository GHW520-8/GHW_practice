#include<iostream>
#include<string>
class Test3 {
public:
	//显示
	void show() {
		//因为set()函数是保护权限，所以在类内调用
		set();
		std::cout << t_str << std::endl;
	}
	//保护权限类内初始化
protected:
	void set() {
		t_str = "我爱C++";
	}
	std::string t_str;
//猜猜看啊，反正看不到
private:
	std::string secret;
};
int main()
{
	Test3 t1;
	t1.show();
	return 0;
}