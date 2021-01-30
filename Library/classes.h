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

#endif // CLASSES_H

