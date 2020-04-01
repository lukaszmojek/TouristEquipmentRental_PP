#include "filedatabase.h"

using namespace std;

FileDatabase::FileDatabase(string users, string equipment, string borrowing, char separator)
{
    this->usersFileName = users;
    this->equipmentFileName = equipment;
    this->borrowingsFileName = borrowing;
    this->separator = separator;
}

string FileDatabase::GetAllUsers()
{
    return "mockUzytkownika";
}
