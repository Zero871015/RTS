#pragma once
#include "Fleet.h"
ref class Destroyer :public Fleet
{
public:
	Destroyer(System::String ^ name, System::Drawing::PointF ^ location);
	bool specialAttack(System::Collections::Generic::List<Shell^>^ list,float angle) override;
};

