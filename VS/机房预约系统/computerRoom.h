#pragma once
#include<iostream>
using namespace std;

class ComputerRoom
{
public:
	//Ĭ�Ϲ���
	ComputerRoom()
	{

	}


	//�вι���
	ComputerRoom(int num, int maxCap)
	{
		m_Num = num;
		m_MaxCap = maxCap;

	}

	int m_Num;
	int m_MaxCap;

};