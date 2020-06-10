#include "UnitOfView.h"

void UnitOfView::MainMenu(char choice) 
{
    switch (choice)
    {
        case '1':
            _signInUpView.RenderLoginView();
            break;

        case '2':
            _signInUpView.RenderRegisterView();
            break;

        case '3':
            exit(0);
            break;

        default: 
            cout << "Nie ma takiej opcji w menu!";
    };

    system("cls");
}

void UnitOfView::UserMenu(char choice, User user, FileDatabase filedatabase){

    auto reservations = filedatabase.GetReservations();
    auto equipment = filedatabase.GetEquimpent();

    switch (choice)
    {
    case '1':
        _userPanel.ShowUserData(user);
        LoadNavigation(user, 50, filedatabase);
        break;

    case '2':
        _userPanel.ShowUserReservations(user);
        LoadNavigation(user, 110, filedatabase);
        break;

    case '3':
        _userPanel.RentEquipmentFlow(user, filedatabase, reservations, equipment);
        LoadNavigation(user, 110, filedatabase);
        break;

    case '4':
        exit(0);
        break;

    default:
        cout << "Nie ma takiej opcji w menu!";
    };

    system("cls");
}

void UnitOfView::NavigationBar(char choice, User user, FileDatabase filedatabase) {

    switch (choice)
    {
    case 1:
        LoadUserMenu(user, filedatabase);
        break;

    case 2:
        exit(0);
        break;

    default: cout << "Nie ma takiej opcji w menu!";
    }
}
