#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include "Equipment.h"

Equipment::Equipment(string id, string name)
{
    _id = id;
    _name = name;
}

string Equipment::Id()
{
    return _id;
}

string Equipment::Name()
{
    return _name;
}

stringstream Equipment::Serialize(char separator)
{
    stringstream reservationEquipment;

    reservationEquipment << _id << separator
         << _name;

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

Equipment Equipment::Deserialize(string serializedData, char separator)
{
    auto equipmentDetails = split(serializedData, separator);

    auto equipment = * new Equipment(
            equipmentDetails[0],
            equipmentDetails[1]);

    return equipment;
}
