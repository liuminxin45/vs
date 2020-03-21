#pragma once
#include"identity.h"
#include"teacher.h"
#include"student.h"
#include"computerRoom.h"
#include<vector>

class Manager :public Identity
{
public:
	//管理员编号
	int m_ManId;
	//管理员姓名
	string m_ManName;
	//管理员密码
	string m_ManPwd;
	//默认构造
	Manager();
	//有参构造
	Manager(int manId, string name, string pwd);
	//显示管理员菜单
	virtual void operMenu();
	//添加账号
	void addAccount();
	//查看机房信息
	void showComputerRoom();
	//查看账号
	void showAccount();
	//清空预约记录
	void clearOrder();
	//初始化容器
	void initVector();
	//学生容器
	vector<Student>vStu;
	//老师容器
	vector<Teacher>vTea;
	//机房容器
	vector<ComputerRoom>vCom;
	//判断是否ID重复
	bool checkRepeat(int id, int type);
	


};