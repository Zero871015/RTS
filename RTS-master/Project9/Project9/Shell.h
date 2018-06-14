#pragma once
using namespace System::Drawing;

ref class Shell
{
public:
	Shell();
	Shell(System::String ^ ID, float speed,int damage, System::Drawing::PointF ^ pos, System::Drawing::PointF ^ target);
	~Shell();

	void Draw(Graphics ^ g);
	void Move();
	bool getIsBoom();
	int getDamage();
	PointF ^ getLocation();
	System::String ^ getName();
	static int ID = 0;
private:
	System::String ^ name;	//砲彈名字
	float speed;	//砲彈速度
	int damage;
	System::Drawing::PointF ^ location;	//目前位置
	System::Drawing::PointF ^ targetLocation;	//目標位置
	bool isBoom;	//要爆了沒
};

