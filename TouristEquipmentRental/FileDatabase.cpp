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
    //Initialize();
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

    while(!file.eof())
    {
        string serializedRecord;

        getline(file, serializedRecord);
        auto record = DATA_TYPE::Deserialize(serializedRecord, _separator);

        data.push_back(record);
    }

    return data;
}
