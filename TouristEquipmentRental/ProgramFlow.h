#ifndef ProgramFlow_H
#define ProgramFlow_H

#include <iostream>

#include "UnitOfView.h"
#include "GlobalOperator.h"

class ProgramFlow
{
private:
	UnitOfView unitOfView;
	GlobalOperator style;

public:

	User NewUser();

	User GetUser(DatabaseOperator databaseOperator);

	void SignIn(DatabaseOperator databaseOperator, FileDatabase filedatabase);

	void RenderApp(DatabaseOperator databaseOperator, FileDatabase filedatabase);

};

#endif //ProgramFlow_H