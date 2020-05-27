#ifndef SignInUpView_H
#define SignInUpView_H
#include <iostream>
#include "GlobalOperator.h"

using namespace std;

class SignInUpView
{
private:
	string	_TypedID,
			_TypedPassword,
			_TypedFirstName,
			_TypedLastName,
			_TypedEmail;

	GlobalOperator style;


public:
	string GetId();

	string GetPassword();

	string GetFirstName();

	string GetLastName();

	string GetEmail();

	void RenderLoginView();

	void RenderRegisterView();

};

#endif //SignInUpView_H

