#include "RentEquipmentView.h"
#include "StringOperations.h"

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

	for (auto eq : equipment)
	{
		++pos;
		positions.push_back(pos);
		cout << setw(45) << pos << ". " << eq.Name() << endl;
	}

	style.SetColor(11);
	style.CreateSeparator(110, '_');
	cout << endl;

	style.SetColor(11);
	cout << setfill(' ') << setw(60) << "Wpisz numery sprzetów oddzielone przecinkiem, ktory chcesz zarezerwowac: ";
	style.SetColor(14);
	cin >> EquipmentNumbersInput;
	cout << endl;
}

vector<Equipment> RentEquipmentView::GetPickedEquipment(vector<Equipment> equipment)
{
	auto SelectedEquipment = * new vector<Equipment>();

	//TODO:multiple eq select 
	isEquipmentOnList = false;

	auto equipmentNumbers = StringOperations::Split(EquipmentNumbersInput, ',');

	for (auto eq : equipment)
	{
		for (auto equipmentNumber : equipmentNumbers)
		{
			if (stoi(eq.Id().substr(2, 4)) == stoi(equipmentNumber))
			{
				auto pickedEquipment = * new Equipment(eq.Id(), eq.Name());
				
				isEquipmentOnList = true;

				SelectedEquipment.push_back(pickedEquipment);
			}
		}
	}

	return SelectedEquipment;
}

Reservation RentEquipmentView::CreateReservation(User user, vector<Reservation> reservations, vector<Equipment> equipment)
{
	stringstream ss;
	string startDate, endDate;

	if (isEquipmentOnList)
	{
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

		if (DateIsValid(startDate) && DateIsValid(endDate))
		try
		{
			int lastReservation = stoi(reservations.back().Id().substr(1, 3)) + 1;
			ss << lastReservation;
			string lastReservationID = ss.str();

			lastReservationID.insert(0, "R");

				for (int i = 1; lastReservationID.length() < 4; ++i)
				{
					lastReservationID.insert(1, "0");
				}

			auto newReservation = * new Reservation(lastReservationID, user.Id(), startDate, endDate);
			newReservation.AssignEquipmentToReservation(GetPickedEquipment(equipment));

			//user.AssignReservationToUser(newReservation);

			style.SetColor(2);
			cout << endl;
			cout << setw(65) << "Rezerwacja przebiegla pomyslnie!\n\n";
			style.SetColor(3);

			cout << setw(40) << " Zarezerwowales przedmiot ";
			style.SetColor(14);
			cout << GetPickedEquipment(equipment)[0].Name();

			style.SetColor(3);
			cout << " w terminie od ";

			style.SetColor(14);
			cout << startDate;

			style.SetColor(3);
			cout << " do ";

			style.SetColor(14);
			cout << endDate;
			cout << endl;

			return newReservation;
		}
		catch (exception e)
		{
			style.SetColor(4);
			cout << setw(60) << "Wystapil blad!";
			style.SetColor(11);
		}
	}
	else
	{
		style.SetColor(4);
		cout << "Brak pozycji na liscie!";
		style.SetColor(11);
	}
}

bool RentEquipmentView::DateIsValid(string date)
{
	auto dataDetails = StringOperations::Split(date, '-');

	auto day = stoi(dataDetails[0]);
	auto month = stoi(dataDetails[1]);
	auto year = stoi(dataDetails[2]);

	return 0 < day && day < 32 &&
		0 < month && month < 13 &&
		2019 < year && year < 2023;
}