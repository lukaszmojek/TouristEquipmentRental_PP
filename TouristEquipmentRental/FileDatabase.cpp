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

vector<User> FileDatabase::GetUsers()
{
	return _users;
}

void FileDatabase::AddUser(User newUser)
{
	_users.push_back(newUser);
}

vector<Reservation> FileDatabase::GetReservations()
{
	return _reservations;
}

vector<ReservationEquipment> FileDatabase::GetReservationEquimpent()
{
	return _reservationsEquipment;
}

void FileDatabase::SaveChanges()
{
	SaveData<User>(_usersFileName, _users);
	SaveData<Equipment>(_equipmentFileName, _equimpent);
	SaveData<Reservation>(_reservationsFileName, _reservations);
	SaveData<ReservationEquipment>(_reservationEquipmentFileName, _reservationsEquipment);
}

vector<Equipment> FileDatabase::GetEquimpent()
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
vector<DATA_TYPE> FileDatabase::ReadData(string fileName)
{
	auto file = _fileOperations.openFile(fileName, ios::in);
	auto data = *new vector<DATA_TYPE>();

	string serializedRecord;

	while (!file.eof())
	{
		getline(file, serializedRecord);
		auto record = DATA_TYPE::Deserialize(serializedRecord, _separator);

		data.push_back(record);
	}

	file.close();

	return data;
}

template <class DATA_TYPE>
void FileDatabase::SaveData(string fileName, vector<DATA_TYPE> data)
{
	ofstream out(fileName);

	for (auto record : data)
	{
		string serializedRecord = record.Serialize(_separator);
		out << serializedRecord << endl;
	}

	out.close();
}
