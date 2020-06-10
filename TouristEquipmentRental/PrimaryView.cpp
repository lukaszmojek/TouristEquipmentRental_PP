#include "PrimaryView.h"

using namespace std;

char PrimaryView::RenderStartView() {

    char choice;

    style.SetColor(102);
    style.CreateSeparator(55, ' ');

    style.SetColor(14);
    cout << setfill(' ')<< setw(45) << " WYPOZYCZALNIA SPRZETU TURYSTYCZNEGO " << endl << endl;

    style.SetColor(102);
    style.CreateSeparator(55, ' ');

    style.SetColor(11);
    cout << setfill(' ') << setw(37) << "  > Wybierz operacje < " << endl;
    cout << endl;

    style.SetColor(14);
    cout << setw(20) << "1." << setw(15) << "Logowanie" << endl;
    cout << setw(20) << "2." << setw(15) << "Rejestracja" << endl;
    cout << setw(20) << "3." << setw(15) << "Wyjdz" << endl;
    cout << endl;

    style.SetColor(11);
    style.CreateSeparator(55, '_');
    cout << setfill(' ')<< setw(37) << "Przejdz do operacji nr: ";

    cin >> choice;

    system("cls");

    return choice;

}