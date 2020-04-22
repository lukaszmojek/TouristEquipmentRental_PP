#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <list>
#include "equipment.h"

using namespace std;

class Reservation
{
    string _id;
    string _startDate;
    string _endDate;
    list<Equipment> _equipment;

public:
    Reservation();
};

#endif // RESERVATION_H
