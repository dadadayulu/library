#include "CTeacher.h"
#include<fstream>

CTeacher::CTeacher()
{
    m_name = "��һ";
}

void CTeacher::borrowBookFromLibrary(CManagementBooks& mb)
{
   
        int all = mb.checkBorrowedBook(m_id);
        if (all < 5)
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
void CTeacher::showInfo()
{
    cout << "����:" << m_name<<" " << "����:" << m_id<<" " << "�Ա�:" << m_gender<<" " << "Ժϵ:" << m_department << endl;
}


