#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(int team, int xPosition, int yPosition);
	~Rook();
private:
	int repeatable;
};