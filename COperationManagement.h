#pragma once
#include<iostream>
#include"CBook.h"
#include"CStudent.h"
#include"CManagementBooks.h"
#include"CTeacher.h"
#include<fstream>
#include"CAdministrator.h"
using namespace std;
class COperationManagement
{
public:
	void login(CUser* user, int t);
	void Register(CUser* user, int t);
	void userOperation(CUser* user, CManagementBooks mb);
	void adminLogin(CAdministrator& admin);
	void init(CManagementBooks& mb);
	void adminOperation(CAdministrator admin, CManagementBooks mb);
};

