#ifndef LoginPanel_H
#define LoginPanel_H
#include <iostream>

using namespace std;

class LoginPanel 
{
	bool isRegister;

public:

	LoginPanel();

	void ShowPanel();
	

	string Login();
};

#endif //LoginPanel_H