#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>

using namespace std;

class Equipment
{
    string _id;
    string _name;

public:
    Equipment(string id, string name);

    string Id();

    string Name();

    stringstream Serialize(char separator);

    static Equipment Deserialize(string serializedData, char separator);
};

#endif // EQUIPMENT_H
