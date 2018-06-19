#pragma once

#ifndef Shell_H
#define Shell_H


using namespace System::Drawing;

ref class Fleet;

ref class Shell
{
public:
	Shell();
	Shell(System::String ^ ID, float speed,int damage, System::Drawing::PointF ^ pos, System::Drawing::PointF ^ target);
	~Shell();

	virtual void Draw(Graphics ^ g);
	virtual void Move();
	virtual void collision(System::Collections::Generic::Dictionary<System::String ^, Fleet ^>^ fleetList);
	bool getIsBoom();
	int getDamage();
	PointF ^ getLocation();
	System::String ^ getName();
	static int ID = 0;
protected:
	System::String ^ name;	//砲彈名字
	float speed;	//砲彈速度
	int damage;
	System::Drawing::PointF ^ location;	//目前位置
	System::Drawing::PointF ^ targetLocation;	//目標位置
	bool isBoom;	//要爆了沒
};

#endif
