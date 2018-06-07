#include "Destroyer.h"




Destroyer::Destroyer(System::String ^ name, System::Drawing::PointF ^ location): Fleet(name, location)
{
	this->HP = 2;
	this->maxSpeed = 3;
	this->maxAttackRange = 10;
	this->attackCD = 15;
	this->maxDefenseRange = 20;
	this->defenseCD = 60;
	this->damage = 1;
	this->sheelSpeed = 3;
}
