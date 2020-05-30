#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Reservation.h"

using namespace std;

class User
{
    string _id;
    string _firstName;
    string _lastName;
    string _email;
    string _password;
    bool _activated;
    string _type;
    vector<Reservation> _reservations;

public:
    User(string id, string firstName, string lastname, string email, string password, string activated = "0");

    string Id();

    string FirstName();

    string LastName();

    string Email();

    string Password();

    bool Activated();

    string Type();

    bool ChangePassword(string oldPassword, string newPassword);

    void AssignReservationToUser(Reservation reservation);

    string Serialize(char separator);

    static User Deserialize(string serializedData, char separator);
};

#endif // USER_H
