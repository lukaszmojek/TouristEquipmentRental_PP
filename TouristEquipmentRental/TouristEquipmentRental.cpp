#include <iostream>
#include <cwchar>
#include <iomanip>
#include <chrono>
#include <thread>
/*header files*/
#include <Windows.h>
#include "FileDatabase.h"
#include "PrimmaryView.h"
#include "UserPanel.h"
#include "DatabaseOperator.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void sleep(int sec) {
	sleep_until(system_clock::now() + seconds(sec));
}
void setColor(int nr) {
	SetConsoleTextAttribute(hConsole, nr);
}

int main(int argc, char** argv)
{	
    auto fileDatabase = new FileDatabase();

	auto databaseOperator = new DatabaseOperator(*fileDatabase);

	try
	{
		auto user = databaseOperator->GetUser("ratatata@gmail.com", "kowalstwo");
		//auto user = databaseOperator->GetUser("Test@test.com", "dupa123");
		//auto user = databaseOperator->GetUser("dawid.blacha@gmail.com", "zaq123");

		auto reservations = databaseOperator->GetUserReservations(user.Id());

		for (auto reservation : reservations)
		{
			auto reservationEquipment = databaseOperator->GetReservationEquipment(reservation.Id());
			reservation.AssignEquipmentToReservation(reservationEquipment);
			user.AssignReservationToUser(reservation);
		}

		;
	}
	catch (exception e)
	{
		cout << e.what();
	}

	/* FONT */
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 25;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	PrimmaryView Start;
	UserPanel UserPanel;

	Start.RenderStartView();
	if (Start.Select() == 1) {
		system("cls");
		Start.LoginView();
		/*Logowanie administratora*/
		if ( (Start.GetID() == "admin") && (Start.GetPassword() == "admin") ) {
			cout << endl;
			setColor(10);
			sleep(1.5);
			cout << "Zalogowano pomyslnie do panelu administratora!" << endl;
			sleep(1.8);
			//TODO:RenderAdminPanel();
			system("cls");
		}
		/*Logowanie u¿ytkownika*/
		else if ((Start.GetID() == "uzytkownik") && (Start.GetPassword() == "haslo")) {
			
			sleep(1.5);
			setColor(10);
			cout << "Zalogowano pomyslnie!" << endl;
			sleep(1.5);
			system("cls");
			UserPanel.RenderUserMenu();
		}
		else {
			setColor(12);
			sleep(2);
			cout << " Wprowadzone dane sa niepoprawne, sproboj sie zalgowac jeszcze raz" << endl;
			sleep(2);
			system("cls");
			Start.LoginView();
		}
	}
	else {
		system("cls");
		Start.RegisterView();
		//TODO: sprawdzic po kolei kazda wartosc czy taka istnieje w bazie
		//TODO: sprawdzic czy wprowadzone hasla sa takie same 
	}



    

    return 0;

}
