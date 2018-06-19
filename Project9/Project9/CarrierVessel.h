#pragma once
#include "Fleet.h"
ref class CarrierVessel :public Fleet
{
public:
	CarrierVessel(System::String ^ name, System::Drawing::PointF ^ location);
	bool specialAttack(System::Collections::Generic::List<Shell^>^ list, Fleet ^ target) override;
};

