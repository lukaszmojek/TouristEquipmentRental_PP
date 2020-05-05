#ifndef RESERVATIONEQUIPMENT_H
#define RESERVATIONEQUIPMENT_H

#include <iostream>

using namespace std;

class ReservationEquipment
{
    string _id;
    string _reservationId;
    string _equipmentId;

public:
    ReservationEquipment(string id, string reservationId, string equimpentId);

    stringstream Serialize(char separator);

    static ReservationEquipment Deserialize(string serializedData, char separator);
};

#endif // RESERVATIONEQUIPMENT_H
