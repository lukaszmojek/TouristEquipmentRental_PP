#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

#include "ReservationEquipment.h"
#include "StringOperations.h"

ReservationEquipment::ReservationEquipment(string id, string reservationId, string equimpentId)
{
    _id = id;
    _reservationId = reservationId;
    _equipmentId = equimpentId;
}

stringstream ReservationEquipment::Serialize(char separator)
{
    stringstream reservationEquipment;

    reservationEquipment << _id << separator
         << _reservationId << separator
         << _equipmentId;

    return reservationEquipment;
}

ReservationEquipment ReservationEquipment::Deserialize(string serializedData, char separator)
{
    auto reservationEquipmentDetails = StringOperations::Split(serializedData, separator);

    auto reservationEquipment = * new ReservationEquipment(
            reservationEquipmentDetails[0],
            reservationEquipmentDetails[1],
            reservationEquipmentDetails[2]);

    return reservationEquipment;
}

string ReservationEquipment::Id()
{
	return _id;
}

string ReservationEquipment::ReservationId()
{
    return _reservationId;
}

string ReservationEquipment::EquipmentId()
{
    return _equipmentId;
}
