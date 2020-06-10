#include <iostream>
#include <cwchar>
#include "FileDatabase.h"
#include "DatabaseOperator.h"
#include "GlobalOperator.h"
#include "ProgramFlow.h"

int main(int argc, char** argv)
{	
	ProgramFlow ProgramFlow;
	GlobalOperator style;

	auto fileDatabase = * new FileDatabase();
	auto databaseOperator = * new DatabaseOperator(fileDatabase);

	style.SetFont(24, 0);

	ProgramFlow.RenderApp(databaseOperator, fileDatabase);

	return 0;	
}
