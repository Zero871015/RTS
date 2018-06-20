#include "FlyingMissileCruiser.h"
#include "Torpedo.h"

FlyingMissileCruiser::FlyingMissileCruiser(System::String ^ name, System::Drawing::PointF ^ location) :Fleet(name, location)
{
	this->HP = 3;
	this->maxSpeed = (float)2.0/60;
	this->maxAttackRange = 15;
	this->attackCD = 30;
	this->maxDefenseRange = 10;
	this->defenseCD = 30;
	this->damage = 3;
	this->shellSpeed = (float)2.0/60;
	this->type = 3;
}

bool FlyingMissileCruiser::specialAttack(System::Collections::Generic::List<Shell^>^ list, float angle)
{
	if (this->specialCDNow <= 0)
	{
		this->specialCDNow = this->specialCD;
		list->Add(gcnew Torpedo(this->location, angle, this->name,2));
		System::Diagnostics::Debug::WriteLine("發射魚雷");
		return true;
	}
	else
	{
		System::Diagnostics::Debug::WriteLine("特殊攻擊冷卻中");
	}
	return false;
}
