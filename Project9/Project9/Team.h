#pragma once
#include "Fleet.h"
ref class Team
{
public:
	Team();
	System::Collections::Generic::Dictionary<System::String ^,Fleet ^>^ fleetList;
	System::Collections::Generic::List<Shell^>^ shellList;
	System::Collections::Generic::List<Shell^>^ bufferShellList;
	int count;
};
