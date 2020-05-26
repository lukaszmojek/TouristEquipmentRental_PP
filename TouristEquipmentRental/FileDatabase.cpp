#include <list>
#include "FileDatabase.h"
#include "User.h"

using namespace std;


FileDatabase::FileDatabase(
        string usersFileName,
        string equipmentFileName,
        string reservationsFileName,
        string reservationEquipmentFileName,
        char separator)
{
    _usersFileName = usersFileName;
    _equipmentFileName = equipmentFileName;
    _reservationsFileName = reservationsFileName;
    _reservationEquipmentFileName = reservationEquipmentFileName;
    _separator = separator;
    _fileOperations = * new FileOperations();
    Initialize();
}

list<User> FileDatabase::GetUsers()
{
    return _users;
}

list<Reservation> FileDatabase::GetReservations()
{
    return _reservations;
}

list<ReservationEquipment> FileDatabase::GetReservationEquimpent()
{
    return _reservationsEquipment;
}

list<Equipment> FileDatabase::GetEquimpent()
{
    return _equimpent;
}

void FileDatabase::Initialize()
{
    _users = ReadData<User>(_usersFileName);
    _equimpent = ReadData<Equipment>(_equipmentFileName);
    _reservations = ReadData<Reservation>(_reservationsFileName);
    _reservationsEquipment = ReadData<ReservationEquipment>(_reservationEquipmentFileName);
}

template <class DATA_TYPE>
list<DATA_TYPE> FileDatabase::ReadData(string fileName)
{
    auto file = _fileOperations.openFile(fileName, ios::in);
    auto data = * new list<DATA_TYPE>();
    string serializedRecord;

    while(!file.eof())
    {
        getline(file, serializedRecord);
        auto record = DATA_TYPE::Deserialize(serializedRecord, _separator);

        data.push_back(record);
    }

    return data;
}
