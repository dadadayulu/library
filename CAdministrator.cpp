#include "CAdministrator.h"
void CAdministrator::addBook(CManagementBooks& mb)
{
	CBook book;
	cout << "��ǰͼ����������" << endl;
	mb.showAllBooksInfo();
	cout << "��������Ҫ���ӵ�ͼ����Ϣ:" << endl;
	string name, author;
	double price;
	int num;
	cout << "���������ӵ�ͼ��������" << endl;
	cin >> name;
	cout << "���������ӵ�ͼ������ߣ�" << endl;
	cin >> author;
	cout << "���������ӵ�ͼ��۸�" << endl;
	cin >> price;
	cout << "���������ӵ�ͼ��ı��飺" << endl;
	cin >> num;
	book.setName(name);
	book.setAuthor(author);
	book.setNum(num);
	book.setPrice(price);
	mb.addBook(book);
	cout << "����ͼ��ɹ�" << endl;
}
void  CAdministrator::setId(string id)
{
	m_id = id;
}

void CAdministrator::setName(string name)
{
	m_name = name;
}

void CAdministrator::setGender(string gender)
{
	m_gender = gender;
}
void CAdministrator::setDepartment(string department)
{
	m_department = department;
}
void CAdministrator::showInfo()
{
	cout << "����:" << m_name << " " << "����:" << m_id << " " << "�Ա�:" << m_gender << " " << "����:" << m_department <<endl;
}

std::istream& operator>>(std::istream& is, CAdministrator& admin)
{
	is >> admin.m_id >> admin.m_name >> admin.m_gender >> admin.m_department;
	return is;
}
string CAdministrator::getId()
{
	return m_id;
}

string CAdministrator::getName()
{
	return m_name;
}

string  CAdministrator::getGender()
{
	return m_gender;
}


string  CAdministrator::getDepartment()
{
	return m_department;
}
