#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<map>
using namespace std;

class OrderFile
{
public:
	//Ĭ�Ϲ���
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();


	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������   keyΪ��¼������value�����¼��ֵ����Ϣ
	map<int, map<string, string>>m_orderData;
};