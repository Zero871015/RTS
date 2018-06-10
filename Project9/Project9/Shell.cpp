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
	//���i�H��������pos���ȡA�_�h���Ф@�ˡA��M���u���y�дN�|�ܦP�@�ӰO����s�x�C
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
	//�e�Xĵ�i�ϰ�
	g->FillPie(b,
		this->targetLocation->X*20 - 30,
		this->targetLocation->Y*20 - 30,
		60.0, 60.0, 0.0, 360.0);

	//�e��
	float size = 10;
	g->FillPie(Brushes::Black,
		X - size / 2,
		Y - size / 2,
		size, size, 0.0, 360.0);
	//�e�W�r
	g->DrawString(this->name,
		gcnew Font("Arial", 12),
		Brushes::Black,
		X + 10,
		Y - 20);
}

void Shell::Move()
{
	//�p��X-Y���q�U�n���ʦh��
	float X, Y, D;
	X = this->targetLocation->X - this->location->X;
	Y = this->targetLocation->Y - this->location->Y;
	D = sqrt(X * X + Y * Y);
	//�p�G�w�g���I�ABOOOOOOOOOOOM
	if (X * X + Y * Y < this->speed * this->speed)
	{
		this->location = this->targetLocation;
		this->isBoom = true;
	}
	//�٨S���I�A���ʤ��q
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
