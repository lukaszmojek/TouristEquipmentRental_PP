#include <iostream>
#include <cwchar>
#include "FileDatabase.h"
#include "DatabaseOperator.h"
#include "GlobalOperator.h"
#include "ProgramFlow.h"

int main(int argc, char** argv)
{	
	auto fileDatabase = * new FileDatabase();
	auto databaseOperator = * new DatabaseOperator(fileDatabase);
	auto unitOfView = * new UnitOfView();
	auto programFlow = * new ProgramFlow(unitOfView, databaseOperator);
	auto style = * new GlobalOperator();

	style.SetFont(24, 0);

	programFlow.RenderApp();

	return 0;	
}
