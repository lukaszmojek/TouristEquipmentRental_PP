#include "PrimaryView.h"
#include <string>
#include <iostream>

using namespace std;

void PrimaryView::RenderStartView(SignInUpView signInUpView) {
    char choice;

    style.SetColor(13);

    style.CreateSeparator(30, '*');
    cout << " WYPOZYCZALNIA SPRZETU TURYSTYCZNEGO " << endl << endl;
    style.CreateSeparator(30, '*');

    style.SetColor(11);
    cout << "  > Wybierz operacje < " << endl;
    cout << endl;

    style.SetColor(14);
    cout << "1) Logowanie" << endl;
    cout << "2) Rejestracja" << endl;
    cout << "3) Wyjdz" << endl;
    cout << endl;

    style.SetColor(11);
    cout << "Przejdz do operacji nr: ";

    cin >> choice;
    system("cls");

    MenuSelect(choice, signInUpView);
}

void PrimaryView::MenuSelect(char choice, SignInUpView signInUpView) {

    string Log, Reg;

    switch (choice)
    {
    case '1':
        signInUpView.RenderLoginView();
        break;

    case '2':
        signInUpView.RenderRegisterView();
        break;

    case '3':
        exit(0);
        break;

    default: 
        cout << "Nie ma takiej opcji w menu!";
    };

    system("cls");
}