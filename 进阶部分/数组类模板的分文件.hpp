#pragma once
#include<iostream>								//通用的数组类
#include<string>
template<typename T>
class my_array
{
public:
	//使用构造函数初始化
	my_array(int capacity)  //初始化，重点根据容量开辟数组
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->p_address = new T[this->m_capacity]; //开辟数组的堆区
	}

	//使用拷贝构造函数深拷贝，防止出错
	my_array(const my_array& arr)
	{
		//拷贝构造函数就是做赋值，只是建立的是"副本"
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//深拷贝，解决浅拷贝的问题
		this->p_address = new T[arr.m_capacity];

		//如果传进来的对象里有数据，将数据拷贝到数组里
		for (int i = 0; i < this->m_size; i++)
		{
			this->p_address[i] = arr.p_address[i];
		}
	}

	//使用赋值运算符重载解决浅拷贝问题
	my_array& operator=(const my_array& arr) //const 防止源数据被意外修改
	{
		//先判断原来堆区里是否有数据，有就释放
		if (this->p_address != NULL)
		{
			delete[] this->p_address;
			this->p_address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}

		//深拷贝，跟拷贝构造函数类似
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->p_address = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->p_address[i] = arr.p_address[i];
		}
		return *this;
	}
	
	//尾插法
	void push_back(T& val)
	{
		if (this->m_capacity == this->get_size())  //如果容量大小一致说明空间不足
		{
			return;
		}
		this->p_address[this->m_size] = val;    //将数据插入到末尾，因为下标从0开始，所以这里可以直接用
		this->m_size++; //更新大小
	}

	//尾删法
	void pop_back()
	{
		if (this->get_size() == 0)  //如果为0证明没有数据
		{
			return;
		}
		this->m_size--;			//将最后一位逻辑删除，使访问不到
	}

	//operator[] 中括号重载 使对象也可以使用[index] 访问数组元素
	T& operator[](int index) //传入下标，返回具体元素
	{
		return this->p_address[index];
	}
	//获取数组容量
	int get_capacity()
	{
		return this->m_capacity;
	}

	//获取数组大小
	int get_size()
	{
		return this->m_size;
	}

	//析构函数释放堆区数据并给成员变量清零
	~my_array()
	{
		if (this->p_address != NULL)
		{
			delete[] this->p_address;
			this->p_address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
	}
private:
	//指针指向堆区开辟的真实数组
	T* p_address;
	//数组的容量
	int m_capacity;
	//数组的大小
	int m_size;
};