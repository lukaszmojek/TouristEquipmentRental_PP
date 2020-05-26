#ifndef PrimmaryView_H
#define PrimmaryView_H
#include <iostream>
#include "GlobalOperator.h"

using namespace std;

class PrimmaryView
{
	GlobalOperator style;

public:

	void RenderStartView();

    int MenuSelect();
	
};

#endif //PrimmaryView_H


