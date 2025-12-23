#include<iostream>
#include"assemble.h"
//电脑类
	//使用构造函数传入三个零件
	Computer::Computer(CPU* cpu,VideCard* vc,Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数
	void Computer::work() {
		//让零件工作起来，调用他们的接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//使用完之后释放三个零件占用的内存
	Computer::~Computer() {
		//释放CPU
		if (m_cpu != nullptr) {
			delete m_cpu;
			m_cpu = nullptr;
		}
		//释放显示器
		if (m_vc != nullptr) {
			delete m_vc;
			m_vc = nullptr;
		}
		//释放内存条
		if (m_mem != nullptr) {
			delete m_mem;
			m_mem = nullptr;
		}
	}

//提供零件的厂商 Intel
	//Cpu 的派生类 
	//开始计算
	void Intel_cpu::calculate() {
		std::cout << "Intel的CPU开始计算！" << std::endl;
	}

	//VideCard 的派生类
	//开始显示
	void Intel_videcard::display() {
		std::cout << "Intel的显示器开始显示！" << std::endl;
	}

	//Memory 的派生类
	//开始存储
	void Intel_memory::storage() {
		std::cout << "Intel的内存条开始存储！" << std::endl;
	}

//提供零件的厂商 Lenovo 同样都是派生类
	//开始计算
	void Lenovo_cpu::calculate() {
		std::cout << "Lenovo的CPU开始计算！" << std::endl;
	}

	//开始显示
	void Lenovo_videcard::display() {
		std::cout << "Lenovo的显示器开始显示！" << std::endl;
	}

	//开始存储
	void Lenovo_memory::storage() {
		std::cout << "Lenovo的内存条开始存储！" << std::endl;
	}

//开始组装电脑
void test() {
	//第一台电脑零件				//创建各个零件的对象，做向上类型转换操作（传统的写法）
	std::cout << "第一台电脑：" << std::endl;
	CPU* intelcpu = new Intel_cpu;
	VideCard* intelvc = new Intel_videcard;	
	Memory* intelmem = new Intel_memory;
	//创建第一台电脑				//使用构造函数将各个零件初始化
	Computer* computer1 = new Computer(intelcpu, intelvc, intelmem);
	computer1->work();				//通过对象访问Computer类中的工作函数，从而根据类型调用派生类中对应的函数
	delete computer1;				//记得释放堆区里的内存
		
	//创建第二台电脑			
	std::cout << std::endl<< "第二台电脑：" << std::endl;	//这是第二种写法，因为构造函数里已经定义了基类的指针来接收
	Computer* computer2 = new Computer(new Lenovo_cpu, new Lenovo_videcard, new Lenovo_memory);
	computer2->work();				
	delete computer2;	

	//创建第三台电脑
	std::cout << std::endl << "第三台电脑：" << std::endl;	
	Computer* computer3 = new Computer(new Lenovo_cpu, new Intel_videcard, new Lenovo_memory);
	computer3->work();
	delete computer3;
}
int main() {
	test();
	return 0;
}