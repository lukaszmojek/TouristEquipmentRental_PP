#include "RentEquipmentView.h"

void RentEquipmentView::RenderEquipmentList(vector <Equipment> equipment) {

    system("cls");

    size_t pos{ 0 };
    vector<int> positions;

    style.SetColor(11);
    cout << setfill(' ') << endl;
    cout << setw(70) << "LISTA DOSTEPNYCH SPRZETOW\n\n";

    style.SetColor(102);
    style.CreateSeparator(110, '_');

    style.SetColor(14);
    cout << setfill(' ');

    for (auto eq : equipment) {
        ++pos;
        positions.push_back(pos);
        cout << setw(45) << pos << ". " << eq.Name() << endl;
    }

    style.SetColor(11);
    style.CreateSeparator(110, '_');
    cout << endl;

    style.SetColor(11);
    cout << setfill(' ') <<setw(60) << "Wpisz numer sprzetu, ktory chcesz zarezerwowac: ";
    style.SetColor(14);
    cin >> EquipmentNumber;
    cout << endl;
}

vector<Equipment> RentEquipmentView::GetPickedEquipment(vector <Equipment> equipment) {

    vector<Equipment> SelectedEquipment;

    //TODO:multiple eq select 
    isEquipmentOnList = false;
    for (auto eq : equipment) {
        if (stoi(eq.Id().substr(2, 4)) == EquipmentNumber) {
            auto pickedEquipment = new Equipment(eq.Id(), eq.Name());
            isEquipmentOnList = true;
            SelectedEquipment.push_back(eq);
            return SelectedEquipment;
        }
    }
}

void RentEquipmentView::CreateReservation(User user, vector<Reservation> reservations, vector <Equipment> equipment)
{
    stringstream ss;
    string startDate, endDate;

    if (isEquipmentOnList) {
        style.SetColor(11);
        cout << endl;
        cout << setw(60) << "Podaj date rozpoczecia wynajmu (Uzyj formatu DD-MM-YYYY): "; //TODO: data format class
        style.SetColor(14);
        cin >> startDate;
        cout << endl;
        style.SetColor(11);
        cout << setw(60) << "Podaj date zakoczenia wynajmu (Uzyj formatu DD-MM-YYYY): ";
        style.SetColor(14);
        cin >> endDate;
        cout << endl;

        try
        {
            int lastReservation = stoi(reservations.back().Id().substr(1, 3)) + 1;
            ss << lastReservation << endl;
            string lastReservationID = ss.str();

            lastReservationID.insert(0, "R");
            if (lastReservationID.length() == 3) {
                for (int i = 1; i < 3; i++)
                    lastReservationID.insert(i, "0");
            }
            else if (lastReservationID.length() == 4)
                lastReservationID.insert(1, "0");

            auto newReservation = *new Reservation(lastReservationID, user.Id(), startDate, endDate);
            newReservation.AssignEquipmentToReservation(GetPickedEquipment(equipment));
            user.AssignReservationToUser(newReservation);

            style.SetColor(2);
            cout << endl;
            cout << setw(65) << "Rezerwacja przebiegla pomyslnie!\n\n";
            style.SetColor(3);

            cout << setw(40) << " Zarezerwowales przedmiot ";
            style.SetColor(14);
            cout << GetPickedEquipment(equipment)[0].Name();

            style.SetColor(3);
            cout << " w terminie "; 

            style.SetColor(14);
            cout << startDate;

            style.SetColor(3);
            cout << " do ";

            style.SetColor(14);
            cout<< endDate;
            cout << endl;

        }
        catch (exception e)
        {
            style.SetColor(4);
            cout << setw(60) << "Wystapil blad!";
            style.SetColor(11);
        }

    }
    else {
        style.SetColor(4);
        cout << "Brak pozycji na liscie!";
        style.SetColor(11);
    }

}