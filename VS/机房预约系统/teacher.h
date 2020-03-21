#pragma once
#include"identity.h"

class Teacher:public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int empid, string name, string pwd);
	//界面菜单
	virtual void operMenu();
	//查看预约
	void showOrder();
	//审核预约
	void managerOrder();
};