#pragma once
#include "Fleet.h"
ref class FlyingMissileCruiser :public Fleet
{
public:
	FlyingMissileCruiser(System::String ^ name, System::Drawing::PointF ^ location);
	bool specialAttack(System::Collections::Generic::List<Shell^>^ list, float angle) override;
};

