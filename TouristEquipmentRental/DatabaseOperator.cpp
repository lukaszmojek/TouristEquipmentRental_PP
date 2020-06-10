#include "DatabaseOperator.h"

User DatabaseOperator::GetUser(string email, string password)
{
	for (auto user : _databaseContext.GetUsers())
	{
		if (user.Email() == email && user.Password() == password)
		{
			if (user.Activated() != 0) {
				return user;
			}
			else
			{
				throw exception("User not yet activated!");
			}
		}
	}

	throw exception("Wrong email or password!");
}

vector<User> DatabaseOperator::GetAllUsers()
{
	return _databaseContext.GetUsers();
}

bool DatabaseOperator::AddUser(User userToAdd)
{
	for (auto user : _databaseContext.GetUsers())
	{
		if (user.Id() == userToAdd.Id() || user.Email() == userToAdd.Email())
		{
			return false;
		}
	}

	try 
	{
		_databaseContext.AddUser(userToAdd);
		_databaseContext.SaveChanges();

		return true;
	}
	catch (exception e)
	{
	
	}
}

vector<Reservation> DatabaseOperator::GetUserReservations(string userId)
{
	auto reservations = * new vector<Reservation>();

	for (auto reservation : _databaseContext.GetReservations())
	{
		if (reservation.UserId() == userId)
		{
			reservations.push_back(reservation);
		}
	}

	return reservations;
}

void DatabaseOperator::AddReservation(Reservation newReservation)
{
	_databaseContext.AddReservation(newReservation);
}

vector<Reservation> DatabaseOperator::GetAllReservations()
{
	return _databaseContext.GetReservations();
}

vector<Equipment> DatabaseOperator::GetReservationEquipment(string reservationId)
{
	auto equipmentIds = * new vector<string>();
	auto reservationEquipment = * new vector<Equipment>();

	for (auto equipmentReservations : _databaseContext.GetReservationEquimpent())
	{
		if (equipmentReservations.ReservationId() == reservationId)
		{
			equipmentIds.push_back(equipmentReservations.EquipmentId());
		}
	}

	for (auto equipment : _databaseContext.GetEquimpent())
	{
		for (auto equipmentId : equipmentIds)
		{
			if (equipmentId == equipment.Id())
			{
				reservationEquipment.push_back(equipment);
			}
		}
	}

	return reservationEquipment;
}

vector<Equipment> DatabaseOperator::GetAllEquipment()
{
	return _databaseContext.GetEquimpent();
}

void DatabaseOperator::SaveChanges()
{
	_databaseContext.SaveChanges();
}


