#pragma once

using namespace System::Drawing;

enum BoardID {
	WALL,
	SEA,
	LASTNUM
};
ref class Board
{
public:
	Board();
	void Draw(Graphics^ g);
	static int getBoard(float x, float y);
private:
	static int **map;
};

