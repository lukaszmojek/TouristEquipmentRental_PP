#include <list>
#include "filedatabase.h"
#include "user.h"

using namespace std;


FileDatabase::FileDatabase(string users, string equipment, string rental, char separator)
{
    _usersFileName = users;
    _equipmentFileName = equipment;
    _rentalFileName = rental;
    _separator = separator;
}

list<User> FileDatabase::GetAllUsers()
{
    auto users = *new list<User>();
    auto user = *new User("1", "Basic", "User", "basicuser@o2.pl", "zaq123");
    users.push_back(user);

    return users;
}
