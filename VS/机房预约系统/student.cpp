#include"student.h"
#include"computerRoom.h"
#include"globeFile.h"
#include<vector>
#include<fstream>
#include<string>
#include<cstring>
#include"orderfile.h"


//默认构造
Student::Student()
{

}
//有参构造    添加机房目前信息，以vector容器来装之
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//初始化机房信息，实例化Student个体时，机房信息自动生成到vCom容器中
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	this->vCom;
	ComputerRoom c;
	while (ifs >> c.m_Num&& ifs >> c.m_MaxCap)
		vCom.push_back(c);
	ifs.close();
}
//菜单界面
void Student::operMenu()
{
	cout << "欢迎"<<this->m_Name<<"同学，请选择：" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看自己的预约" << endl;
	cout << "3.查看机房全部预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.注销登陆" << endl;
}

//申请预约
void Student::applyOrder()
{
	int date = 0;
	int interval = 0;
	int room = 0;


	while (true)
	{
		cout << "机房开放时间为周一至周五！" << endl;
		cout << "请选择申请预约的时间：" << endl;
		cout << "1.周一" << endl;
		cout << "2.周二" << endl;
		cout << "3.周三" << endl;
		cout << "4.周四" << endl;
		cout << "5.周五" << endl;
		cin >> date;
		if (date > 0 && date < 6)
			break;
		system("cls");
		cout << "输入有误请重新输入：" << endl;

	}
	system("cls");

	while (true)
	{
		
		cout << "请选择时间段：" << endl;
		cout << "1.上午" << endl;
		cout << "2.下午" << endl;

		cin >> interval;
		if (interval ==1 || interval ==2)
			break;
		system("cls");
		cout << "输入有误请重新输入：" << endl;

	}

	while (true)
	{

		cout << "请选择预约机房：" << endl;
		for (int i = 0; i < this->vCom.size(); i++)
			cout <<"机房编号："<< this->vCom[i].m_Num << "\t" << "机房容量："<< this->vCom[i].m_MaxCap << endl;
		cout << endl;
		cout << "------------------------------------------------" << endl;
		cout << "1.一号机房" << endl;
		cout << "2.二号机房" << endl;
		cout << "3.三号机房" << endl;

		cin >> room;
		if (room == 1 || room == 2 || room ==3)
			break;
		system("cls");
		cout << "输入有误请重新输入：" << endl;
		
	}
	cout << "预约成功！审核中..." << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " " 
		<< "interval:" << interval << " " 
		<< "stuID:" << this->m_Id << " " 
		<< "stuName:" << this->m_Name << " " 
		<< "roomID:" << room << " " 
		<< "status:" << 1 <<endl;

	ofs.close();

	system("pause");
	system("cls");


}
//查看自己的预约
void Student::showMyOrder()
{
	system("cls");
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuID"].c_str()))
		{
			cout << "预约日期：星期" << of.m_orderData[i]["date"] << "\t";
			cout << "预约时段：" << (of.m_orderData[i]["interval"] = "1" ? "上午" : "下午") << "\t";
			cout << "机房编号：" << of.m_orderData[i]["roomID"] << "\t";
			cout << "预约状态："; //<< of.m_orderData[i]["status"];
			//判断status
			string S;
			int s = atoi(of.m_orderData[i]["status"].c_str());
			switch (s)
			{
			case 1:
				S = "预约中";
				break;
			case 2:

				S = "预约成功";
				break;
			case -1:
				S = "预约失败";
				break;
			}
			
			cout << S << endl << endl;
		}
	}
}
//显示所有人的预约
void Student::showAllOrder()
{
	system("cls");
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "预约日期：星期" << of.m_orderData[i]["date"] << "\t";
		cout << "预约时段：" << (of.m_orderData[i]["interval"] = "1" ? "上午" : "下午") << "\t";
		cout << "机房编号：" << of.m_orderData[i]["roomID"] << "\t";
		cout << "预约学生：" << of.m_orderData[i]["stuName"] << "\t";
		cout << "学生学号：" << of.m_orderData[i]["stuID"] << "\t";
		cout << "预约状态："; //<< of.m_orderData[i]["status"];
		//判断status
		string S;
		int s = atoi(of.m_orderData[i]["status"].c_str());
		switch (s)
		{
		case 0:
			S = "取消预约";
			break;
		case 1:
			S = "预约中";
			break;
		case 2:

			S = "预约成功";
			break;
		case -1:
			S = "预约失败";
			break;
		}
		cout << S << endl << endl;
	}
}
//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	//删除预约记录->  1、可以真的删除      2、可以把预约状态设置成，取消预约
	//这里采用第二种
	//遍历map<int, map<string, string>>m_orderData，将m_orderData放进vector，并且遍历打印
	//要修改的vector[i]->second->[]["status"]=0;
	vector<map<string, string>> temp;

	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id)
			temp.push_back(of.m_orderData[i]);
	}
	cout << "请选择你要取消的预约：" << endl;
	int i = 0;
	for (vector<map<string, string>>::iterator it = temp.begin(); it != temp.end(); it++ )
	{
		cout << i << "." << "学号：" << (*it)["stuID"] << " " << "姓名：" << (*it)["stuName"] << " "
			<< "预约日期：周" << (*it)["date"] << " " << "时段：" << (*it)["interval"] << " "
			<< "预约状态：";

		
		//判断status预约状态
		string S;
		int s = atoi(of.m_orderData[i]["status"].c_str());
		switch (s)
		{
		case 0:
			S = "取消预约";
			break;
		case 1:
			S = "预约中";
			break;
		case 2:

			S = "预约成功";
			break;
		case -1:
			S = "预约失败";
			break;
		}
		cout << S << endl;
		i++;
	}
	int select = 0;
	cin >> select;

	//寻找在m_orderData中与之匹配的记录
	for (int x = 0; x < of.m_Size; x++)
	{
		if (temp[select]["stuID"] == of.m_orderData[x]["stuID"] &&
			temp[select]["stuName"] == of.m_orderData[x]["stuName"] &&
			temp[select]["date"] == of.m_orderData[x]["date"] &&
			temp[select]["interval"] == of.m_orderData[x]["interval"] &&
			temp[select]["status"] == of.m_orderData[x]["status"]
			)
		{
			//找到了，现在开始修改status的状态
			of.m_orderData[x]["status"] = "0";
			cout << "取消预约成功！" << endl;
			return;
		}
	}

	//更新一下预约记录
	void updateOrder();
}