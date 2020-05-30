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

public:
	char RenderStartView();
};

#endif //PrimmaryView_H


