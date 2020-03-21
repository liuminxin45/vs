//#include<iostream>
//using namespace std;
//#include<fstream>
//
//
//int main()
//{
//	
//	int x = 0;
//	ofstream ofs;
//	ofs.open("yearm.txt", ios::trunc);
//	int year;
//	int month;
//	int day;
//	int sum_day = 0;
//	int flag = -1;
//	for (year = 2011; year < 2020; year++)
//	{
//		
//		for (month = 1; month < 13; month++)
//		{
//			if (month <= 8)
//			{
//				if (month % 2 == 1) flag = 1;
//				else if (month % 2 == 0 && month != 2) flag = 2;
//				else flag = 3;
//				switch (flag)
//				{
//				case 1:
//					sum_day = 31;
//					break;
//				case 2:
//					sum_day = 30;
//					break;
//				case 3:
//					sum_day = 29;
//					break;
//				default:
//					break;
//				}
//			}
//			else 
//			{
//				if (month % 2 == 1) flag = 2;
//				else if (month % 2 == 0) flag = 1;
//				switch (flag)
//				{
//				case 1:
//					sum_day = 31;
//					break;
//				case 2:
//					sum_day = 30;
//					break;
//				default:
//					break;
//				}
//			}
//			
//			
//			for (day = 1; day <= sum_day; day++)
//			{
//				ofs << year;
//				if (month < 10)
//					ofs << 0;
//				ofs << month;
//				if (day < 10)
//					ofs << 0;
//				ofs << day << endl;
//			}
//		}
//	}
//	ofs.close();
//	return 0;
//}
