#ifndef PrimmaryView_H
#define PrimmaryView_H
#include <iostream>
#include "GlobalOperator.h"
#include "SignInUpView.h"

using namespace std;

class PrimaryView
{
private:
	GlobalOperator style;
	
	void MenuSelect(char, SignInUpView signInOnView);

public:
	void RenderStartView(SignInUpView signInOnView);
};

#endif //PrimmaryView_H


