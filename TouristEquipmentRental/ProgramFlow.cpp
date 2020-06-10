#include "ProgramFlow.h"

User ProgramFlow::NewUser() {

	auto newUser = *new User(
		unitOfView.SigningOnIn().GetId(),
		unitOfView.SigningOnIn().GetFirstName(),
		unitOfView.SigningOnIn().GetLastName(),
		unitOfView.SigningOnIn().GetEmail(),
		unitOfView.SigningOnIn().GetPassword()
	);

	return newUser;
}

User ProgramFlow::GetUser(DatabaseOperator databaseOperator) {

	auto user = databaseOperator.GetUser(
		unitOfView.SigningOnIn().GetEmail(),
		unitOfView.SigningOnIn().GetPassword()
	);

	return user;
}

void ProgramFlow::SignIn(DatabaseOperator databaseOperator, FileDatabase filedatabase) {
	if (GetUser(databaseOperator).Activated() == true)
	{
		if (GetUser(databaseOperator).Id()[0] == 'A')
		{
			style.Delay(1.5);
			cout << "Zalogowano pomyslnie do panelu administratora" << endl;
			//AdminPanel.RenderAdminMenu();
		}
		else if (GetUser(databaseOperator).Id()[0] == 'U')
		{
			style.Delay(1.5);
			cout << "Zalogowano pomyslnie do panelu uzytkownika" << endl;

			unitOfView.LoadUserMenu(GetUser(databaseOperator), filedatabase);
		}
	}
	else
	{
		cout << "Konto nie jest aktywne. Skontaktuj sie z administratorem" << endl;
	}
}

void ProgramFlow::RenderApp(DatabaseOperator databaseOperator, FileDatabase filedatabase) {

	unitOfView.LoadMenu();

	unitOfView.SigningOnIn().isRegisterMode ? databaseOperator.AddUser(NewUser()) : NULL;

	try {
		SignIn(databaseOperator, filedatabase);
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

}