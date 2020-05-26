#ifndef UserPanel_H
#define UserPanel_H
#include <iostream>
#include "User.h";
#include "PrimmaryView.h"
#include "GlobalOperator.h"


using namespace std;

class UserPanel {
private:
	GlobalOperator style;
	PrimmaryView start;
public:

	void RenderUserMenu(User);

	void ShowUserData(User);


};

#endif // UserPanel_H
