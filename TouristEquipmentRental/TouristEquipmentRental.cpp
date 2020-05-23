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
        //auto user = databaseOperator->GetUser("Test@test.com", "dupa123");
        //auto user = databaseOperator->GetUser("dawid.blacha@gmail.com", "zaq123");

        auto reservations = databaseOperator->GetUserReservations(user.Id());

        for (auto reservation : reservations)
        {
            auto reservationEquipment = databaseOperator->GetReservationEquipment(reservation.Id());
            reservation.AssignEquipmentToReservation(reservationEquipment);
            user.AssignReservationToUser(reservation);
        }

        ;
    }
    catch (exception e)
    {
        cout << e.what();
    }
    

    return 0;
}
