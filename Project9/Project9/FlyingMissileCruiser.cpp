#include "FlyingMissileCruiser.h"


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
}
