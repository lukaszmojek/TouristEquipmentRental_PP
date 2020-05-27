#include "UserPanel.h"
#include <Windows.h>
#include <iomanip>
#include <string>
#include <iostream>



void UserPanel::RenderUserMenu(User user) {
        system("cls");
        style.SetColor(13);
        style.CreateSeparator(30, '*');
        cout << "   PANEL UZYTKOWNIKA " << endl; cout << endl;
        style.CreateSeparator(30, '*');


        style.SetColor(11);
        cout << "  > Wybierz operacje < " << endl;
        cout << endl;
        style.SetColor(14);
        cout << "1) Dane konta" << endl;
        cout << "2) Moje rezerwacje" << endl;
        cout << "3) Zarezerwuj sprzet" << endl;
        cout << "4) Wyloguj " << endl;
        cout << endl;
        style.SetColor(11);

        string Log, Reg;
        char choice;

        cout << "Przejdz do operacji nr: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            ShowUserData(user);
            //TODO: Navigation();
            break;

        case '2':
            //TODO:ShowUserRezervations();
            //TODO: Navigation();
            break;
        case '3':
            //TODO:RentEquipment()
            //TODO: Navigation();
            break;
        case '4':
            //start.RenderStartView(); // TODO: How to inject SignInUpView here?
            break;

        default: cout << "Nie ma takiej opcji w menu!";
        };

        
    }
void UserPanel::ShowUserData(User user) {

    system("cls");

    int  primmaryC = 11,
         secconadryC = 14,
         fieldLentgth = 30;

    /*separator*/
    style.SetColor(102);
    style.CreateSeparator(50, ' ');
    style.SetColor(primmaryC);

    /*Konto*/
    cout << endl;
    cout <<setfill(' ') << setw(15) << "KONTO:" << setw(fieldLentgth);
    style.SetColor(secconadryC);
    (user.Id()[0] == 'A') ? cout << "ADMINISTRATOR" << endl : cout << "UZYTKOWNIK" << endl << endl;

    /*Status konta*/
    style.SetColor(primmaryC);
    cout << setw(15) << "STATUS KONTA:" << setw(fieldLentgth); 
    style.SetColor(secconadryC);
    if (user.Activated() == true) {
        style.SetColor(2);
        cout << "AKTYWOWANY" << endl;
    }
    else {
        style.SetColor(4);
        cout << "NIEAKTYWNY" << endl;
    }
    cout << endl;

    /*Imie*/
    style.SetColor(primmaryC);
    cout << setw(15) << "IMIE:" << setw(fieldLentgth);  
    style.SetColor(secconadryC);
    cout<< user.FirstName() << endl << endl;            
    style.SetColor(primmaryC);

    /*Nazwisko*/
    cout << setw(15) << "NAZWISKO:" << setw(fieldLentgth);
    style.SetColor(secconadryC);
    cout << user.LastName() << endl << endl;
    style.SetColor(primmaryC);

    /*Email*/
    cout << setw(15) << "EMAIL:" << setw(fieldLentgth); 
    style.SetColor(secconadryC);
    cout << user.Email() << endl << endl;                
    cout << endl;

    /*separator*/
    style.SetColor(102);
    style.CreateSeparator(50, ' ');
    style.SetColor(primmaryC);


}