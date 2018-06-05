#include "Shell.h"
#include <cmath>

using namespace System::Drawing;

Shell::Shell()
{

}

Shell::Shell(System::String ^ ID, float speed, System::Drawing::PointF ^ pos, System::Drawing::PointF ^ target)
{
	this->name = ID;
	this->speed = speed;
	//���i�H��������pos���ȡA�_�h���Ф@�ˡA��M���u���y�дN�|�ܦP�@�ӰO����s�x�C
	this->location = gcnew PointF(pos->X, pos->Y);
	this->targetLocation = target;
}

void Shell::Draw(Graphics ^ g)
{
	//�e��
	float size = 10;
	g->FillPie(Brushes::Black,
		this->location->X - size / 2,
		this->location->Y - size / 2,
		size, size, 0.0, 360.0);
	//�e�W�r
	g->DrawString(this->name,
		gcnew Font("Arial", 12),
		Brushes::Black,
		this->location->X + 10,
		this->location->Y - 20);
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
		//this->Boom();
	}
	//�٨S���I�A���ʤ��q
	else
	{
		this->location->X += this->speed * X / D;
		this->location->Y += this->speed * Y / D;
	}
}
