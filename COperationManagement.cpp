#include "COperationManagement.h"
//�����¼��ע�ᣬ����Ա����ͼ�飬��ʼ����������������Ϣ�ȴ��ļ��ж�ȡ������
//���������У����ڲ���
void COperationManagement::login(CUser* user, int t)
{
	ifstream readFile;
	ifstream readFile1;
	if (t == 1)
	{
		readFile.open("teacherLogin.txt");
		readFile1.open("teacher.txt");
	}
	else
	{
		readFile1.open("student.txt");
		readFile.open("studentLogin.txt");
	}
	if (!readFile.is_open())
	{
		cout << "��¼���ݶ�ȡ����" << endl;
	}
	if (!readFile1.is_open())
	{
		cout << "�û����ݶ�ȡ����" << endl;
	}
	cout << "����������ѧ����:" << endl;
	string account, password;
	cin >> account;
	int flag = 0;
	while (!readFile.eof())
	{
		string act;
		readFile >> act;
		if (act == account)
		{
			cout << "����������:" << endl;
			cin >> password;
			string pwd;
			readFile >> pwd;
			if (pwd == password)
			{
				cout << "��¼�ɹ�" << endl;
				flag = 1;
				
				while (!readFile1.eof())
				{
					
					readFile1 >> user;
			
					if(user->getId() == act)
					{
						break;
					}
				}
				break;
			}
			else
			{
				cout << "������������µ�¼" << endl;
				login(user, t);
			}
		}

	}
	if (!flag)
	{
		cout << "ѧ���Ŵ�����������" << endl;
		login(user, t);
	}
	readFile.close();
	readFile1.close();
}

void COperationManagement::Register(CUser* user, int t)
{
	ofstream writeFile;
	ofstream writeFile1;
	if (t == 1)
	{
		writeFile1.open("teacher.txt", ios::app);
		writeFile.open("teacherLogin.txt",ios::app);
	}
	else
	{
		writeFile1.open("student.txt", ios::app);
		writeFile.open("studentLogin.txt",ios::app);
	}
	string pwd, act;
	cout << "����������ѧ������Ϊע���˺�:" << endl;
	cin >> act;
	cout << "����������ע������:" << endl;
	cin >> pwd;
	writeFile << endl << act << " " << pwd;
	cout << "������������Ӧ��Ϣ:" << endl;
	string  name, department, gender;
	cout << "��������:" << endl;
	cin >> name;
	cout << "�����Ա�:" << endl;
	cin >> gender;
	cout << "�����ڵ�Ժϵ:" << endl;
	cin >> department;
	writeFile1 <<endl << act << " " << name << " " << gender << " " << department;//���ﲻ����user,��Ϊ�ڵ�¼ʱ���ã����Ҳ�û�г�ʼ��
	writeFile.close();
	writeFile1.close();
	cout << "ע��ɹ��� �Ͻ���¼����ͼ��ܰ�!" << endl;
	login(user, t);
}

void COperationManagement::userOperation(CUser* user, CManagementBooks mb)
{
	while (1)
	{
		cout << "��ѡ�����Ĳ��� 1.���� 2.�鿴�Լ���ǰ������� 3.���� 4.�˳�" << endl;
		int t;
		cin >> t;
		if (t == 1)
		{
			cout << "��ǰͼ���������£�" << endl;
			mb.showCurrentAllBook();
			cout << "�Ƿ�������Ҫ���ĵ�ͼ��(y/n)" << endl;
			string s;
			cin >> s;
			if (s == "y")
			{
				user->borrowBookFromLibrary(mb);
			}
		}
		else if (t == 2)
		{
			mb.checkBorrowedBook(user->getId());
		}
		else if (t == 3)
		{
			user->returnBook(mb);
		}
		else if (t == 4)
		{
			cout << "�˳��ɹ�" << endl;
			break;
		}
		else
		{
			cout << "���޴˲������밴��ʾ����" << endl;
		}
	}
}

void COperationManagement::adminLogin(CAdministrator& admin)
{
	ifstream readFile("adminLogin.txt");
	ifstream readFile1("admin.txt");
	cout << "���������Ĺ���:" << endl;
	string account, password;
	cin >> account;
	int flag = 0;
	while (!readFile.eof())
	{
		string act;
		readFile >> act;
		if (act == account)
		{
			cout << "����������:" << endl;
			cin >> password;
			string pwd;
			readFile >> pwd;
			if (pwd == password)
			{
				cout << "��¼�ɹ�,��ӭ��" << endl;
				flag = 1;

				while (!readFile1.eof())
				{
					
					readFile1 >> admin;
					if(admin.getId() == act)
					{
						break;
					}
				}
				break;
			}
			else
			{
				cout << "������������µ�¼" << endl;
				adminLogin(admin);
			}
		}

	}
	if (!flag)
	{
		cout << "ѧ���Ŵ�����������" << endl;
		adminLogin(admin);
	}
	readFile.close();
	readFile1.close();

}

void COperationManagement::init(CManagementBooks& mb)
{
	mb.initBooks();
	mb.initOutBook();
}

void COperationManagement::adminOperation(CAdministrator admin, CManagementBooks mb)
{
	while (1)
	{
		cout << "��ѡ�����Ĳ��� 1.������ 2.�鿴��ǰ������� 3.�鿴��ǰ����ͼ����Ϣ��� 4.�鿴��������ϸ��Ϣ 5.ɾ��ͼ�� 6.�޸�ͼ����Ϣ 7.�˳�" << endl;
		int t;
		cin >> t;
		if (t == 1)
		{
			admin.addBook(mb);
		}
		else if (t == 2)
		{
			mb.checekOutBook();
		}
		else if (t == 3)
		{
			mb.showAllBooksInfo();
		}
		else if (t == 4)
		{
			string id;
			cout << "��������Ҫ�鿴�����˵�ѧ����:" << endl;
			cin >> id;
			mb.viewBorrowerDetails(id);
		}
		else if (t == 5)
		{
			mb.showAllBooksInfo();
			string bookName, bookAuthor;
			cout << "��������Ҫɾ����ͼ������:" << endl;
			cin >> bookName;
			cout << "��������Ҫɾ����ͼ������:" << endl;
			cin >> bookAuthor;
			mb.deleteBooke(bookAuthor, bookName);
			mb.showAllBooksInfo();
		}
		else if (t == 6)
		{
			mb.showAllBooksInfo();
			string bookName,bookAuthor;
			cout << "��������Ҫ�޵�ͼ������:" << endl;
			cin >> bookName;
			cout << "��������Ҫ�޵�ͼ������:" << endl;
			cin >> bookAuthor;
			mb.modifyBook(bookAuthor, bookName);
		}
		else if (t == 7)
		{
			cout << "�˳��ɹ�" << endl;
			break;
		}
		else
		{
			cout << "���޴˲������밴��ʾ����" << endl;
		}
	}
}


