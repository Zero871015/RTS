#include "Fleet.h"
#include <Cmath>


Fleet::Fleet()
{
	this->name = "Monika";
	this->location = gcnew PointF(50, 50);
	this->maxSpeed = 1;
	this->sheelSpeed = 5;
}

Fleet::Fleet(System::String ^ name, System::Drawing::PointF ^ location)
{
	this->name = name;
	this->location = gcnew PointF(location->X,location->Y);
	this->maxSpeed = 1;
	this->sheelSpeed = 5;
}

void Fleet::Draw(Graphics ^ g)
{
	float X = this->location->X;
	float Y = this->location->Y;
	float size = 10;
	//�e�T����
	array<PointF>^ curvePoints = { PointF(X,Y - size),
		PointF(X - size / 2 * sqrtf(3),Y + size / 2) ,
		PointF(X + size / 2 * sqrtf(3),Y + size / 2) };
	g->FillPolygon(Brushes::Black, curvePoints);

	//�e�W�r
	g->DrawString(this->name,
		gcnew Font("Arial", 12),
		Brushes::Black,
		X + 10,
		Y - 20);

	//���եΡA�ХܥX�����I
	g->DrawLine(Pens::Red, this->location->X, this->location->Y, this->location->X + 1, this->location->Y + 1);
}

void Fleet::Move()
{
	//�p��X-Y���q
	float trueAngle=angle/180* (float)3.14159265;
	this->location->X += speed * cosf(trueAngle);
	this->location->Y -= speed * sinf(trueAngle);
	
	//�ثe�b���
	if (whereAmI() == WALL)
	{
		this->location->X -= speed * cosf(trueAngle);
		this->location->Y += speed * sinf(trueAngle);
		System::Diagnostics::Debug::WriteLine("����");
		this->speed = 0;
		this->angle = 0;
	}
	else if (whereAmI() == SEA)
	{

	}
}

bool Fleet::Fire(System::Collections::Generic::List<Shell^>^ list, PointF ^ location)
{
	//�s�W���u�A�Z�������n�^��false(�٨S��)
	System::String ^ name;
	name = "Shell";
	name += Shell::ID;
	Shell ^temp = gcnew Shell(name, sheelSpeed, this->location, location);
	list->Add(temp);
	return true;
}

int Fleet::whereAmI()
{
	//�^�ǥثe��ĥ�b����
	return Board::getBoard(this->location->X, this->location->Y);
}

void Fleet::setMove(float speed, float angle)
{
	//�]�w�t�׹L��
	if (speed > this->maxSpeed)
	{
		speed = this->maxSpeed;
		System::Diagnostics::Debug::WriteLine("�W�X�̤j���ʳt�סA�j��t");
	}
	this->speed = speed;
	this->angle = angle;
}
