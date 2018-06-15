#include "Exceptions.h"



Exceptions::Exceptions()
{
}

int Exceptions::getType()
{
	return type;
}

Exceptions::Exceptions(array<String^>^ text, int type)
{
	this->type = type;
	this->text = text;
}
