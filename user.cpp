#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include "user.h"
#include "helpers.h"

User::User(string id, string firstName, string lastname, string email, string password)
{
    _id = id;
    _firstName = firstName;
    _lastName = lastname;
    _email = email;
    //TODO: add hashing
    _password = password;
}

string User::Id()
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

bool User::ChangePassword(string oldPassword, string newPassword)
{
    //TODO: add hashing
    if (oldPassword == _password)
    {
        //TODO: log password change
        _password = newPassword;
        return true;
    }

    return false;
}

stringstream User::Serialize(char separator)
{
    stringstream user;

    user << _id << separator
         << _firstName << separator
         << _lastName << separator
         << _email << separator
         << _password;

    return user;
}

vector<string> split(const string& s, char delimiter)
{
   vector<std::string> tokens;
   string token;
   istringstream tokenStream(s);

   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }

   return tokens;
}

User User::Deserialize(string serializedUser, char separator)
{
    auto userDetails = split(serializedUser, separator);

    auto user = * new User(userDetails[0], userDetails[1], userDetails[2], userDetails[3], userDetails[4]);

    return user;
}


