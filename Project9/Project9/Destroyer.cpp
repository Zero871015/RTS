#include "Destroyer.h"




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
}
