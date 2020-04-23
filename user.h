#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    string _id;
    string _firstName;
    string _lastName;
    string _email;
    string _password;

public:
    User(string id, string firstName, string lastname, string email, string password);

    string Id();

    string FirstName();

    string LastName();

    string Email();

    bool ChangePassword(string oldPassword, string newPassword);

    stringstream Serialize(char separator);

    static User Deserialize(string serializedUser, char separator);
};

#endif // USER_H
