#include "ReservationEquipment.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

ReservationEquipment::ReservationEquipment(string id, string reservationId, string equimpentId)
{
    _id = id;
    _reservationId = reservationId;
    _equipmentId = equimpentId;
}

stringstream ReservationEquipment::Serialize(char separator)
{
    stringstream reservationEquipment;

    reservationEquipment << _id << separator
         << _reservationId << separator
         << _equipmentId;

    return reservationEquipment;
}

vector<string> split(const string& s, char separator)
{
   vector<std::string> tokens;
   string token;
   istringstream tokenStream(s);

   while (getline(tokenStream, token, separator))
   {
      tokens.push_back(token);
   }

   return tokens;
}

ReservationEquipment ReservationEquipment::Deserialize(string serializedData, char separator)
{
    auto reservationEquipmentDetails = split(serializedData, separator);

    auto reservationEquipment = * new ReservationEquipment(
            reservationEquipmentDetails[0],
            reservationEquipmentDetails[1],
            reservationEquipmentDetails[2]);

    return reservationEquipment;
}
