#ifndef FILEDATABASE_H
#define FILEDATABASE_H

#include <iostream>
#include <stdlib.h>
#include <list>
#include "User.h"
#include "Equipment.h"
#include "Reservation.h"
#include "ReservationEquipment.h"
#include "FileOperations.h"

using namespace std;

class FileDatabase
{
private:
    string _usersFileName;
    string _equipmentFileName;
    string _reservationsFileName;
    string _reservationEquipmentFileName;
    char _separator;

    FileOperations _fileOperations;

    list<User> _users;
    list<Equipment> _equimpent;
    list<Reservation> _reservations;
    list<ReservationEquipment> _reservationsEquipment;

    void Initialize();

    template <class DATA_TYPE>
    list<DATA_TYPE> ReadData(string fileName);

public:
    FileDatabase(
            string usersFileName = "users.txt",
            string equipmentFileName = "equipment.txt",
            string reservationsFileName = "reservations.txt",
            string reservationEquipmentFileName = "reservation_equimpent.txt",
            char separator = ';');

    list<User> GetUsers();

    list<Equipment> GetEquimpent();

    list<Reservation> GetReservations();

    list<ReservationEquipment> GetReservationEquimpent();
};

#endif // FILEDATABASE_H
