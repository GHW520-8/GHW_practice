#pragma once
#include<iostream>
//抽象的CPU类
class CPU {
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};

//抽象的显卡类
class VideCard {
public:
	//抽象的显示函数
	virtual void display() = 0;
};

//抽象的内存条类
class Memory {
public:
	//抽象的存储函数
	virtual void storage() = 0;
};

//电脑类
class Computer {
public:
	//使用构造函数传入三个零件
	Computer(CPU* cpu, VideCard* vc, Memory* mem);
	//提供工作的函数
	void work();
	//使用完之后释放三个零件的内存
	~Computer();
private:
	CPU* m_cpu;
	VideCard* m_vc;
	Memory* m_mem;
};

//提供零件的厂商 Intel
class Intel_cpu : public CPU {
public:
	//开始计算
	virtual void calculate();
};

class Intel_videcard : public VideCard {
public:
	//开始显示
	virtual void display();
};

class Intel_memory : public Memory {
public:
	//开始存储
	virtual void storage();
};

//提供零件的厂商 Lenovo
class Lenovo_cpu : public CPU {
public:
	//开始计算
	virtual void calculate();
};
 
class Lenovo_videcard : public VideCard {
public:
	//开始显示
	virtual void display();
};
class Lenovo_memory : public Memory {
public:
	//开始存储
	virtual void storage();
};
