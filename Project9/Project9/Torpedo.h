#pragma once
#include "Shell.h"

ref class Fleet;

ref class Torpedo :public Shell
{
public:
	Torpedo(System::Drawing::PointF ^ pos,float angle, System::String ^ name);
	void Move() override;
	void Draw(Graphics ^ g) override;
	void collision(System::Collections::Generic::Dictionary<System::String ^, Fleet ^>^ fleetList) override;
private:
	float angle;
	float speed;
	System::String ^ fleetName;
};

