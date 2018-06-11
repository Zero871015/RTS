#include "BB.h"


BB::BB(System::String ^ name, System::Drawing::PointF ^ location) :Fleet(name, location)
{
	this->HP = 4;
	this->maxSpeed = (float)1.0/60;
	this->maxAttackRange = 20;
	this->attackCD = 30;
	this->maxDefenseRange = 10;
	this->defenseCD = 30;
	this->damage = 3;
	this->sheelSpeed = (float)2.0/60;
}
