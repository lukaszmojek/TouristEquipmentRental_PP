#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int _id;
    string _firstName;
    string _lastName;
    string _email;
    string _password;

public:
    User(int id, string firstName, string lastname, string email, string password);

    int Id();

    string FirstName();

    string LastName();

    string Email();

    string ChangePassword(string oldPassword, string newPassword);
};

#endif // USER_H
