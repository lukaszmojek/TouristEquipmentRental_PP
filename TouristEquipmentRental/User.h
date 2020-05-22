#ifndef USER_H
#define USER_H

#include <iostream>
#include "Reservation.h"

using namespace std;

class User
{
    string _id;
    string _firstName;
    string _lastName;
    string _email;
    string _password;
    list<Reservation> _reservations;

public:
    User(string id, string firstName, string lastname, string email, string password);

    string Id();

    string FirstName();

    string LastName();

    string Email();

    string Password();

    bool ChangePassword(string oldPassword, string newPassword);

    void AssignReservationToUser(Reservation reservation);

    stringstream Serialize(char separator);

    static User Deserialize(string serializedData, char separator);
};

#endif // USER_H
