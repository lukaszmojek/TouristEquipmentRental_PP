#include "user.h"

User::User(int id, string firstName, string lastname, string email, string password)
{
    _id = id;
    _firstName = firstName;
    _lastName = lastname;
    _email = email;
    //TODO: add hashing
    _password = password;
}

int User::Id()
{
    return _id;
}

string User::FirstName()
{
    return _firstName;
}

string User::LastName()
{
    return _lastName;
}

string User:: Email()
{
    return _email;
}

string User::ChangePassword(string oldPassword, string newPassword)
{
    //TODO: add hashing
    if (oldPassword == _password)
    {
        //TODO: log password change
        _password = newPassword;
    }
}
