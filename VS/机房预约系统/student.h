#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"computerRoom.h"
#include<vector>

class Student :public Identity
{
public:

	//默认构造
	Student();
	//有参构造
	Student(int id, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看预约
	void showMyOrder();
	//显示所有人的预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
	//机房容器
	vector<ComputerRoom> vCom;
};