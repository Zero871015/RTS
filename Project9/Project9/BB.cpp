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
	this->shellSpeed = (float)2.0/60;
	this->type = 2;
	this->clock = -1;
}

bool BB::specialAttack()
{
	if (this->specialCDNow <= 0)
	{
		this->specialCDNow = this->specialCD;
		this->bufferHP = this->HP;
		this->HP = 9999;
		this->clock = 10;
		return true;
	}
	else
	{
		System::Diagnostics::Debug::WriteLine("特殊技能冷卻中");
	}
	return false;
}

void BB::Move()
{
	Fleet::Move();
	clock--;
	if (clock == 0)
	{
		this->HP = this->bufferHP;
	}
}
