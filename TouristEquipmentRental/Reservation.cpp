#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

#include "Reservation.h"
#include "Equipment.h"
#include "StringOperations.h"

Reservation::Reservation(string id, string userId, string startDate, string endDate)
{
    _id = id;
    _userId = userId;
    _startDate = startDate;
    _endDate = endDate;
}

stringstream Reservation::Serialize(char separator)
{
    stringstream reservation;

    reservation << _id << separator
         << _userId << separator
         << _startDate << separator
         << _endDate;

    return reservation;
}

Reservation Reservation::Deserialize(string serializedData, char separator)
{
    auto reservationDetails = StringOperations::Split(serializedData, separator);

    auto reservation = * new Reservation(
            reservationDetails[0],
            reservationDetails[1],
            reservationDetails[2],
            reservationDetails[3]);

    return reservation;
}

string Reservation::Id()
{
    return _id;
}

string Reservation::UserId()
{
    return _userId;
}

string Reservation::StartDate()
{
    return _startDate;
}

string Reservation::EndDate()
{
    return _endDate;
}

void Reservation::AssignEquipmentToReservation(list<Equipment> equipment)
{
    for (auto eq : equipment)
    {
        _equipment.push_back(eq);
    }
}
