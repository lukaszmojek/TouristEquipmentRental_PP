#include "DatabaseOperator.h"

DatabaseOperator::DatabaseOperator(FileDatabase databaseContext)
{
	_databaseContext = databaseContext;
}

User DatabaseOperator::GetUser(string email, string password)
{
	for (auto user : _databaseContext.GetUsers())
	{
		if (user.Email() == email & user.Password() == password)
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

list<Reservation> DatabaseOperator::GetUserReservations(string userId)
{
	auto reservations = * new list<Reservation>();

	for (auto reservation : _databaseContext.GetReservations())
	{
		if (reservation.UserId() == userId)
		{
			reservations.push_back(reservation);
		}
	}

	return reservations;
}

list<Equipment> DatabaseOperator::GetReservationEquipment(string reservationId)
{
	auto equipmentIds = * new list<string>();
	auto reservationEquipment = * new list<Equipment>();

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
