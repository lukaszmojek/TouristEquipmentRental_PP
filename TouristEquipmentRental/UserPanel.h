#ifndef UserPanel_H
#define UserPanel_H

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

#include "GlobalOperator.h"
#include "PrimaryView.h"
#include "DatabaseOperator.h"
#include "RentEquipmentView.h"

using namespace std;

class UserPanel {
private:
	GlobalOperator style;
	PrimaryView start;

public:

	void RenderUserMenu(User user);

	void ShowUserData(User user );

	void ShowUserReservations(User user);

	void RenderNavigationBar(User user, int width);

	void RentEquipmentFlow(User user);
};

#endif // UserPanel_H
