#include "CarrierVessel.h"



CarrierVessel::CarrierVessel(System::String ^ name, System::Drawing::PointF ^ location):Fleet(name,location)
{
	this->HP = 5;
	this->maxSpeed = (float)1.0/60;
	this->maxAttackRange = 25;
	this->attackCD = 60;
	this->maxDefenseRange = 5;
	this->defenseCD = 15;
	this->damage = 3;
	this->sheelSpeed = (float)4.0/60;
	
}
