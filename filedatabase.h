#ifndef FILEDATABASE_H
#define FILEDATABASE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class FileDatabase
{
private:
    string usersFileName;
    string equipmentFileName;
    string borrowingsFileName;
    char separator;

public:
    FileDatabase(string users = "users.txt", string equipment = "users.txt", string borrowing = "users.txt", char separator = ';');

    string GetAllUsers();
};

#endif // FILEDATABASE_H
