#ifndef FILEDATABASE_H
#define FILEDATABASE_H

#include <iostream>
#include <stdlib.h>
#include <list>
#include "user.h"

using namespace std;

class FileDatabase
{
private:
    string _usersFileName;
    string _equipmentFileName;
    string _rentalFileName;
    char _separator;

public:
    FileDatabase(string users = "users.txt", string equipment = "equipment.txt", string rental = "rental.txt", char separator = ';');

    list<User> GetAllUsers();
};

#endif // FILEDATABASE_H
