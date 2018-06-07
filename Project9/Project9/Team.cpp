#include "Team.h"



Team::Team()
{
	this->fleetList = gcnew System::Collections::Generic::Dictionary<System::String ^, Fleet ^>;
	this->shellList = gcnew System::Collections::Generic::List<Shell ^>;
	this->bufferShellList = gcnew System::Collections::Generic::List<Shell ^>;
	count = 0;
}
