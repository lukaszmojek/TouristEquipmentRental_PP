#include "PrimmaryView.h"
#include <Windows.h>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;


string PrimmaryView::GetID() {
    return _TypedID;
}

string PrimmaryView::GetPassword() {
    return _TypedPassword;
}

string PrimmaryView::GetFirstName() {
    return _TypedFirstName;
}

string PrimmaryView::GetLastName() {
    return _TypedLastName;
}

string PrimmaryView::GetEmail() {
    return _TypedEmail;
}


/* ---------------EKRAN STARTOWY----------------*/

void PrimmaryView::RenderStartView() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 13);
        cout << setfill('*') << setw(30) << '*' << endl; cout << endl;
        cout << "   WYPOZYCZALNIA KAJAKOW " << endl; cout << endl;
        cout << setfill('*') << setw(30) << '*' << endl; cout << endl;


    SetConsoleTextAttribute(hConsole, 11);
    cout << "  > Wybierz operacje < " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "1) Logowanie" << endl;
    cout << "2) Rejestracja" << endl;
    cout << "3) Wyjdz" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);
}
int PrimmaryView::Wybor() {
    string Log, Reg;
    cout << "Przejdz do operacji nr: ";
    char choice;
    cin >> choice;

    switch (choice)
    {
    case '1':
        return 1;
        break;

    case '2':
        return 0;
        break;

    case '3':
        exit(0);
        break;

    default: cout << "Nie ma takiej opcji w menu!";
    };
    system("cls");
}

/* ---------------LOGOWANIE----------------*/

void PrimmaryView::LoginView() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string userID, password;

    SetConsoleTextAttribute(hConsole, 13);
    cout << setfill('*') << setw(30) << '*' << endl; cout << endl;
    cout << setfill(' ') << setw(19) << "LOGOWANIE" << endl;
    cout << endl; cout << setfill('*') << setw(30) << '*' << endl; cout << endl;

    SetConsoleTextAttribute(hConsole, 10);
    cout << " ID UZYTKOWNIKA: ";
    cin >> userID;
    cout << endl;
    cout << " HASLO: ";
    cin >> password;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);

    _TypedID = userID;
    _TypedPassword = password;
    cout << "Sprawdzanie poprawnoscii wprowadzonych danych..." << endl;
    cout << endl;
}

/* ---------------REJESTRACJA----------------*/

void PrimmaryView::RegisterView() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string userID, password, firstname, lastname,email;

    SetConsoleTextAttribute(hConsole, 5);
    cout << setfill('*') << setw(30) << '*' << endl; cout << endl;
    cout << setfill(' ') << setw(19) << "REJESTRACJA" << endl;
    cout << endl; cout << setfill('*') << setw(30) << '*' << endl; cout << endl;

    SetConsoleTextAttribute(hConsole, 14);
    cout << " ID UZYTKOWNIKA: ";
    cin >> userID;
    cout << endl;

    cout << " IMIE: ";
    cin >> firstname;
    cout << endl;

    cout << " NAZWISKO: ";
    cin >> lastname;
    cout << endl;

    cout << " EMAIL: ";
    cin >> email;
    cout << endl;

    cout << " HASLO: ";
    cin >> password;
    cout << endl;

    cout << " POWTORZ HASLO: ";
    cin >> password;
    cout << endl;

    SetConsoleTextAttribute(hConsole, 11);

    _TypedID = userID;
    _TypedPassword = password;
    cout << "Sprawdzanie poprawnoscii wprowadzonych danych..." << endl;
    cout << endl;
}