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

    string Serialize(char separator);

    static ReservationEquipment Deserialize(string serializedData, char separator);

    string Id();

    string ReservationId();

    string EquipmentId();
};

#endif // RESERVATIONEQUIPMENT_H
