#pragma once
#include "Fleet.h"
ref class BB :public Fleet
{
public:
	BB(System::String ^ name, System::Drawing::PointF ^ location);
	bool specialAttack() override;
	void Move() override;
	int bufferHP;
	int clock;
};

