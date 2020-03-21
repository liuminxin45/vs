#include<iostream>
#include<fstream>
#include"identity.h"
#include"globeFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
#include<string>

using namespace std;

//����Ա�˵�ȫ�ֺ��� 
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();
		Manager* man = (Manager*)manager;
		//����ѡ��
		int select = 0;
		//
		cin >> select;
		switch (select)
		{
				/*1.����˺�
				2.�鿴�˺�
				3.�鿴����
				4.���ԤԼ
				0.ע����½*/
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
			cout << "ע���ɹ���"<<endl;
			system("pause");
			system("cls");
			return;
			break;
		}
		default:
			cout << "����������������룺" << endl;
			break;
		}
	}
}

//ѧ���˵�ȫ�ֺ���
void studentMenu(Identity* & student)
{
	while (true)
	{
		student->operMenu();
		int select = 0;
		cin >> select;
		Student* man = (Student*)student;
		/*"1.����ԤԼ" 
		"2.�鿴�Լ���ԤԼ" 
		"3.�鿴����ȫ��ԤԼ"
		"4.ȡ��ԤԼ" 
		"0.ע����½" */
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
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
			break;
		default:
		{
			cout << "�����������������룺" << endl;
			system("pause"); 
		}
			break;
		}
	}
}

//��½����
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ� " << endl;
		cin >> id;
	}
	else
	{
		cout << "���������Ա�˺ţ�" << endl;
		cin >> id;
	}
	cout << "����������û����� " << endl;
	cin >> name;
	cout << "������������룺 " << endl;
	cin >> pwd;

	int fId = 0;
	string fName;
	string fPwd;
	while (ifs >> fId && ifs >> fName && ifs >> fPwd)
	{
		if(fId == id && fName == name && fPwd == pwd)
		{
			system("cls");
			cout << "��֤�ɹ���" << endl;
			system("pause");
			system("cls");
			//��������Ӳ˵�
			{
				if (type == 1)
				{
					//����ѧ���Ӳ˵�
					//������ѧ��
					person = new Student(id, name, pwd);    //֮ǰ��student.hͷ�ļ��У�Student���еĴ��麯�������и� = 0������
					studentMenu(person);
				}
				else if (type == 2)
				{
					//������ʦ�Ӳ˵�
					cout << "��ӭ" << fName << "��ʦ��" << endl;
					person = new Teacher(id, name, pwd);

				}
				else if(type == 3)
				{
					//�������Ա�Ӳ˵�
					cout << "��ӭ����Ա��" << fName << endl;
					person = new Manager(id, name, pwd);
					managerMenu(person);
				}
			}
			return;
		}
	}
	cout << "��½��֤ʧ��" << endl;
	system("pause");
	system("cls");
}


int main()
{
	
	int choice = 0;
	while (true)
	{
		cout << "============  ��ӭ�������ԤԼϵͳ  ============" << endl;
		cout << "������������ݣ� " << endl;
		cout << "\t\t||    1.ѧ��\n";
		cout << "\t\t||          \n";
		cout << "\t\t||    2.��ʦ\n";
		cout << "\t\t||          \n";
		cout << "\t\t||    3.����\n";
		cout << "\t\t||          \n";
		cout << "\t\t||    0.�˳�\n";
		cout << "\t\t||          \n";
		cout << "����������ѡ�� " << endl;

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
				cout << "��ӭ�´�ʹ�ã�" << endl;
				system("pause");
				return 0;
			}
		default:
			cout << "�����������������룺\n";
		}
		system("pause");
		system("cls");
	}
	return 0;
}

