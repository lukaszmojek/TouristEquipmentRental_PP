#ifndef PrimmaryView_H
#define PrimmaryView_H
#include <iostream>

using namespace std;

class PrimmaryView
{
	string	_TypedID,
			_TypedPassword,
			_TypedFirstName,
			_TypedLastName,
			_TypedEmail;

public:
	string GetID();
	string GetPassword();
	string GetFirstName();
	string GetLastName();
	string GetEmail();

	void RenderStartView();

	int Select();

	void LoginView();

	void RegisterView();
};

#endif //PrimmaryView_H


