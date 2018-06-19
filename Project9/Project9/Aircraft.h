#pragma once
#include "Shell.h"
ref class Aircraft : public Shell
{
public:
	Aircraft(System::Drawing::PointF ^ pos, Fleet ^ target, float VX, float VY);
	void Move() override;
	void Aircraft::Draw(Graphics ^ g) override;
private:
	float VX, VY;
	float AX, AY;
	Fleet ^ target;
};

