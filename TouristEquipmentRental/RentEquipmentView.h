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
	int EquipmentNumber;
	bool isEquipmentOnList;
	GlobalOperator style;

public:

	void RenderEquipmentList();

	vector<Equipment> GetPickedEquipment();

	void CreateReservation(User user);
};

#endif //RentEquipmentView_H