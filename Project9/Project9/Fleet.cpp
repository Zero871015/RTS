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
	//畫三角形
	array<PointF>^ curvePoints = { PointF(X,Y - size),
		PointF(X - size / 2 * sqrtf(3),Y + size / 2) ,
		PointF(X + size / 2 * sqrtf(3),Y + size / 2) };
	g->FillPolygon(Brushes::Black, curvePoints);

	//畫名字
	g->DrawString(this->name,
		gcnew Font("Arial", 12),
		Brushes::Black,
		X + 10,
		Y - 20);

	//測試用，標示出中心點
	g->DrawLine(Pens::Red, this->location->X, this->location->Y, this->location->X + 1, this->location->Y + 1);
}

void Fleet::Move()
{
	//計算X-Y分量
	float trueAngle=angle/180* (float)3.14159265;
	this->location->X += speed * cosf(trueAngle);
	this->location->Y -= speed * sinf(trueAngle);
	
	//目前在牆壁
	if (whereAmI() == WALL)
	{
		this->location->X -= speed * cosf(trueAngle);
		this->location->Y += speed * sinf(trueAngle);
		System::Diagnostics::Debug::WriteLine("撞牆");
		this->speed = 0;
		this->angle = 0;
	}
	else if (whereAmI() == SEA)
	{

	}
}

bool Fleet::Fire(System::Collections::Generic::List<Shell^>^ list, PointF ^ location)
{
	//新增砲彈，距離不夠要回傳false(還沒做)
	System::String ^ name;
	name = "Shell";
	name += Shell::ID;
	Shell ^temp = gcnew Shell(name, sheelSpeed, this->location, location);
	list->Add(temp);
	return true;
}

int Fleet::whereAmI()
{
	//回傳目前船艦在哪裡
	return Board::getBoard(this->location->X, this->location->Y);
}

void Fleet::setMove(float speed, float angle)
{
	//設定速度過快
	if (speed > this->maxSpeed)
	{
		speed = this->maxSpeed;
		System::Diagnostics::Debug::WriteLine("超出最大移動速度，強制降速");
	}
	this->speed = speed;
	this->angle = angle;
}
