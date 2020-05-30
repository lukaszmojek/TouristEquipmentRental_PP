#ifndef FILEDATABASE_H
#define FILEDATABASE_H

#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
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

    vector<User> _users;
    vector<Equipment> _equimpent;
    vector<Reservation> _reservations;
    vector<ReservationEquipment> _reservationsEquipment;

    void Initialize();

    template <class DATA_TYPE>
    vector<DATA_TYPE> ReadData(string fileName);
    
    template <class DATA_TYPE>
    void SaveData(string fileName, vector<DATA_TYPE> data);

public:
    FileDatabase(
            string usersFileName = "users.txt",
            string equipmentFileName = "equipment.txt",
            string reservationsFileName = "reservations.txt",
            string reservationEquipmentFileName = "reservation_equimpent.txt",
            char separator = ';');

    vector<User> GetUsers();

    void AddUser(User newUser);

    vector<Equipment> GetEquimpent();

    vector<Reservation> GetReservations();

    vector<ReservationEquipment> GetReservationEquimpent();

    void SaveChanges();
};

#endif // FILEDATABASE_H
