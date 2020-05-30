#include "PrimaryView.h"
#include <string>
#include <iostream>

using namespace std;

char PrimaryView::RenderStartView() {
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

    return choice;
}