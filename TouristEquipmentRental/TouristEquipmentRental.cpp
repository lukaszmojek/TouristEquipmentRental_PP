#include <iostream>
#include <cwchar>
#include "FileDatabase.h"
#include "PrimmaryView.h"
#include "UserPanel.h"
#include "DatabaseOperator.h"
#include "GlobalOperator.h"
#include "SignInUpView.h"



int main(int argc, char** argv)
{	
	GlobalOperator style;
	PrimmaryView Start;
	SignInUpView Login;
	SignInUpView Register;

	UserPanel UserPanel;

    auto fileDatabase = new FileDatabase();

	auto databaseOperator = new DatabaseOperator(*fileDatabase);
	
	style.SetFont(24,0);


	Start.RenderStartView();
	if (Start.MenuSelect() == 1) {
		system("cls");
		Login.RenderLoginView();
		/*Sgin In*/
		try
		{
			auto user = databaseOperator->GetUser(Login.GetEmail(), Login.GetPassword());
			if ((user.Id()[0] == 'A') && (user.Activated() == true)) {
				style.Delay(1.5);
				cout << "Zalogowano pomyslnie do panelu administratora" << endl;
				//AdminPanel.RenderAdminMenu();
			}
			else {
				style.Delay(1.5);
				cout << "Zalogowano pomyœlnie do panelu uzytkownika" << endl;
				UserPanel.RenderUserMenu();
			}	
		}
		catch (exception e)
		{
			cout << endl;

			style.SetColor(4);
			style.Delay(1.5);

			cout << e.what();

			style.Delay(1.5);

			cout << endl;

			system("cls");
			Login.RenderLoginView();
			
		}
		return 0;
	}
}
