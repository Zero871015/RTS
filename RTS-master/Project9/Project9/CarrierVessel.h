#pragma once
#include "Fleet.h"
ref class CarrierVessel :public Fleet
{
public:
	CarrierVessel::CarrierVessel(System::String ^ name, System::Drawing::PointF ^ location);
};

