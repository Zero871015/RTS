#pragma once
#include "Fleet.h"
ref class Team
{
public:
	Team();
	System::Collections::Generic::List<Fleet ^>^ fleetList;
};

