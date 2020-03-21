#include<iostream>
#include<fstream>
#include"identity.h"
#include"globeFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
#include<string>

using namespace std;

//管理员菜单全局函数 
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();
		Manager* man = (Manager*)manager;
		//功能选择
		int select = 0;
		//
		cin >> select;
		switch (select)
		{
				/*1.添加账号
				2.查看账号
				3.查看机房
				4.清空预约
				0.注销登陆*/
		case 1:
			man->addAccount();
			break;
		case 2:
		{
			man->initVector();
			man->showAccount();
			break;
		}
		case 3:
			man->showComputerRoom();
			break;
		case 4:
			man->clearOrder();
			break;
		case 0:
		{
			delete manager;
			cout << "注销成功！"<<endl;
			system("pause");
			system("cls");
			return;
			break;
		}
		default:
			cout << "输入错误请重新输入：" << endl;
			break;
		}
	}
}

//学生菜单全局函数
void studentMenu(Identity* & student)
{
	while (true)
	{
		student->operMenu();
		int select = 0;
		cin >> select;
		Student* man = (Student*)student;
		/*"1.申请预约" 
		"2.查看自己的预约" 
		"3.查看机房全部预约"
		"4.取消预约" 
		"0.注销登陆" */
		switch (select)
		{
		case 1:
			man->applyOrder();
			break;
		case 2:
			man->showMyOrder();
			break;
		case 3:
			man->showAllOrder();
			break;
		case 4:
			man->cancelOrder();
			break;
		case 0:
		{
			delete man;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
			break;
		default:
		{
			cout << "输入有误请重新输入：" << endl;
			system("pause"); 
		}
			break;
		}
	}
}

//登陆功能
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号： " << endl;
		cin >> id;
	}
	else
	{
		cout << "请输入管理员账号：" << endl;
		cin >> id;
	}
	cout << "请输入你的用户名： " << endl;
	cin >> name;
	cout << "请输入你的密码： " << endl;
	cin >> pwd;

	int fId = 0;
	string fName;
	string fPwd;
	while (ifs >> fId && ifs >> fName && ifs >> fPwd)
	{
		if(fId == id && fName == name && fPwd == pwd)
		{
			system("cls");
			cout << "验证成功！" << endl;
			system("pause");
			system("cls");
			//进入各自子菜单
			{
				if (type == 1)
				{
					//进入学生子菜单
					//创建该学生
					person = new Student(id, name, pwd);    //之前在student.h头文件中，Student类中的纯虚函数后面有个 = 0，报错！
					studentMenu(person);
				}
				else if (type == 2)
				{
					//进入老师子菜单
					cout << "欢迎" << fName << "老师！" << endl;
					person = new Teacher(id, name, pwd);

				}
				else if(type == 3)
				{
					//进入管理员子菜单
					cout << "欢迎管理员：" << fName << endl;
					person = new Manager(id, name, pwd);
					managerMenu(person);
				}
			}
			return;
		}
	}
	cout << "登陆验证失败" << endl;
	system("pause");
	system("cls");
}


int main()
{
	
	int choice = 0;
	while (true)
	{
		cout << "============  欢迎进入机房预约系统  ============" << endl;
		cout << "请输入您的身份： " << endl;
		cout << "\t\t||    1.学生\n";
		cout << "\t\t||          \n";
		cout << "\t\t||    2.老师\n";
		cout << "\t\t||          \n";
		cout << "\t\t||    3.管理\n";
		cout << "\t\t||          \n";
		cout << "\t\t||    0.退出\n";
		cout << "\t\t||          \n";
		cout << "请输入您的选择： " << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			{
				cout << "欢迎下次使用！" << endl;
				system("pause");
				return 0;
			}
		default:
			cout << "输入有误，请重新输入：\n";
		}
		system("pause");
		system("cls");
	}
	return 0;
}

