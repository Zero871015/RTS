#pragma once

#ifndef Fleet_H
#define Fleet_H


#include "Shell.h"
#include "Board.h"
using namespace System::Drawing;

ref class Fleet
{
public:
	Fleet();
	Fleet(System::String ^ name, System::Drawing::PointF ^ location);
	void Draw(Graphics^ g,System::Drawing::Color color);
	void DrawBig(Graphics^ g);
	virtual void Move();
	bool Fire(System::Collections::Generic::List<Shell^>^ list, System::String ^,PointF ^ location);
	int whereAmI();
	bool setMove(float speed, float angle);
	float getShellSpeed();
	void setName(System::String ^);
	PointF ^ getLocation();
	void setHP(int);
	int getHP();
	System::String ^ getName();
	System::String ^ showAttackCD();
	System::String ^ showDefenseCD();
	System::String ^ showSpecialCD();
	void UpdataCD();
	bool Defense(System::String ^ shellName, System::Collections::Generic::List<Shell^>^ list);
	void SetDefenseCD();
	bool isDrawBig;
	int whoAmI();

	virtual bool specialAttack(System::Collections::Generic::List<Shell^>^ list, float angle);	//魚雷
	virtual bool specialAttack();	//防護罩
	virtual bool specialAttack(System::Collections::Generic::List<Shell^>^ list, Fleet ^ target);	//飛機
protected:
	System::String ^ name;	//船艦名字
	int type;	//船艦種類(之後用繼承可能移除)
	System::Drawing::PointF ^ location;	//目前位置

	int HP;	//船艦血量
	float maxSpeed;	//最大移動速度
	float speed;	//目前移動速度
	float angle;	//目前移動角度
	int maxAttackRange;	//船艦最大攻擊距離
	int attackCD;	//攻擊冷卻
	int attackCDNow;	//攻擊冷卻計數
	int maxDefenseRange;	//船艦最大防禦距離
	int defenseCD;	//防禦冷卻
	int defenseCDNow;	//防禦冷卻計數
	int damage;	//發射的砲彈傷害
	float shellSpeed;	//發射的砲彈速度
	int specialCD;	//特殊攻擊冷卻
	int specialCDNow;	//特殊攻擊冷卻計數
};

#endif
