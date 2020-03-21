#include"orderfile.h"
#include"globeFile.h"



OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string room;
	string status;
	string id;
	string name;

	this->m_Size = 0;
	while (ifs >> date && ifs >> interval && ifs >> id && ifs >> name && ifs >> room && ifs >> status)
	{
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = id.find(":");
		if (pos != -1)
		{
			key = id.substr(0, pos);
			value = id.substr(pos + 1, id.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = name.find(":");
		if (pos != -1)
		{
			key = name.substr(0, pos);
			value = name.substr(pos + 1, name.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = room.find(":");
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		}

		
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "key = : " << it->first << "  value = " << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		{
			cout << "key = "<< mit->first << " " << "value = "<< mit->second << endl;
		}
	}*/
}

//更新预约记录
void OrderFile::updateOrder()
{

	
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i] ["date:"]<< " "
			<< "interval:" << m_orderData[i]["interval:"] << " "
			<< "stuID:" << m_orderData[i]["stuID:"] << " "
			<< "stuName:" << m_orderData[i]["stuName:"] << " "
			<< "roomID:" << m_orderData[i]["roomID:"] << " "
			<< "status:" << m_orderData[i]["status:"] << endl;
	}
}
