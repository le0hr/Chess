#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(int team, int xPosition, int yPosition);
	~Knight();
private:
	int repeatable;
};