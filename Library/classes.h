#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
using namespace std;

class Info {
public:
	string getUsername();
	string getPassword();
	void setUsername(string username);
	void setPassword(string password);
private:
	string username;
	string password;
};
class Book {
public:
	string getBookName();
	string getYear();
	string getPageNum();
	void setBookName(string bookName);
	void setYear(string year);
	void setPageNum(string pageNum);
private:
	string bookName;
	string year;
	string pageNum;
};

string Info::getUsername()
{
	return username;
}
string Info::getPassword()
{
	return password;
}
void Info::setUsername(string username)
{
	this->username = username;
}
void Info::setPassword(string password)
{
	this->password = password;
}
string Book::getBookName()
{
	return bookName;
}
string Book::getYear()
{
	return year;
}
string Book::getPageNum()
{
	return pageNum;
}
void Book::setBookName(string bookName)
{
	this->bookName = bookName;
}
void Book::setYear(string year)
{
	this->year = year;
}
void Book::setPageNum(string pageNum)
{
	this->pageNum = pageNum;
}

#endif // CLASSES_H

