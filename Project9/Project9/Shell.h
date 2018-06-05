#pragma once

using namespace System::Drawing;

ref class Shell
{
public:
	Shell();
	Shell(System::String ^ ID, float speed, System::Drawing::PointF ^ pos, System::Drawing::PointF ^ target);

	void Draw(Graphics ^ g);
	void Move();
private:
	System::String ^ name;	//砲彈名字
	float speed;	//砲彈速度
	System::Drawing::PointF ^ location;	//目前位置
	System::Drawing::PointF ^ targetLocation;	//目標位置
};

