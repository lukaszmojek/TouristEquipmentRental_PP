#include <iostream>
#include "SignInUpView.h"
#include "GlobalOperator.h"
#include <conio.h>
#include <iomanip>

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


    style.SetColor(102);
    style.CreateSeparator(55, ' ');

    style.SetColor(14);
    cout << setfill(' ') << setw(35) << " LOGOWANIE \n \n";

    style.SetColor(102);
    style.CreateSeparator(55, ' ');

    style.SetColor(3);
    cout << setfill(' ') << setw(20) << " EMAIL: ";

    style.SetColor(14);
    cin >> email;
    cout << endl;

    style.SetColor(3);
    cout << setw(20) <<"HASLO: ";

    style.SetColor(14);
    while (c != 13) {      
        c = _getch();
        if (c != 13) {
            password += c;
            cout << "*";
        }
        
    }

    _TypedEmail = email;
    _TypedPassword = password;

    style.SetColor(11);
    cout << "\n\n\nSprawdzanie poprawnoscii wprowadzonych danych..." << endl;

    style.Delay(1);
    style.CreateSeparator(50, '=');
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

    style.SetColor(102);
    style.CreateSeparator(55, ' ');

    style.SetColor(14);
    cout << setfill(' ') << setw(35) << "REJESTRACJA\n\n";

    style.SetColor(102);
    style.CreateSeparator(55, ' ');
    cout << setfill(' ');

    style.SetColor(3);
    cout << setw(20) << "ID UZYTKOWNIKA: ";
    style.SetColor(14);
    cin >> userID;
    cout << endl;

    style.SetColor(3);
    cout << setw(20) << " IMIE: ";
    style.SetColor(14);
    cin >> firstname;
    cout << endl;

    style.SetColor(3);
    cout << setw(20) << " NAZWISKO: ";
    style.SetColor(14);
    cin >> lastname;
    cout << endl;

    style.SetColor(3);
    cout << setw(20) << " EMAIL: ";
    style.SetColor(14);
    cin >> email;
    cout << endl;

    style.SetColor(3);
    cout << setw(20) << " HASLO: ";
    style.SetColor(14);

    while (c != 13) {
        c = _getch();
        if (c != 13) {
            password += c;
            cout << "*";
        }
    }

    _TypedID        = userID;
    _TypedPassword  = password;
    _TypedFirstName = firstname;
    _TypedLastName  = lastname;
    _TypedEmail     = email;
}