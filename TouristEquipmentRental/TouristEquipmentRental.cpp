#include <iostream>
#include <cwchar>
#include "FileDatabase.h"
#include "DatabaseOperator.h"
#include "GlobalOperator.h"
#include "UnitOfView.h"

int main(int argc, char** argv)
{	
	auto fileDatabase = * new FileDatabase();
	auto databaseOperator = * new DatabaseOperator(fileDatabase);
	auto unitOfView = * new UnitOfView();	
	GlobalOperator style;
	
	style.SetFont(24,0);

	unitOfView.LoadMenu();

	if (unitOfView.SigningOnIn().isRegisterMode)
	{
		auto newUser = * new User(
			unitOfView.SigningOnIn().GetId(),
			unitOfView.SigningOnIn().GetFirstName(),
			unitOfView.SigningOnIn().GetLastName(),
			unitOfView.SigningOnIn().GetEmail(),
			unitOfView.SigningOnIn().GetPassword()
		);

		databaseOperator.AddUser(newUser);
	}

	/*Sign In*/
	try
	{
		auto user = databaseOperator.GetUser(
			unitOfView.SigningOnIn().GetEmail(),
			unitOfView.SigningOnIn().GetPassword()
		);

		if (user.Activated() == true)
		{
			if (user.Id()[0] == 'A')
			{
				style.Delay(1.5);
				cout << "Zalogowano pomyslnie do panelu administratora" << endl;
				//AdminPanel.RenderAdminMenu();
			} 
			else if (user.Id()[0] == 'U')
			{
				style.Delay(1.5);
				cout << "Zalogowano pomyslnie do panelu uzytkownika" << endl;
				unitOfView.Panel().RenderUserMenu(user);
			}
		} 
		else
		{
			cout << "Konto nie jest aktywne. Skontaktuj sie z administratorem" << endl;
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
		unitOfView.SigningOnIn().RenderLoginView();
	}

	return 0;	
}
