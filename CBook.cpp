#include "CBook.h"//���ڶ�����󣬲�ʵ����>>�����أ������ļ����룬����
#include <iostream>
#include<fstream>
using namespace std;


CBook::CBook()
{
	string b = "";
	string randStr = "0123456789X";
	for (int i = 0; i <= 12; i++)
	{
		if (i == 1 || i == 5 || i == 11)
		{
			b += '-';
		}
		else
		{
			if (i == 12)
			{
				b += randStr[rand() % 11];
			}
			else
			{
				b += randStr[rand() % 10];
			}
		}
	}
	m_num = 1;
	m_name = "�ȴ����";
	m_author = "����Ԫ";
	m_isbn = b;
	m_page = rand();
	m_pressInfo = "�ܻԳ�����";
	m_price = rand();
}

void CBook::setNum(int num)
{
	m_num = num;
}

int CBook::getNum()
{
	return m_num;
}


void CBook::setName(string name)
{
	m_name = name;
}

string CBook::getName()
{
	return m_name;
}

void CBook::setIsbn(string isbn)
{
	m_isbn = isbn;
}

string CBook::getIsbn()
{
	return m_isbn;
}

void CBook::setPressInfo(string perssInfo)
{ 
	m_pressInfo = perssInfo;
}

string CBook::getPressInfo()
{
	return m_pressInfo;
}

void CBook::setPrice(double price)
{
	m_price = price;
}

double CBook::getPrice()
{
	return m_price;
}

void CBook::setPage(int page)
{
	m_page = page;

}

int CBook::getPage()
{
	return m_page;
}

void CBook::setAuthor(string author)
{
	m_author = author;
}

string CBook::getAuthor()
{
	return m_author;
}


void CBook::checkIsnb()
{
	int sum = 0;
	for (int i = 0, j = 1; i < m_isbn.size(); i++) {
		if (m_isbn[i] != '-' && i != 12) {
			sum += (m_isbn[i] - '0') * j;
			j++;
		}

	}
	sum %= 11;
	char c = 'X';
	if (sum < 10) c = sum + '0';
	if (m_isbn[12] == c) puts("This book isbn are Right!");
	else puts("This book isbn are wrong!");
}



bool CBook::isBorrowed()
{
	if (m_num >= 1)
	{
		m_num--;
		return true;
	}
	return false;
}

void CBook::showInfo()
{
	cout<<"����:" << m_author << " "<<"isbn����:" << m_isbn << " " <<"�鱾����:"<< m_name << " "
		<<"��ҳ��:" << m_page << " " <<"������:" << m_pressInfo << " " <<"�۸�:" << m_price
		<< " " <<"ʣ�౾��:"<<m_num<< endl;
}

std::ostream& operator <<(std::ostream& os, const CBook& book)
{
	os << endl <<book.m_name << " " <<book.m_isbn << " " << book.m_pressInfo << " " <<book.m_price << " " << book.m_page << " " << book.m_author << " " << book.m_num;
	return os;
}

std::istream& operator>>(std::istream& is, CBook& book)
{
	is >> book.m_name >> book.m_isbn >> book.m_pressInfo >> book.m_price >>book.m_page >> book.m_author >> book.m_num;
	return is;
}
