#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"computerRoom.h"
#include<vector>

class Student :public Identity
{
public:

	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴ԤԼ
	void showMyOrder();
	//��ʾ�����˵�ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//��������
	vector<ComputerRoom> vCom;
};