#pragma once
#include"identity.h"
#include"teacher.h"
#include"student.h"
#include"computerRoom.h"
#include<vector>

class Manager :public Identity
{
public:
	//����Ա���
	int m_ManId;
	//����Ա����
	string m_ManName;
	//����Ա����
	string m_ManPwd;
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(int manId, string name, string pwd);
	//��ʾ����Ա�˵�
	virtual void operMenu();
	//����˺�
	void addAccount();
	//�鿴������Ϣ
	void showComputerRoom();
	//�鿴�˺�
	void showAccount();
	//���ԤԼ��¼
	void clearOrder();
	//��ʼ������
	void initVector();
	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//��������
	vector<ComputerRoom>vCom;
	//�ж��Ƿ�ID�ظ�
	bool checkRepeat(int id, int type);
	


};