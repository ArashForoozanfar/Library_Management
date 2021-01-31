#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "classes.h"
#define A 100
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, k = 0, l = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0;
	Info I[A], J[A], D[A], U[A];
	string userName, password, userName1, password1, userName2, password2, userName3, password3, newusername, newpassword, sa, sb, sc, sd, se, sf, sg, sh, si, sj;
	fstream Admin("Admins.txt", ios::in | ios::out | ios::app);
	if (!Admin)
		cout << "Couldnot open file Admins.txt" << endl;
	fstream User("Users.txt", ios::in | ios::out | ios::app);
	if (!User)
		cout << "Couldnot open file Users.txt" << endl;
	ifstream ab("AdminNumber.txt", ios::in);
	if (!ab)
		cout << "Couldnot open file AdminNumber.txt" << endl;
	ab >> f;
	ab.close();
	/*fstream ADname("Admins.txt", ios::in | ios::out | ios::app);
	fstream USname("Users.txt", ios::in | ios::out | ios::app);
	fstream ADnum("AdminNumber.txt", ios::in | ios::out | ios::app);
	fstream USnum("Usernumber.txt", ios::in | ios::out | ios::app);
	ADname.close();
	ADnum.close();
	USname.close();
	USnum.close();*/
	ifstream cd("UserNumber.txt", ios::in);
	if (!cd)
		cout << "Couldnot open file UserNumber.txt" << endl;
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
		g = 0;
	}
	Admin.close();
	for (int i = 0; i < h; i++) {
		User >> sc;
		J[i].setUsername(sc);
		User >> sd;
		J[i].setPassword(sd);
		if (userName == J[i].getUsername() && password == J[i].getPassword()) {
			k = 1;
			break;
		}
		k = 0;
	}
	User.close();
	if (g == 1) {
		cout << "You entered successfully as an Adminstrator!" << endl;
		cout << "Select 1 to add new admin or user" << endl;
		cout << "Select 2 to delete a admin or user" << endl;
		cout << "Select 3 to update admin or user information" << endl;
		cout << "Select 4 to add new book information" << endl;
		cout << "Select 5 to update a book information" << endl;
		cout << "Select 6 to delete a book information" << endl;
		cout << "Select 7 to search and show books informations" << endl;
		cin >> a;
		if (a == 1) {
			cout << "You want to add new admin or user information" << endl;
			cout << "Select 1 to add new admin" << endl;
			cout << "Select 2 to add new user" << endl;
			cin >> b;
			if (b == 1) {
				ifstream Na("AdminNumber.txt", ios::in);
				if (!Na)
					cout << "Couldnot open file AdminNumber.txt" << endl;
				Na >> c;
				c++;
				remove("AdminNumber.txt");
				ofstream Ma("AdminNumber.txt", ios::out);
				if (!Ma)
					cout << "Couldnot open file AdminNumber.txt" << endl;
				Ma << c;
				Ma.close();
				//#include "InsertAdmin.txt"
				fstream IA("Admins.txt", ios::out | ios::app);
				cout << "Enter username:";
				cin >> userName1;
				cout << "Enter password:";
				cin >> password1;
				IA << userName1 << endl;
				IA << password1 << endl;
				cout << "Information submitted successfully!";
				IA.close();
			}
			else if (b == 2) {
				ifstream Nu("UserNumber.txt", ios::in);
				if (!Nu)
					cout << "Couldnot open file UserNumber.txt" << endl;
				Nu >> d;
				d++;
				remove("UserNumber.txt");
				ofstream Mu("UserNumber.txt", ios::out);
				if (!Mu)
					cout << "Couldnot open file UserNumber.txt" << endl;
				Mu << d;
				Mu.close();
				//#include "InsertUser.txt"
				fstream UI("Users.txt", ios::out | ios::app);
				cout << "Enter username:";
				cin >> userName1;
				cout << "Enter password:";
				cin >> password1;
				UI << userName1 << endl;
				UI << password1 << endl;
				cout << "Information submitted successfully!";
				UI.close();
			}
		}
		else if (a == 2) {
			cout << "You want to delete an admin or user information!" << endl;
			cout << "Select 1 to delete an admin" << endl;
			cout << "Select 2 to delete a user" << endl;
			cin >> n;
			if (n == 1) {
				fstream Admin("Admins.txt", ios::in | ios::out | ios::app);
				cout << "Please enter the username of admin you want to delete: ";
				cin >> userName2;
				cout << "Please enter the password of admin you want to delete: ";
				cin >> password2;
				Admin.seekg(0, ios::beg);
				for (int i = 0; i < f; i++) {
					Admin >> se;
					D[i].setUsername(se);
					//cout << "D[" << i << "].getUsername()= " << D[i].getUsername() << endl;
					Admin >> sf;
					D[i].setPassword(sf);
					//cout << "D[" << i << "].getpassword()= " << D[i].getPassword() << endl;
					if (D[i].getUsername() == userName2 && D[i].getPassword() == password2) {
						l = i;
						//cout << "L: " << l << endl;
						o = 1;
					}
				}
				if (o == 0) {
					cout << "The admin you want to delete, was not found!" << endl;
				}
				else {
					Admin.close();
					remove("Admins.txt");
					fstream Admind("Admins.txt", ios::in | ios::out | ios::app);
					if (!Admind)
						cout << "Couldnot open file Admins.txt" << endl;
					int m = 0;
					while (m < f) {
						if (m != l) {
							sg = D[m].getUsername();
							//cout << "Dm[" << m << "].getUsername()=" << sg << endl;
							Admind << sg << endl;
							sh = D[m].getPassword();
							//cout << "Dm[" << m << "].getpassword()=" << sh << endl;
							Admind << sh << endl;
						}
						m++;
					}
					Admind.close();
					cout << "Information deleted successfully!" << endl;
					ifstream ab("AdminNumber.txt", ios::in);
					if (!ab)
						cout << "Couldnot open file AdminNumber.txt" << endl;
					ab >> f;
					f--;
					ab.close();
					remove("AdminNumber.txt");
					ofstream AB("AdminNumber.txt", ios::out);
					if (!AB)
						cout << "Couldnot open file AdminNumber.txt" << endl;
					AB << f;
					AB.close();
				}
			}
			else if (n == 2) {
				fstream User("Users.txt", ios::in | ios::out | ios::app);
				cout << "Please enter the username of user you want to delete: ";
				cin >> userName2;
				cout << "Please enter the password of user you want to delete: ";
				cin >> password2;
				User.seekg(0, ios::beg);
				for (int i = 0; i < h; i++) {
					User >> se;
					D[i].setUsername(se);
					//cout << "D[" << i << "].getUsername()= " << D[i].getUsername() << endl;
					User >> sf;
					D[i].setPassword(sf);
					//cout << "D[" << i << "].getpassword()= " << D[i].getPassword() << endl;
					if (D[i].getUsername() == userName2) {
						l = i;
						//cout << "L: " << l << endl;
						o = 1;
					}
				}
				if (o == 0) {
					cout << "The user you want to delete, was not found!" << endl;
				}
				else {
					User.close();
					remove("Users.txt");
					fstream Userd("Users.txt", ios::in | ios::out | ios::app);
					if (!Userd)
						cout << "Couldnot open file Users.txt" << endl;
					int m = 0;
					while (m < h) {
						if (m != l) {
							sg = D[m].getUsername();
							//cout << "Dm[" << m << "].getUsername()=" << sg << endl;
							Userd << sg << endl;
							sh = D[m].getPassword();
							//cout << "Dm[" << m << "].getpassword()=" << sh << endl;
							Userd << sh << endl;
						}
						m++;
					}
					Userd.close();
					cout << "Information deleted successfully!" << endl;
					ifstream ab("UserNumber.txt", ios::in);
					if (!ab)
						cout << "Couldnot open file UserNumber.txt" << endl;
					ab >> f;
					f--;
					ab.close();
					remove("UserNumber.txt");
					ofstream AB("UserNumber.txt", ios::out);
					if (!AB)
						cout << "Couldnot open file UserNumber.txt" << endl;
					AB << f;
					AB.close();
				}
			}
		}
		else if (a == 3) {
			cout << "You want to update an admin or user information!" << endl;
			cout << "Select 1 to update an admin" << endl;
			cout << "Select 2 to update a user" << endl;
			cin >> p;
			if (p == 1) {
				fstream Admin("Admins.txt", ios::in | ios::out | ios::app);
				cout << "You want to update an admin information!" << endl;
				cout << "Please enter the username of admin you want to update: ";
				cin >> userName3;
				cout << "Please enter the password of admin you want to update: ";
				cin >> password3;
				Admin.seekg(0, ios::beg);
				for (int i = 0; i < f; i++) {
					Admin >> si;
					U[i].setUsername(si);
					Admin >> sj;
					U[i].setPassword(sj);
					if (U[i].getUsername() == userName3 && U[i].getPassword() == password3) {
						q = i;
						r = 1;
					} 
				}
				Admin.close();
				remove("Admins.txt");
				if (r == 0) {
					cout << "The admin you want to update was not found!" << endl;
				}
				else {
					cout << "Select 1 to update username:( " << userName3 << " )" << endl;
					cout << "Select 2 to update password:( " << password3 << " )" << endl;
					cin >> s;
					if (s == 1) {
						cout << "You want to update username!" << endl;
						cout << "Please enter new username: ";
						cin >> newusername;
						fstream AU("Admins.txt", ios::out | ios::app);
						if (!AU)
							cout << "Couldnot open file Admins.txt";
						int t = 0;
						while (t < f) {
							if (t != q) {
								si = U[t].getUsername();
								AU << si << endl;
								sj = U[t].getPassword();
								AU << sj << endl;
							}
							else if (t == q) {
								AU << newusername << endl;
								sj = U[t].getPassword();
								AU << sj << endl;
							}
							t++;
						}
						cout << "Information updated successfully!" << endl;
					}
					else if (s == 2) {
						cout << "You want to update password!" << endl;
						cout << "Please enter new password: ";
						cin >> newpassword;
						fstream AU("Admins.txt", ios::out | ios::app);
						if (!AU)
							cout << "Couldnot open file Admins.txt";
						int t = 0;
						while (t < f) {
							if (t != q) {
								si = U[t].getUsername();
								AU << si << endl;
								sj = U[t].getPassword();
								AU << sj << endl;
							}
							else if (t == q) {
								si = U[t].getUsername();
								AU << si << endl;
								AU << newpassword << endl;
							}
							t++;
						}
						cout << "Information updated successfully!" << endl;
					}
				}
			}
			else if (p == 2) {
				fstream User("Users.txt", ios::in | ios::out | ios::app);
				cout << "You want to update a user information!" << endl;
				cout << "Please enter the username of user you want to update: ";
				cin >> userName3;
				cout << "Please enter the password of user you want to update: ";
				cin >> password3;
				User.seekg(0, ios::beg);
				for (int i = 0; i < h; i++) {
					User >> si;
					U[i].setUsername(si);
					User >> sj;
					U[i].setPassword(sj);
					if (U[i].getUsername() == userName3 && U[i].getPassword() == password3) {
						q = i;
						r = 1;
					}
				}
				User.close();
				remove("Users.txt");
				if (r == 0) {
					cout << "The user you want to update was not found!" << endl;
				}
				else {
					cout << "Select 1 to update username:( " << userName3 << " )" << endl;
					cout << "Select 2 to update password:( " << password3 << " )" << endl;
					cin >> s;
					if (s == 1) {
						cout << "You want to update username!" << endl;
						cout << "Please enter new username: ";
						cin >> newusername;
						fstream UU("Users.txt", ios::out | ios::app);
						if (!UU)
							cout << "Couldnot open file Users.txt";
						int t = 0;
						while (t < h) {
							if (t != q) {
								si = U[t].getUsername();
								UU << si << endl;
								sj = U[t].getPassword();
								UU << sj << endl;
							}
							else if (t == q) {
								UU << newusername << endl;
								sj = U[t].getPassword();
								UU << sj << endl;
							}
							t++;
						}
						cout << "Information updated successfully!" << endl;
					}
					else if (s == 2) {
						cout << "You want to update password!" << endl;
						cout << "Please enter new password :";
						cin >> newpassword;
						fstream UU("Users.txt", ios::out | ios::app);
						if (!UU)
							cout << "Couldnot open file Users.txt";
						int t = 0;
						while (t < h) {
							if (t != q) {
								si = U[t].getUsername();
								UU << si << endl;
								sj = U[t].getPassword();
								UU << sj << endl;
							}
							else if (t == q) {
								si = U[t].getUsername();
								UU << si << endl;
								UU << newpassword << endl;
							}
							t++;
						}
						cout << "Information updated successfully!" << endl;
					}
				}
			}
		}
	}
	else if (k == 1 && g == 0) {
		cout << "You entered successfully as a user!" << endl;
		cout << "Select 1 to search and show book information" << endl;
	}
	else {
		cout << "Username or password is incorrect!, Please try again...";
	}
}