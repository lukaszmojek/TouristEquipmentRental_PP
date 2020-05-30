#include <iostream>
#include "SignInUpView.h"
#include "GlobalOperator.h"
#include <conio.h>

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
    isLoginMode = true;
    isRegisterMode = !isLoginMode;

    string email, password;
    char c = ' ';

    style.SetColor(13);
    style.CreateSeparator(30, '*');
    cout << " LOGOWANIE\n\n";
    style.CreateSeparator(30, '*');

    style.SetColor(10);
    cout << " EMAIL: ";
    cin >> email;
    cout << endl;
    cout << " \nHASLO: ";

    while (c != 13) {       //TODO: Naprawic backspace
        c = _getch();
        if (c != 13) {
            password += c;
            cout << "*";
        }
        
    }

    cout << endl;

    _TypedEmail = email;
    _TypedPassword = password;

    style.SetColor(11);
    cout << endl;
    cout << "Sprawdzanie poprawnoscii wprowadzonych danych..." << endl;
    style.CreateSeparator(50, '-');
}

void SignInUpView::RenderRegisterView() {
    isRegisterMode = true;
    isLoginMode = !isRegisterMode;

    string  userID,
            password,
            firstname,
            lastname,
            email;

    char c = ' ';

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
    while (c != 13) {
        c = _getch();
        if (c != 13) {
            password += c;
            cout << "*";
        }
    }

    cout << endl;

    _TypedID        = userID;
    _TypedPassword  = password;
    _TypedFirstName = firstname;
    _TypedLastName  = lastname;
    _TypedEmail     = email;

    style.SetColor(11);
    cout << endl;
    cout << "Sprawdzanie poprawnoscii wprowadzonych danych..." << endl;
    style.CreateSeparator(50, '-');
}