#include "Torpedo.h"
#include "Fleet.h"
#include <cmath>


Torpedo::Torpedo(System::Drawing::PointF ^ pos,float angle, System::String ^ name)
{
	this->angle = angle;
	this->location = gcnew PointF(pos->X, pos->Y);
	this->damage = 4;
	this->speed = (float)3.0 / 60;
	this->name = name;
}

void Torpedo::Move()
{
	//計算X-Y分量
	float trueAngle = angle / 180 * (float)3.14159265;
	this->location->X += speed * cosf(trueAngle);
	this->location->Y -= speed * sinf(trueAngle);
}

void Torpedo::Draw(Graphics ^ g)
{
	float X = this->location->X * 20;
	float Y = this->location->Y * 20;

	//畫圓
	float size = 6;
	g->FillPie(Brushes::BlueViolet,
		X - size / 2,
		Y - size / 2,
		size, size, 0.0, 360.0);
}

void Torpedo::collision(System::Collections::Generic::Dictionary<System::String^, Fleet^>^ fleetList)
{
	for each (auto var in fleetList)
	{
		if (var.Key == this->name)
			continue;
		float X = var.Value->getLocation()->X;
		float Y = var.Value->getLocation()->Y;
		float dis = sqrt(pow(this->location->X - X, 2) +
			pow(this->location->Y - Y, 2));
		if (dis < 0.5)
			this->isBoom = true;
	}
}
