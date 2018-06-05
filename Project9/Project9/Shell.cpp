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
	//不可以直接指派pos的值，否則指標一樣，船隻和砲彈的座標就會變同一個記憶體存儲。
	this->location = gcnew PointF(pos->X, pos->Y);
	this->targetLocation = target;
}

void Shell::Draw(Graphics ^ g)
{
	//畫圓
	float size = 10;
	g->FillPie(Brushes::Black,
		this->location->X - size / 2,
		this->location->Y - size / 2,
		size, size, 0.0, 360.0);
	//畫名字
	g->DrawString(this->name,
		gcnew Font("Arial", 12),
		Brushes::Black,
		this->location->X + 10,
		this->location->Y - 20);
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
		//this->Boom();
	}
	//還沒到點，移動分量
	else
	{
		this->location->X += this->speed * X / D;
		this->location->Y += this->speed * Y / D;
	}
}
