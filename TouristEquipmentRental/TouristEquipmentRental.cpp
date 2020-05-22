#include <iostream>
#include "FileDatabase.h"
#include "DatabaseOperator.h"

using namespace std;

int main()
{
    auto fileDatabase = new FileDatabase();

    auto databaseOperator = new DatabaseOperator(* fileDatabase);

    try
    {
        auto user = databaseOperator->GetUser("ratatata@gmail.com", "kowalstwo");

        auto reservations = databaseOperator->GetUserReservations("U420");

        for (auto reservation : reservations)
        {
            auto reservationEquipment = databaseOperator->GetReservationEquipment(reservation.Id());
            reservation.AssignEquipmentToReservation(reservationEquipment);
            user.AssignReservationToUser(reservation);
        }
    }
    catch (exception e)
    {
    
    }
    

    return 0;
}
