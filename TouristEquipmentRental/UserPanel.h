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

	char RenderUserMenu();

	void ShowUserData(User user );

	void ShowUserReservations(User user);

	char RenderNavigationBar(int width);

	void RentEquipmentFlow( User user, DatabaseOperator databaseOperator, vector<Reservation> reservations, vector<Equipment> equipment );
};


#endif // UserPanel_H
