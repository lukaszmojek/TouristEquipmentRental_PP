#ifndef ProgramFlow_H
#define ProgramFlow_H

#include <iostream>

#include "UnitOfView.h"
#include "GlobalOperator.h"

class ProgramFlow
{
private:
	UnitOfView _unitOfView;
	DatabaseOperator _databaseOperator;
	GlobalOperator _style;

public:
	ProgramFlow(UnitOfView unitOfView, DatabaseOperator databaseOperator)
	{
		_unitOfView = unitOfView;
		_databaseOperator = databaseOperator;
		_style = * new GlobalOperator();
	}

	User NewUser();

	User GetUser();

	void SignIn();

	void RenderApp();

};

#endif //ProgramFlow_H