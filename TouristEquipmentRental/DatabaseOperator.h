#pragma once
#include "FileDatabase.h"
class DatabaseOperator
{
private:
    FileDatabase _databaseContext;

public:
	DatabaseOperator()
	{
		_databaseContext = * new FileDatabase();
	}

	DatabaseOperator(FileDatabase databaseContext)
	{
		_databaseContext = databaseContext;
	}

	User GetUser(string email, string password);

	bool AddUser(User userToAdd);

	vector<Reservation> GetUserReservations(string userId);

	void AddReservation(Reservation reservation);

	vector<Equipment> GetReservationEquipment(string reservationId);
	
	vector<User> GetAllUsers();

	vector<Reservation> GetAllReservations();

	vector<Equipment> GetAllEquipment();

	void SaveChanges();
};

