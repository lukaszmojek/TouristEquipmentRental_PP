#include "UserPanel.h"

void UserPanel::RenderUserMenu(User user) {

    string Log, Reg;
    char choice;

    system("cls");

    style.SetColor(102);
    style.CreateSeparator(55, ' ');

    style.SetColor(14);
    cout << setfill(' ') << setw(37) << "PANEL UZYTKOWNIKA\n\n";

    style.SetColor(102);
    style.CreateSeparator(55, ' ');

    style.SetColor(11);
    cout << setfill(' ') << setw(37) << "  > Wybierz operacje < " << endl;
    cout << endl;

    style.SetColor(14);
    cout << setw(15) << "1." << setw(23) << "Dane konta" << endl;
    cout << setw(15) << "2." << setw(23) << "Moje rezerwacje" << endl;
    cout << setw(15) << "3." << setw(23) << "Zarezerwuj sprzet" << endl;
    cout << setw(15) << "4." << setw(23) << "Wyjdz" << endl;
    cout << endl;

    style.SetColor(11);
    style.CreateSeparator(55, '_');
    cout << setfill(' ') << setw(37) << "Przejdz do operacji nr: ";

    style.SetColor(14);
    cin >> choice;

    switch (choice)
    {
    case '1':
        ShowUserData(user);
        RenderNavigationBar(user, 50);
        break;

    case '2':
        ShowUserReservations(user);
        RenderNavigationBar(user, 110);
        break;
    case '3':
        RentEquipmentFlow(user);
        RenderNavigationBar(user, 110);
        break;
    case '4':
        exit(0);
        break;

    default: cout << "Nie ma takiej opcji w menu!";
    };


}
void UserPanel::ShowUserData(User user) {

    system("cls");

    int fieldLentgth = 30;

    style.SetColor(102);
    style.CreateSeparator(50, ' ');
    style.SetColor(11);

    cout << endl;
    cout << setfill(' ') << setw(15) << "RODZAJ KONTA:" << setw(fieldLentgth);
    style.SetColor(14);
    (user.Id()[0] == 'A') ? cout << "ADMINISTRATOR" << endl : cout << "UZYTKOWNIK" << endl << endl;

    style.SetColor(11);
    cout << setw(15) << "STATUS KONTA:" << setw(fieldLentgth);
    style.SetColor(14);

    if (user.Activated() == true) {
        style.SetColor(2);
        cout << "AKTYWOWANY\n" << endl;
    }
    else {
        style.SetColor(4);
        cout << "NIEAKTYWNY\n" << endl;
    }

    style.SetColor(11);
    cout << setw(15) << "IMIE:" << setw(fieldLentgth);
    style.SetColor(14);
    cout << user.FirstName() << endl << endl;

    style.SetColor(11);
    cout << setw(15) << "NAZWISKO:" << setw(fieldLentgth);
    style.SetColor(14);
    cout << user.LastName() << endl << endl;

    style.SetColor(11);
    cout << setw(15) << "EMAIL:" << setw(fieldLentgth);
    style.SetColor(14);
    cout << user.Email() << endl << endl;
    cout << endl;

    style.SetColor(102);
    style.CreateSeparator(50, ' ');
    style.SetColor(14);

}


void UserPanel::ShowUserReservations(User user) {

    system("cls");

    auto fileDatabase = new FileDatabase();
    auto databaseOperator = new DatabaseOperator(*fileDatabase);
    auto reservations = databaseOperator->GetUserReservations(user.Id());
    int  fieldLentgth = 30;

    style.SetColor(102);
    style.CreateSeparator(110, ' ');
    style.SetColor(11);

    cout << endl;

    cout << setfill(' ') << setw(20) << "NUMER REZERWACJI" << setw(fieldLentgth);
    cout << setfill(' ') << setw(30) << "DATA ROZPOCZECIA WYNAJMU" << setw(fieldLentgth);
    cout << setfill(' ') << setw(30) << "DATA ZAKONCZENIA WYNAJMU" << setw(fieldLentgth);
    cout << setfill(' ') << setw(30) << "WYPOZYCZONY SPRZET" << setw(fieldLentgth);
    cout << endl;

    for (auto reservation : reservations) {

        style.SetColor(14);
        cout << endl;

        cout << setfill(' ') << setw(20) << reservation.Id();
        cout << setfill(' ') << setw(30) << reservation.StartDate();
        cout << setfill(' ') << setw(30) << reservation.EndDate();

        auto reservationEquipment = databaseOperator->GetReservationEquipment(reservation.Id());

        cout << setfill(' ') << setw(30);
        for (auto Equipment : reservationEquipment) {

            cout << Equipment.Name() << setfill(' ') << setw(110) << endl;

        }
    }

    cout << endl << endl;
    style.SetColor(102);
    style.CreateSeparator(110, ' ');
    style.SetColor(11);
}


void UserPanel::RentEquipmentFlow(User user)
{
    auto RentEquipment = new RentEquipmentView;

    RentEquipment->RenderEquipmentList();
    RentEquipment->CreateReservation(user);
}

void UserPanel::RenderNavigationBar(User user, int widht)
{
    int c;

    cout << endl << endl << endl;
    style.SetColor(11);
    style.CreateSeparator(widht, '_');

    style.SetColor(14);
    cout << "[1] Wroc do menu" << setfill(' ') << setw(widht - 15) << "[2] Wyjdz z aplikacji\n";

    style.SetColor(11);
    style.CreateSeparator(widht, '_');
    cout << endl;
    cout << "Przejdz do opracji nr: ";

    style.SetColor(14);
    cin >> c;
    switch (c)
    {
    case 1:
        RenderUserMenu(user);
        break;

    case 2:
        exit(0);
        break;

    default: cout << "Nie ma takiej opcji w menu!";
    }
}