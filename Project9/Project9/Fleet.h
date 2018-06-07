#pragma once
#include "Shell.h"
#include "Board.h"
using namespace System::Drawing;

ref class Fleet
{
public:
	Fleet();
	Fleet(System::String ^ name, System::Drawing::PointF ^ location);
	void Draw(Graphics^ g);
	void Move();
	bool Fire(System::Collections::Generic::List<Shell^>^ list,PointF ^ location);
	int whereAmI();
	void setMove(float speed, float angle);
	float getSheelSpeed();
	PointF ^ getLocation();
private:
	System::String ^ name;	//船艦名字
	int type;	//船艦種類(之後用繼承可能移除)
	System::Drawing::PointF ^ location;	//目前位置

	int HP;	//船艦血量
	float maxSpeed;	//最大移動速度
	float speed;	//目前移動速度
	float angle;	//目前移動角度
	int maxAttackRange;	//船艦最大攻擊距離
	int attackCD;	//攻擊冷卻
	int maxDefenseRange;	//船艦最大防禦距離
	int defenseCD;	//防禦冷卻
	int damage;	//發射的砲彈傷害
	float sheelSpeed;	//發射的砲彈速度
};

