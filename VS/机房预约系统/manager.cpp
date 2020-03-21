#include"manager.h"
#include"globeFile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(int manId, string manName, string manPwd)
{
	this->m_ManId = manId;
	this->m_ManName = manName;
	this->m_Pwd = manPwd;
}
//显示管理员菜单
void Manager::operMenu()
{
	cout << "================\t欢迎管理员\t================\n"
		<< "\n"
		<< "================\t         \t================\n"
		<< "\n"
		<< "================\t1.添加账号\t================\n"
		<< "\n"
		<< "================\t2.查看账号\t================\n"
		<< "\n"
		<< "================\t3.查看机房\t================\n"
		<< "\n"
		<< "================\t4.清空预约\t================\n"
		<< "\n"
		<< "================\t0.注销登陆\t================\n"
		<< "================\t         \t================\n"
		<< "\n";
}
//添加账号
void Manager::addAccount()
{
	cout << "请输入添加账号类型：" << endl;
	cout << "\n";
	cout << "1.学生\n2.老师" << endl;
	string tip;
	string fileName;
	int Select = 0;
	while (true)
	{
		int select = 0;
		cin >> select;
		Select = select;

		if (select == 1)
		{
			tip = "请输入学号：" ;
			fileName = STUDENT_FILE;
			break;
		}
		else if (select == 2)
		{
			tip = "请输入职工号:" ;
			fileName = TEACHER_FILE;
			break;
		}
		else
		{
			cout << "输入错误，请重新输入：" << endl;
			system("pause");
			system("cls");
		}
	}
	int id;
	string name;
	string pwd;
	while (true)
	{
		cout << tip << endl;
		cin >> id;
		if (checkRepeat(id, Select))
		{
			cout << "ID重复，请重新输入：" << endl;
		}
		else
			break;
	}
	cout << "请输入姓名： " << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	//将账号信息写入文件
	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");

	ofs.close();
}
//查看机房信息
void Manager::showComputerRoom()
{
	//清一下屏再开始
	system("cls");
	ifstream ifs;
	cout << "机房信息如下：\t" << endl;
	vector<ComputerRoom>vCom;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom s;
	while (ifs >> s.m_Num&& ifs >> s.m_MaxCap)
	{
		vCom.push_back(s);
	}
	cout << "机房房间" << "\t" << "机房最大容量"<< "\t\t" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << (*it).m_Num << "\t" << (*it).m_MaxCap << "\t" << endl;
	}
	system("pause");
	system("cls");
}
//查看账号
void Manager::showAccount()
{
	//将txt信息读入容器中
	ifstream ifs;
	while (true)
	{
		vStu.clear();
		vTea.clear();
		system("cls");
		cout << "查看账号信息：\n"
			<< endl
			<< "1.学生账号信息"
			<< endl
			<< "2.老师账号信息"
			<< endl;
		int select = 0;
		cin >> select;
		//清屏一下
		system("cls");
		if (select == 1)
		{
			Student s;
			ifs.open(STUDENT_FILE, ios::in);
			while (ifs >> s.m_Id&& ifs >> s.m_Name&& ifs >> s.m_Pwd)
				vStu.push_back(s);
			//输出学生账号信息
			cout << "学生账号总数为："
				<< vStu.size() << endl << endl;
			cout << "他们分别是：" << endl;
			int count = 0;
			cout << "序号" << ".\t" << "账号ID" << "\t" << "姓名" << "\t" << "密码" << endl << endl;
			for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
			{
				count++;
				cout << count << ".\t" << (*it).m_Id << "\t" << (*it).m_Name << "\t" << (*it).m_Pwd << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		else if (select == 2)
		{
			Teacher s;
			ifs.open(TEACHER_FILE, ios::in);
			while (ifs >> s.m_Id&& ifs >> s.m_Name&& ifs >> s.m_Pwd)
				vTea.push_back(s);
			//输出老师账号信息
			cout << "老师账号总数为："
				<< vTea.size() << endl << endl;
			cout << "他们分别是：" << endl;
			int count = 0;
			cout << "序号" << ".\t" << "账号ID" << "\t" << "姓名" << "\t" << "密码" << endl << endl;
			for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
			{
				count++;
				cout << count << ".\t" << (*it).m_Id <<"\t"<< (*it).m_Name << "\t" << (*it).m_Pwd << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}
}
//清空预约记录
void Manager::clearOrder()
{
	system("cls");
	cout << "确认清空？" << endl << endl;
	cout << "1.确认" << "\t" << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ifstream ifs;
		ifs.open(ORDER_FILE, ios::trunc|ios::out);
		cout << "清空成功！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		system("cls");
		return;
	}
}
//初始化initVector容器
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
}
//添加ID时查看是否重复
bool Manager::checkRepeat(int id, int type)
{
	string tip;
	int checkId;
	string checkName;
	string checkPwd;
	ifstream ifs;
	//学生ID查重选项
	if (type == 1)
	{
		tip = STUDENT_FILE;
	}
	//老师ID查重选项
	if (type == 2)
	{
		tip = TEACHER_FILE;
	}
	ifs.open(tip, ios::in);
	while (ifs >> checkId && ifs >> checkName && ifs >> checkPwd)
	{
		if (id == checkId)
		{
			return true;
		}
	}
	return false;
}
