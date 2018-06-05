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
	System::String ^ name;	//���u�W�r
	float speed;	//���u�t��
	System::Drawing::PointF ^ location;	//�ثe��m
	System::Drawing::PointF ^ targetLocation;	//�ؼЦ�m
};

