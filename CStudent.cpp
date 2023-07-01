#include "CStudent.h"
#include<fstream>
using  namespace std;


CStudent::CStudent()
{
    m_class = "���";
}

void CStudent::showInfo()
{
    cout << "����:" << m_name << " " << "ѧ��:" << m_id << " " << "�Ա�:" << m_gender << " " << "Ժϵ:" << m_department << " "<<"�༶:"<<m_class<<endl;
}

void CStudent::borrowBookFromLibrary(CManagementBooks& mb)//���߽��Ĺ���
{
    int all = mb.checkBorrowedBook(m_id);
    if (all < 3)
    {
        string name;
        cout << "��������Ҫ�������:" << endl;
        cin >> name;
        if (mb.borrow(name))
        {
            ofstream writeFile("borrowedBook.txt", ios::app);
            mb.setMapValue(m_id, name);
            writeFile << endl << m_id << " " << name;
            writeFile.close();
        }
    }
    else
    {
        cout << "���Ѿ����������ɽ�����" << endl;
    }
    
}



void CStudent::setClass(string Class)
{
    m_class = Class;
}



string CStudent::getClass()
{
    return m_class;
}


