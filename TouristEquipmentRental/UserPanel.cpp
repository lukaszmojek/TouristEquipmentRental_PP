#include "UserPanel.h"
#include <Windows.h>
#include <iomanip>
#include <string>
#include <iostream>

void UserPanel::RenderUserMenu() {

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, 13);
        cout << setfill('*') << setw(30) << '*' << endl; cout << endl;
        cout << "   PANEL UZYTKOWNIKA " << endl; cout << endl;
        cout << setfill('*') << setw(30) << '*' << endl; cout << endl;


        SetConsoleTextAttribute(hConsole, 11);
        cout << "  > Wybierz operacje < " << endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "1) Dane konta" << endl;
        cout << "2) Moje rezerwacje" << endl;
        cout << "3) Zarezerwuj sprzet" << endl;
        cout << "4) Wyloguj " << endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 11);
    }
    int UserPanel::Select() {

        string Log, Reg;
        char choice;

        cout << "Przejdz do operacji nr: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            return 1;
            break;

        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            exit(0);
            break;

        default: cout << "Nie ma takiej opcji w menu!";
        };

        system("cls");

}