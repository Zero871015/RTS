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
	System::String ^ name;	//���u�W�r
	float speed;	//���u�t��
	int damage;
	System::Drawing::PointF ^ location;	//�ثe��m
	System::Drawing::PointF ^ targetLocation;	//�ؼЦ�m
	bool isBoom;	//�n�z�F�S
};

