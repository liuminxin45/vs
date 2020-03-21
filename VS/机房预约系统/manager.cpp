#include"manager.h"
#include"globeFile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(int manId, string manName, string manPwd)
{
	this->m_ManId = manId;
	this->m_ManName = manName;
	this->m_Pwd = manPwd;
}
//��ʾ����Ա�˵�
void Manager::operMenu()
{
	cout << "================\t��ӭ����Ա\t================\n"
		<< "\n"
		<< "================\t         \t================\n"
		<< "\n"
		<< "================\t1.����˺�\t================\n"
		<< "\n"
		<< "================\t2.�鿴�˺�\t================\n"
		<< "\n"
		<< "================\t3.�鿴����\t================\n"
		<< "\n"
		<< "================\t4.���ԤԼ\t================\n"
		<< "\n"
		<< "================\t0.ע����½\t================\n"
		<< "================\t         \t================\n"
		<< "\n";
}
//����˺�
void Manager::addAccount()
{
	cout << "����������˺����ͣ�" << endl;
	cout << "\n";
	cout << "1.ѧ��\n2.��ʦ" << endl;
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
			tip = "������ѧ�ţ�" ;
			fileName = STUDENT_FILE;
			break;
		}
		else if (select == 2)
		{
			tip = "������ְ����:" ;
			fileName = TEACHER_FILE;
			break;
		}
		else
		{
			cout << "����������������룺" << endl;
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
			cout << "ID�ظ������������룺" << endl;
		}
		else
			break;
	}
	cout << "������������ " << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	//���˺���Ϣд���ļ�
	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");

	ofs.close();
}
//�鿴������Ϣ
void Manager::showComputerRoom()
{
	//��һ�����ٿ�ʼ
	system("cls");
	ifstream ifs;
	cout << "������Ϣ���£�\t" << endl;
	vector<ComputerRoom>vCom;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom s;
	while (ifs >> s.m_Num&& ifs >> s.m_MaxCap)
	{
		vCom.push_back(s);
	}
	cout << "��������" << "\t" << "�����������"<< "\t\t" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << (*it).m_Num << "\t" << (*it).m_MaxCap << "\t" << endl;
	}
	system("pause");
	system("cls");
}
//�鿴�˺�
void Manager::showAccount()
{
	//��txt��Ϣ����������
	ifstream ifs;
	while (true)
	{
		vStu.clear();
		vTea.clear();
		system("cls");
		cout << "�鿴�˺���Ϣ��\n"
			<< endl
			<< "1.ѧ���˺���Ϣ"
			<< endl
			<< "2.��ʦ�˺���Ϣ"
			<< endl;
		int select = 0;
		cin >> select;
		//����һ��
		system("cls");
		if (select == 1)
		{
			Student s;
			ifs.open(STUDENT_FILE, ios::in);
			while (ifs >> s.m_Id&& ifs >> s.m_Name&& ifs >> s.m_Pwd)
				vStu.push_back(s);
			//���ѧ���˺���Ϣ
			cout << "ѧ���˺�����Ϊ��"
				<< vStu.size() << endl << endl;
			cout << "���Ƿֱ��ǣ�" << endl;
			int count = 0;
			cout << "���" << ".\t" << "�˺�ID" << "\t" << "����" << "\t" << "����" << endl << endl;
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
			//�����ʦ�˺���Ϣ
			cout << "��ʦ�˺�����Ϊ��"
				<< vTea.size() << endl << endl;
			cout << "���Ƿֱ��ǣ�" << endl;
			int count = 0;
			cout << "���" << ".\t" << "�˺�ID" << "\t" << "����" << "\t" << "����" << endl << endl;
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
			cout << "������������������" << endl;
			system("pause");
			system("cls");
		}
	}
}
//���ԤԼ��¼
void Manager::clearOrder()
{
	system("cls");
	cout << "ȷ����գ�" << endl << endl;
	cout << "1.ȷ��" << "\t" << "2.ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ifstream ifs;
		ifs.open(ORDER_FILE, ios::trunc|ios::out);
		cout << "��ճɹ���" << endl;
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
//��ʼ��initVector����
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
}
//���IDʱ�鿴�Ƿ��ظ�
bool Manager::checkRepeat(int id, int type)
{
	string tip;
	int checkId;
	string checkName;
	string checkPwd;
	ifstream ifs;
	//ѧ��ID����ѡ��
	if (type == 1)
	{
		tip = STUDENT_FILE;
	}
	//��ʦID����ѡ��
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
