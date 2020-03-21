#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<map>
using namespace std;

class OrderFile
{
public:
	//默认构造
	OrderFile();

	//更新预约记录
	void updateOrder();


	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器   key为记录条数，value具体记录键值对信息
	map<int, map<string, string>>m_orderData;
};