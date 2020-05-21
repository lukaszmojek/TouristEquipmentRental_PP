#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <list>

#include "Equipment.h"

using namespace std;

class Reservation
{
    string _id;
    string _userId;
    string _startDate;
    string _endDate;
    list<Equipment> _equipment;

public:
    Reservation(string id, string userId, string startDate, string endDate);

    stringstream Serialize(char separator);

    static Reservation Deserialize(string serializedData, char separator);

    string Id();

    string UserId();

    string StartDate();

    string EndDate();
};

#endif // RESERVATION_H
