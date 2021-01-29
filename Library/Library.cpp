#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#define A 100
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

int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, k = 0;
	Info I[A], J[A];
	string userName, password, userName1, password1, newusername, newpassword, sa, sb, sc, sd;
	fstream Admin("Admins.txt", ios::in | ios::out | ios::app);
	fstream User("Users.txt", ios::in | ios::out | ios::app);
	ifstream ab("AdminNumber.txt", ios::in);
	ab >> f;
	ab.close();
	ifstream cd("UserNumber.txt", ios::in);
	cd >> h;
	cd.close();
	cout << "Welcome to library management application!" << endl;
	cout << "Please enter username and password for login:" << endl;
	cout << "Username: ";
	cin >> userName;
	cout << "Password: ";
	cin >> password;
	for (int i = 0; i < f; i++) {
		Admin >> sa;
		I[i].setUsername(sa);
		Admin >> sb;
		I[i].setPassword(sb);
		if (userName == I[i].getUsername() && password == I[i].getPassword()) {
			g = 1;
			break;
		}
		else {
			g = 0;
		}
	}
	for (int i = 0; i < h; i++) {
		User >> sc;
		J[i].setUsername(sc);
		User >> sd;
		J[i].setPassword(sd);
		if (userName == J[i].getUsername() && password == J[i].getPassword()) {
			k = 1;
			break;
		}
		else {
			k = 0;
		}
	}
	if (g == 1) {
		cout << "You entered successfully as an Adminstrator!" << endl;
		cout << "Select 1 to add new admin or user" << endl;
		cout << "Select 2 to delete a admin or user" << endl;
		cout << "Select 3 to update admin or user information" << endl;
		cout << "Select 4 to add new book information" << endl;
		cout << "Select 5 to update a book information" << endl;
		cout << "Select 6 to delete a book information" << endl;
		cin >> a;
		if (a == 1) {
			cout << "You want to add new admin or user information" << endl;
			cout << "Select 1 to add new admin" << endl;
			cout << "Select 2 to add new user" << endl;
			cin >> b;
			if (b == 1) {
				ifstream Na("AdminNumber.txt", ios::in);
				Na >> c;
				c++;
				remove("AdminNumber.txt");
				ofstream Ma("AdminNumber.txt", ios::out);
				Ma << c;
				Ma.close();
				//#include "InsertAdmin.txt"
				cout << "Enter username:";
				cin >> userName1;
				cout << "Enter password:";
				cin >> password1;
				fstream Admin("Admins.txt", ios::out | ios::in | ios::app);
				Admin << userName1 << endl;
				Admin << password1 << endl;
				cout << "Information submitted successfully!";
				Admin.close();
			}
			else if (b == 2) {
				ifstream Nu("UserNumber.txt", ios::in);
				Nu >> d;
				d++;
				remove("UserNumber.txt");
				ofstream Mu("UserNumber.txt", ios::out);
				Mu << d;
				Mu.close();
				//#include "InsertUser.txt"
				cout << "Enter username:";
				cin >> userName1;
				cout << "Enter password:";
				cin >> password1;
				fstream User("Users.txt", ios::out | ios::in | ios::app);
				User << userName1 << endl;
				User << password1 << endl;
				cout << "Information submitted successfully!";
				User.close();
			}
		}
	}
	else if (k == 1 && g == 0) {
		cout << "You entered successfully as a user!" << endl;
		cout << "Select 1 to add new book information" << endl;
		cout << "Select 2 to update a book information" << endl;
		cout << "Select 3 to delete a book information" << endl;
	}
	else {
		cout << "Username or password is incorrect!, Please try again ...";
	}
}