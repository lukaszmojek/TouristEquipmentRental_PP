#include "ProgramFlow.h"

User ProgramFlow::NewUser() {

	auto newUser = *new User(
		_unitOfView.SigningOnIn().GetId(),
		_unitOfView.SigningOnIn().GetFirstName(),
		_unitOfView.SigningOnIn().GetLastName(),
		_unitOfView.SigningOnIn().GetEmail(),
		_unitOfView.SigningOnIn().GetPassword()
	);

	return newUser;
}

User ProgramFlow::GetUser() {
	auto user = _databaseOperator.GetUser(
		_unitOfView.SigningOnIn().GetEmail(),
		_unitOfView.SigningOnIn().GetPassword()
	);

	return user;
}

void ProgramFlow::SignIn() {
	if (GetUser().Activated() == true)
	{
		if (GetUser().Id()[0] == 'A')
		{
			_style.Delay(1.5);
			cout << "Zalogowano pomyslnie do panelu administratora" << endl;
			//AdminPanel.RenderAdminMenu();
		}
		else if (GetUser().Id()[0] == 'U')
		{
			_style.Delay(1.5);
			cout << "Zalogowano pomyslnie do panelu uzytkownika" << endl;

			_unitOfView.LoadUserMenu(GetUser(), _databaseOperator);
		}
	}
	else
	{
		cout << "Konto nie jest aktywne. Skontaktuj sie z administratorem" << endl;
	}
}

void ProgramFlow::RenderApp() {

	_unitOfView.LoadMenu();

	_unitOfView.SigningOnIn().isRegisterMode ? _databaseOperator.AddUser(NewUser()) : NULL;

	try {
		SignIn();
	}
	catch (exception e)
	{
		cout << endl;
		_style.SetColor(4);
		_style.Delay(1.5);

		cout << e.what();

		_style.Delay(1.5);

		cout << endl;

		system("cls");
		_unitOfView.SigningOnIn().RenderLoginView();
	}
}