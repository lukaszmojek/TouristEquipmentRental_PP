#include <iostream>
#include "SignInUpView.h"
#include "GlobalOperator.h"


using namespace std;

string SignInUpView::GetId() {
    return _TypedID;
}

string SignInUpView::GetPassword() {
    return _TypedPassword;
}

string SignInUpView::GetFirstName() {
    return _TypedFirstName;
}

string SignInUpView::GetLastName() {
    return _TypedLastName;
}

string SignInUpView::GetEmail() {
    return _TypedEmail;
}

void SignInUpView::RenderLoginView() {

    string email, password;

    style.SetColor(13);
    style.CreateSeparator(30, '*');
    cout << "   LOGOWANIE " << endl; cout << endl;
    style.CreateSeparator(30, '*');

    style.SetColor(10);
    cout << " EMAIL: ";
    cin >> email;
    cout << endl;
    cout << " HASLO: ";
    cin >> password;
    cout << endl;

    _TypedEmail = email;
    _TypedPassword = password;

    style.SetColor(11);
    cout << "Sprawdzanie poprawnoscii wprowadzonych danych..." << endl;
    cout << endl;
}

void SignInUpView::RenderRegisterView() {

    string  userID,
            password,
            firstname,
            lastname,
            email;

    style.SetColor(5);
    style.CreateSeparator(30, '*');
    cout << "   REJESTRACJA " << endl; cout << endl;
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

    _TypedID        = userID;
    _TypedPassword  = password;
    _TypedFirstName = firstname;
    _TypedLastName  = lastname;
    _TypedEmail     = email;

    style.SetColor(11);
    cout << "Sprawdzanie poprawnoscii wprowadzonych danych..." << endl;
    cout << endl;
}