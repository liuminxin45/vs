#include"student.h"
#include"computerRoom.h"
#include"globeFile.h"
#include<vector>
#include<fstream>
#include<string>
#include<cstring>
#include"orderfile.h"


//Ĭ�Ϲ���
Student::Student()
{

}
//�вι���    ��ӻ���Ŀǰ��Ϣ����vector������װ֮
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ��������Ϣ��ʵ����Student����ʱ��������Ϣ�Զ����ɵ�vCom������
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	this->vCom;
	ComputerRoom c;
	while (ifs >> c.m_Num&& ifs >> c.m_MaxCap)
		vCom.push_back(c);
	ifs.close();
}
//�˵�����
void Student::operMenu()
{
	cout << "��ӭ"<<this->m_Name<<"ͬѧ����ѡ��" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�Լ���ԤԼ" << endl;
	cout << "3.�鿴����ȫ��ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "0.ע����½" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	int date = 0;
	int interval = 0;
	int room = 0;


	while (true)
	{
		cout << "��������ʱ��Ϊ��һ�����壡" << endl;
		cout << "��ѡ������ԤԼ��ʱ�䣺" << endl;
		cout << "1.��һ" << endl;
		cout << "2.�ܶ�" << endl;
		cout << "3.����" << endl;
		cout << "4.����" << endl;
		cout << "5.����" << endl;
		cin >> date;
		if (date > 0 && date < 6)
			break;
		system("cls");
		cout << "�����������������룺" << endl;

	}
	system("cls");

	while (true)
	{
		
		cout << "��ѡ��ʱ��Σ�" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;

		cin >> interval;
		if (interval ==1 || interval ==2)
			break;
		system("cls");
		cout << "�����������������룺" << endl;

	}

	while (true)
	{

		cout << "��ѡ��ԤԼ������" << endl;
		for (int i = 0; i < this->vCom.size(); i++)
			cout <<"������ţ�"<< this->vCom[i].m_Num << "\t" << "����������"<< this->vCom[i].m_MaxCap << endl;
		cout << endl;
		cout << "------------------------------------------------" << endl;
		cout << "1.һ�Ż���" << endl;
		cout << "2.���Ż���" << endl;
		cout << "3.���Ż���" << endl;

		cin >> room;
		if (room == 1 || room == 2 || room ==3)
			break;
		system("cls");
		cout << "�����������������룺" << endl;
		
	}
	cout << "ԤԼ�ɹ��������..." << endl;

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
//�鿴�Լ���ԤԼ
void Student::showMyOrder()
{
	system("cls");
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuID"].c_str()))
		{
			cout << "ԤԼ���ڣ�����" << of.m_orderData[i]["date"] << "\t";
			cout << "ԤԼʱ�Σ�" << (of.m_orderData[i]["interval"] = "1" ? "����" : "����") << "\t";
			cout << "������ţ�" << of.m_orderData[i]["roomID"] << "\t";
			cout << "ԤԼ״̬��"; //<< of.m_orderData[i]["status"];
			//�ж�status
			string S;
			int s = atoi(of.m_orderData[i]["status"].c_str());
			switch (s)
			{
			case 1:
				S = "ԤԼ��";
				break;
			case 2:

				S = "ԤԼ�ɹ�";
				break;
			case -1:
				S = "ԤԼʧ��";
				break;
			}
			
			cout << S << endl << endl;
		}
	}
}
//��ʾ�����˵�ԤԼ
void Student::showAllOrder()
{
	system("cls");
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "ԤԼ���ڣ�����" << of.m_orderData[i]["date"] << "\t";
		cout << "ԤԼʱ�Σ�" << (of.m_orderData[i]["interval"] = "1" ? "����" : "����") << "\t";
		cout << "������ţ�" << of.m_orderData[i]["roomID"] << "\t";
		cout << "ԤԼѧ����" << of.m_orderData[i]["stuName"] << "\t";
		cout << "ѧ��ѧ�ţ�" << of.m_orderData[i]["stuID"] << "\t";
		cout << "ԤԼ״̬��"; //<< of.m_orderData[i]["status"];
		//�ж�status
		string S;
		int s = atoi(of.m_orderData[i]["status"].c_str());
		switch (s)
		{
		case 0:
			S = "ȡ��ԤԼ";
			break;
		case 1:
			S = "ԤԼ��";
			break;
		case 2:

			S = "ԤԼ�ɹ�";
			break;
		case -1:
			S = "ԤԼʧ��";
			break;
		}
		cout << S << endl << endl;
	}
}
//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	//ɾ��ԤԼ��¼->  1���������ɾ��      2�����԰�ԤԼ״̬���óɣ�ȡ��ԤԼ
	//������õڶ���
	//����map<int, map<string, string>>m_orderData����m_orderData�Ž�vector�����ұ�����ӡ
	//Ҫ�޸ĵ�vector[i]->second->[]["status"]=0;
	vector<map<string, string>> temp;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_Id)
			temp.push_back(of.m_orderData[i]);
	}
	cout << "��ѡ����Ҫȡ����ԤԼ��" << endl;
	int i = 0;
	for (vector<map<string, string>>::iterator it = temp.begin(); it != temp.end(); it++ )
	{
		cout << i << "." << "ѧ�ţ�" << (*it)["stuID"] << " " << "������" << (*it)["stuName"] << " "
			<< "ԤԼ���ڣ���" << (*it)["date"] << " " << "ʱ�Σ�" << (*it)["interval"] << " "
			<< "ԤԼ״̬��";

		
		//�ж�statusԤԼ״̬
		string S;
		int s = atoi(of.m_orderData[i]["status"].c_str());
		switch (s)
		{
		case 0:
			S = "ȡ��ԤԼ";
			break;
		case 1:
			S = "ԤԼ��";
			break;
		case 2:

			S = "ԤԼ�ɹ�";
			break;
		case -1:
			S = "ԤԼʧ��";
			break;
		}
		cout << S << endl;
		i++;
	}
	int select = 0;
	cin >> select;

	//Ѱ����m_orderData����֮ƥ��ļ�¼
	for (int x = 0; x < of.m_Size; x++)
	{
		if (temp[select]["stuID"] == of.m_orderData[x]["stuID"] &&
			temp[select]["stuName"] == of.m_orderData[x]["stuName"] &&
			temp[select]["date"] == of.m_orderData[x]["date"] &&
			temp[select]["interval"] == of.m_orderData[x]["interval"] &&
			temp[select]["status"] == of.m_orderData[x]["status"]
			)
		{
			//�ҵ��ˣ����ڿ�ʼ�޸�status��״̬
			of.m_orderData[x]["status"] = "0";
			cout << "ȡ��ԤԼ�ɹ���" << endl;
			return;
		}
	}

	//����һ��ԤԼ��¼
	void updateOrder();
}