#include "Board.h"

#define MAP_SIZE (20+2)

Board::Board()
{
	//��l�Ʀa�Ϥj�p
	this->map = new int*[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++)
	{
		map[i] = new int[MAP_SIZE];
	}

	//�]�w�a�ϸ��
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			//��ɳ]�w
			if (i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1)
			{
				map[i][j] = WALL;
			}
			//���v�]�w
			else
			{
				map[i][j] = SEA;
			}
		}
	}
}

void Board::Draw(Graphics^ g)
{
	const int boxSize = 20;
	//���
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (this->map[i][j] == WALL)
				g->FillRectangle(Brushes::Gray, i * boxSize, j * boxSize, boxSize, boxSize);
			else if(this->map[i][j]==SEA)
				g->FillRectangle(Brushes::AliceBlue, i * boxSize, j * boxSize, boxSize, boxSize);
		}
	}
	//�e�u
	for (int i = 0; i < MAP_SIZE + 1; i++)
	{
		for (int j = 0; j < MAP_SIZE + 1; j++)
		{
			g->DrawLine(Pens::Black, j * boxSize, 0, j * boxSize, MAP_SIZE * boxSize);
			g->DrawLine(Pens::Black, 0, i * boxSize, MAP_SIZE * boxSize, i * boxSize);
		}
	}

}

int Board::getBoard(float x, float y)
{
	return map[(int)x / 20][(int)y / 20];
}
