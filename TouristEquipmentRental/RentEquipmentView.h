#ifndef RentEquipmentView_H
#define RentEquipmentView_H

#include <string>
#include <vector>
#include <iomanip>

#include "GlobalOperator.h"
#include "FileDatabase.h"

using namespace std;

class RentEquipmentView	{
private:

	string EquipmentNumbersInput;
	bool isEquipmentOnList;
	GlobalOperator style;

	bool DateIsValid(string date);

public:

	void RenderEquipmentList(vector <Equipment> equipment);

	vector<Equipment> GetPickedEquipment(vector <Equipment> equipment);

	Reservation CreateReservation(User user, vector<Reservation> reservations, vector <Equipment> equipment);
};

#endif //RentEquipmentView_H