#include "CManagementBooks.h"//用户所有的相关操作的中间执行者，有设计模式中代理的思想
using namespace std;

void CManagementBooks::showCurrentAllBook()//展示目前的图书数量
{
	for (int i = 0; i < m_allBookNum; i++)
	{
		cout << "书名:" << m_books[i].getName() <<" " << "剩余数量" << m_books[i].getNum() << endl;
	}
}

CManagementBooks::CManagementBooks()
{
	m_allBookNum = 0;
}

void CManagementBooks::addBook(CBook book)
{
	int flag = 0;
	for (int i = 0; i < m_allBookNum; i++)
	{
		if (m_books[i].getName() == book.getName())
		{
			flag = 1;
			m_books[i].setNum(m_books[i].getNum() + book.getNum());
			ofstream writeFile("library.txt", ios::out);
			for (int i = 0; i < m_allBookNum; i++)
			{
				writeFile << m_books[i];
			}
			writeFile.close();
			break;
		}
	}
	if (!flag)
	{
		ofstream writeFile("library.txt", ios::app);
		m_books.push_back(book);
		m_allBookNum++;
		writeFile << book;
		writeFile.close();
	}
}



int CManagementBooks::getAllBookNum()
{
	return m_allBookNum;
}

void CManagementBooks::showAllBooksInfo()
{
	for (int i = 0; i < m_allBookNum; i++)
	{
		m_books[i].showInfo();
	}
}

bool CManagementBooks::borrow(string name)
{

	for (int i =0; i <m_allBookNum; i++)
	{
		if (m_books[i].getName() == name)
		{
			if (m_books[i].getNum() >= 1)
			{
				m_books[i].setNum(m_books[i].getNum() - 1);
				cout << "借书成功" << endl;
				ofstream writeFile("library.txt");
				for (int i = 0; i < m_allBookNum; i++)
				{
					writeFile << m_books[i];
				}
				writeFile.close();
				return true;
			}
			else
			{
				cout << "此书数量不足" << endl;
				return false;
			}
		}

	}
	cout << "很抱歉，暂无此书" << endl;
	return false;
}

void CManagementBooks::Return(string id,string bookName)
{
	CBook book;
	book.setName(bookName);
	addBook(book);
	ofstream writeFile("borrowedBook.txt",ios::out);
	for (auto iter =m_outBookMap.begin(); iter != m_outBookMap.end(); ++iter)
	{
		if (iter->first == id && iter->second == bookName)
		{
			m_outBookMap.erase(iter);
			break;
		}
	}
	for (auto map : m_outBookMap)
	{
		writeFile << endl << map.first << " " << map.second;
	}
	writeFile.close();
}

void CManagementBooks::initOutBook()
{
	ifstream readFile("borrowedBook.txt");
	if (!readFile.is_open())
	{
		cout << "查看全体借书情况数据读取出错" << endl;
	}
	else
	{
		while (!readFile.eof())
		{
			string studentId, bookName;
			readFile >> studentId >> bookName;
			m_outBookMap.insert(pair<string, string>(studentId, bookName));
		}
	}
	readFile.close();

}

void CManagementBooks::checekOutBook()
{
	for (auto map : m_outBookMap)
	{
		cout << "借阅人学工号:" << map.first<<" " << "借阅书名:" << map.second << endl;
	}
}

void CManagementBooks::initBooks()
{
	ifstream readFile;
	readFile.open("library.txt");
	if (!readFile.is_open())
	{
		cout << "图书数据读取错误" << endl;
		readFile.close();
		return;
	}
	while (!readFile.eof())
	{
		
		CBook book;
		readFile >> book;
		m_allBookNum++;
		m_books.push_back(book);
	}
	readFile.close();
}

int CManagementBooks::checkBorrowedBook(string userId)
{
	
	int flag = 0;
	for (auto map : m_outBookMap)
	{
		if (userId == map.first)
		{
			if (!flag)
			{
				cout << "您已经借的全部图书如下：" << endl;
				flag++;
			}
			else
			{
				flag++;
			}
			cout << map.second << " ";
		}
	}
	if (!flag)
	{
		cout << "您目前没有借书" << endl;
	}
	cout << "共：" << flag << "本";
	cout << endl;
	return flag;
}

void CManagementBooks::viewBorrowerDetails(string id)
{
	ifstream readFile("teacher.txt");
	ifstream readFile1("student.txt");
	int flag = 0;
	if (!readFile1.is_open()|| !readFile.is_open())
	{
		cout << "用户数据读取错误" << endl;
	}
	while (!readFile1.eof())
	{
		string act1, name, department, gender;
		readFile1 >> act1 >> name >> gender >> department;
		if (id == act1)
		{
			cout<<"用户类别:"<<"学生"<<" " << "用户姓名:" << name << " " << "用户性别:" << gender << " " << "用户所在部门:" << department << endl;
			flag = 1;
		}
	
	}
	if (!flag)
	{
		while (!readFile.eof())
		{
			string act1, name, department, gender;
			readFile >> act1 >> name >> gender >> department;
			if (id == act1)
			{
				flag = 1;
				cout << "用户类别:"<<"老师"<<" " << "用户姓名:" << name << " " << "用户性别:" << gender << " " << "用户所在部门:" << department << endl;
			}

		}
	}
	if (!flag)
	{
		cout << "无此用户！" << endl;
	}
	readFile.close();
	readFile1.close();
}

bool CManagementBooks::checkTrueBorrow(string id, string bookName)
{
	
	for (auto map : m_outBookMap)
	{
		if (map.first == id && map.second == bookName)
		{
			return true;
		}
	}
	return false;
}

void CManagementBooks::setMapValue(string userId,string bookName)
{
	m_outBookMap.insert(pair<string, string>(userId, bookName));
}


void CManagementBooks::deleteBooke(string authorName, string bookName)
{
	int flag = 0;
	for (int i = 0; i < m_allBookNum; i++)
	{
		if (m_books[i].getName() == bookName && m_books[i].getAuthor() == authorName)
		{
			flag = 1;
			m_allBookNum--;
			m_books.erase(m_books.begin() + i);
			ofstream writeFile("library.txt", ios::out);
			for (int i = 0; i < m_allBookNum; i++)
			{
				writeFile << m_books[i];
			}
			writeFile.close();

			ofstream writeFile1("borrowedBook.txt", ios::out);
			for (auto iter = m_outBookMap.begin(); iter != m_outBookMap.end(); /*++iter*/)
			{
				if (iter->second == bookName)
				{

					m_outBookMap.erase(iter++);
				}
				else
				{
					iter++;
				}
			}
			for (auto map : m_outBookMap)
			{
				writeFile1 << endl << map.first << " " << map.second;
			}
			writeFile1.close();
			cout << "删除图书成功" << endl;
			break;
		}
	}
	if (!flag)
	{
		cout << "删除失败" << endl;
	}
}

void CManagementBooks::modifyBook(string authorName, string bookName)
{
	
	/*cout << "请输入您要修改的图书的书名及作者姓名，以空格隔开" << endl;*/
	string name;
	string pressInfo;
	double price;
	int page;
	string author;
	int num;
	int flag = 0;
	for (int i = 0; i < m_allBookNum; i++)
	{

		if (m_books[i].getName() == bookName && m_books[i].getAuthor() == authorName)
		{
			flag = 1;
			string cmd;
			
			while (1)
			{
				cout << "请输入您要修改的相应信息,输入对应序号即可:" << endl;
				cout << "1.修改书名" << endl;
				cout << "2.修改出版社" << endl;
				cout << "3.修改价格" << endl;
				cout << "4.修改页数" << endl;
				cout << "5.修改作者名" << endl;
				cout << "6.修改现有本数" << endl;
				cout << "若您确认修改，请输入:y" << endl;
				cin >> cmd;
				if (cmd == "1")
				{
					cout << "请输入您要修改为的书名:" << endl;
					cin >> name;
					m_books[i].setName(name);
				}
				else if (cmd == "2")
				{
					cout << "请输入您要修改为的出版社:" << endl;
					cin >> pressInfo;
					m_books[i].setPressInfo(pressInfo);
				}
				else if (cmd == "3")
				{
					cout << "请输入您要修改为的价格:" << endl;
					cin >> price;
					m_books[i].setPrice(price);
				}
				else if (cmd == "4:")
				{
					cout << "请输入您要修改为的页数" << endl;
					cin >> page;
					m_books[i].setPage(page);
				}
				else if (cmd == "5:")
				{
					cout << "请输入您要修改为的作者名" << endl;
					cin >> author;
					m_books[i].setAuthor(author);
				}
				else if (cmd == "6")
				{
					cout << "请输入您要修改为的现有本数:" << endl;
					cin >> num;
					m_books[i].setNum(num);
				}
				else if (cmd == "y")
				{
					ofstream writeFile("library.txt", ios::out);
					for (int i = 0; i < m_allBookNum; i++)
					{
						writeFile << m_books[i];
					}
					writeFile.close();
					cout << "修改成功" << endl;
					showAllBooksInfo();
					break;
				}
				else
				{
					cout << "请输入正确的命令!" << endl;
				}
			}
		}
	}
	if (!flag)
	{
		cout << "修改失败,没有此书" << endl;
	}
}
