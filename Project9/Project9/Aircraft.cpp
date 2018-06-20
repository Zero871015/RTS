#include "Aircraft.h"
#include "Fleet.h"
#include <cmath>


Aircraft::Aircraft(System::Drawing::PointF ^ pos, Fleet ^ target,float VX,float VY)
{
	this->location = gcnew PointF(pos->X, pos->Y);
	this->target = target;
	this->VX = VX;
	this->VY = VY;
	this->damage = 1;
	this->targetLocation = target->getLocation();
	this->name = "Aircraft";
}

void Aircraft::Move()
{
	this->targetLocation = target->getLocation();
	//計算X-Y分量各要移動多少
	float X, Y;
	X = (this->targetLocation->X - this->location->X);
	Y = (this->targetLocation->Y - this->location->Y);

	AX = X / 200;
	AY = Y / 200;
	VX += AX;
	VY += AY;
	float V = sqrt(pow(VX, 2) + pow(VY, 2));
	if (V > 0.4)
	{
		VX = VX *(float)0.4 / V;
		VY = VY *(float)0.4 / V;
	}
	//如果已經到點，BOOOOOOOOOOOM
	if (abs(X) + abs(Y) < 1)
	{
		this->isBoom = true;
	}
	//還沒到點，移動分量
	else
	{
		this->location->X += VX;
		this->location->Y += VY;
	}
}

void Aircraft::Draw(Graphics ^ g)
{
	float X = this->location->X * 20;
	float Y = this->location->Y * 20;
	float dis = sqrt(powf((this->location->X - this->targetLocation->X), 2) +
		powf((this->location->Y - this->targetLocation->Y), 2));
	SolidBrush ^ b;
	if (dis > 5)
	{
		b = gcnew SolidBrush(Color::FromArgb(0, 0, 0, 0));
	}
	else
	{
		b = gcnew SolidBrush(Color::FromArgb((int)((5 - dis) * 30), (int)((5 - dis) * 51), 0, 0));
	}
	//畫出警告區域
	g->FillPie(b,
		this->targetLocation->X * 20 - 30,
		this->targetLocation->Y * 20 - 30,
		60.0, 60.0, 0.0, 360.0);


	//畫圓
	float size = 6;
	g->FillPie(Brushes::DarkRed,
		X - size / 2,
		Y - size / 2,
		size, size, 0.0, 360.0);


}