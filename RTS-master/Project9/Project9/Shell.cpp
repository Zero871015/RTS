#include "Shell.h"
#include <cmath>

using namespace System::Drawing;

Shell::Shell()
{

}

Shell::Shell(System::String ^ ID, float speed,int damage, System::Drawing::PointF ^ pos, System::Drawing::PointF ^ target)
{
	this->name = ID;
	this->speed = speed;
	this->damage = damage;
	//不可以直接指派pos的值，否則指標一樣，船隻和砲彈的座標就會變同一個記憶體存儲。
	this->location = gcnew PointF(pos->X, pos->Y);
	this->targetLocation = target;
	this->isBoom = false;
	this->ID++;
}

Shell::~Shell()
{
}

void Shell::Draw(Graphics ^ g)
{
	float X = this->location->X * 20;
	float Y = this->location->Y * 20;
	float dis = sqrt(powf((this->location->X - this->targetLocation->X), 2)+
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
		this->targetLocation->X*20 - 30,
		this->targetLocation->Y*20 - 30,
		60.0, 60.0, 0.0, 360.0);

	//畫圓
	float size = 10;
	g->FillPie(Brushes::Black,
		X - size / 2,
		Y - size / 2,
		size, size, 0.0, 360.0);
	//畫名字
	g->DrawString(this->name,
		gcnew Font("Arial", 12),
		Brushes::Black,
		X + 10,
		Y - 20);
}

void Shell::Move()
{
	//計算X-Y分量各要移動多少
	float X, Y, D;
	X = this->targetLocation->X - this->location->X;
	Y = this->targetLocation->Y - this->location->Y;
	D = sqrt(X * X + Y * Y);
	//如果已經到點，BOOOOOOOOOOOM
	if (X * X + Y * Y < this->speed * this->speed)
	{
		this->location = this->targetLocation;
		this->isBoom = true;
	}
	//還沒到點，移動分量
	else
	{
		this->location->X += this->speed * X / D;
		this->location->Y += this->speed * Y / D;
	}
}

bool Shell::getIsBoom()
{
	return this->isBoom;
}

int Shell::getDamage()
{
	return this->damage;
}

PointF ^ Shell::getLocation()
{
	return this->location;
}

System::String ^ Shell::getName()
{
	return this->name;
}
