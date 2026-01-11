#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(int team, int xPosition, int yPosition);
	~King();
private:
	int repeatable;
};