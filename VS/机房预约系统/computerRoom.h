#pragma once
#include<iostream>
using namespace std;

class ComputerRoom
{
public:
	//默认构造
	ComputerRoom()
	{

	}


	//有参构造
	ComputerRoom(int num, int maxCap)
	{
		m_Num = num;
		m_MaxCap = maxCap;

	}

	int m_Num;
	int m_MaxCap;

};