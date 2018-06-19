#include "Destroyer.h"
#include "Torpedo.h"



Destroyer::Destroyer(System::String ^ name, System::Drawing::PointF ^ location): Fleet(name, location)
{
	this->HP = 2;
	this->maxSpeed = (float)3.0/60;
	this->maxAttackRange = 10;
	this->attackCD = 15;
	this->maxDefenseRange = 20;
	this->defenseCD = 60;
	this->damage = 1;
	this->shellSpeed = (float)3.0/60;
	this->type = 4;
}

bool Destroyer::specialAttack(System::Collections::Generic::List<Shell^>^ list,float angle)
{
	if (this->specialCDNow <= 0)
	{
		this->specialCDNow = this->specialCD;
		list->Add(gcnew Torpedo(this->location, angle, this->name));
		list->Add(gcnew Torpedo(this->location, angle-10, this->name));
		list->Add(gcnew Torpedo(this->location, angle+10, this->name));
		System::Diagnostics::Debug::WriteLine("�o�g���p");
		return true;
	}
	else
	{
		System::Diagnostics::Debug::WriteLine("�S������N�o��");
	}
	return false;
}