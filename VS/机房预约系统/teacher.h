#pragma once
#include"identity.h"

class Teacher:public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empid, string name, string pwd);
	//����˵�
	virtual void operMenu();
	//�鿴ԤԼ
	void showOrder();
	//���ԤԼ
	void managerOrder();
};