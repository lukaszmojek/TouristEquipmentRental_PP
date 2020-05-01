#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include "Reservation.h"
#include "Equipment.h"

Reservation::Reservation(string id, string userId, string startDate, string endDate)
{
    _id = id;
    _userId = userId;
    _startDate = startDate;
    _endDate = endDate;
}

stringstream Reservation::Serialize(char separator)
{
    stringstream reservation;

    reservation << _id << separator
         << _userId << separator
         << _startDate << separator
         << _endDate;

    return reservation;
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

Reservation Reservation::Deserialize(string serializedData, char separator)
{
    auto reservationDetails = split(serializedData, separator);

    auto reservation = * new Reservation(
            reservationDetails[0],
            reservationDetails[1],
            reservationDetails[2],
            reservationDetails[3]);

    return reservation;
}
