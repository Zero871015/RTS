#pragma once

using namespace System::Drawing;

enum BoardID {
	WALL,
	SEA,
	STORM,
	LASTNUM
};
ref class Board
{
public:
	Board();
	void Draw(Graphics^ g);
	static int getBoard(float x, float y);
	static int **map;
private:
};

