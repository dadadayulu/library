#include<iostream>
#include"CBook.h"
#include"CStudent.h"
#include"CManagementBooks.h"
#include"CTeacher.h"
#include<fstream>
#include"CAdministrator.h"
#include"COperationManagement.h"
using namespace std;
int main()
{
	CManagementBooks mb;
	CUser* user = nullptr;
	COperationManagement om;
	om.init(mb);
	cout << "***** ��ӭ����ͼ��� *****" << endl;
	//cout << "ע������" << endl;
	//cout << "1.ѧ����๲�ɽ�������,��ʦ��๲�ɽ��屾"<<endl<<endl;
	cout << "��ѡ�����ĵ�¼��ʽ 1:��ʦ 2:ѧ�� 3:����Ա" << endl;
	int t;
	cin >> t;
	if (t == 1)
	{
		user = new CTeacher;
	}
	else if(t == 2)
	{
		user = new CStudent;
	}
	else if(t == 3)
	{
		CAdministrator admin;
		om.adminLogin(admin);
		admin.showInfo();
		om.adminOperation(admin, mb);
		return 0;
	}
	cout << "���Ƿ������˺ţ�(y/n):" << endl;
	string c;
	cin >> c;
	if (c == "y")
	{
		cout << "���¼:" << endl;
		om.login(user,t);
		user->showInfo();
	}
	else
	{
		cout << "��ע��һ����!" << endl;
		om.Register(user,t);
	}
	om.userOperation(user, mb);
	delete user;
	return 0;
	

}