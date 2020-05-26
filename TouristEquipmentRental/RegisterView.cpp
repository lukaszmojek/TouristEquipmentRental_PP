#include <iostream>
#include "RegisterView.h"
#include "LoginView.h"
#include "GlobalOperator.h"

using namespace std;

void RegisterView::RenderRegisterView() {

    string  userID, 
            password, 
            firstname, 
            lastname, 
            email;

    style.SetColor(5);
    style.CreateSeparator(30, '*');
    cout << "REJESTRACJA" << endl;
    style.CreateSeparator(30, '*');

    style.SetColor(14);
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

    style.SetColor(11);

    _TypedID = userID;
    _TypedPassword = password;

    cout << "Sprawdzanie poprawnoscii wprowadzonych danych..." << endl;
    cout << endl;
}