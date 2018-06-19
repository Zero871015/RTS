#include "CarrierVessel.h"
#include "Aircraft.h"


CarrierVessel::CarrierVessel(System::String ^ name, System::Drawing::PointF ^ location):Fleet(name,location)
{
	this->HP = 5;
	this->maxSpeed = (float)1.0/60;
	this->maxAttackRange = 25;
	this->attackCD = 60;
	this->maxDefenseRange = 5;
	this->defenseCD = 15;
	this->damage = 3;
	this->shellSpeed = (float)4.0/60;
	this->type = 1;
}

bool CarrierVessel::specialAttack(System::Collections::Generic::List<Shell^>^ list, Fleet ^ target)
{
	if (this->specialCDNow <= 0)
	{
		this->specialCDNow = this->specialCD;
		list->Add(gcnew Aircraft(this->location, target, 2, 0));
		list->Add(gcnew Aircraft(this->location, target, -2, 0));
		list->Add(gcnew Aircraft(this->location, target, 0, 2));
		list->Add(gcnew Aircraft(this->location, target, 0, -2));
		System::Diagnostics::Debug::WriteLine("發射飛機");
		return true;
	}
	else
	{
		System::Diagnostics::Debug::WriteLine("特殊攻擊冷卻中");
	}
	return false;
}
