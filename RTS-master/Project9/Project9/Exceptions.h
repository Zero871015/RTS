#pragma once
using namespace System;

ref class Exceptions : public Exception
{
private:
	int type;
public:
	array<String ^>^ text;
	Exceptions();
	int getType();
	Exceptions(array<String ^>^, int);
};

enum error { blankLine, errorCommand, errorSET, errorFIRE, errorDEFENSE, errorTAG, errorMOVE };
