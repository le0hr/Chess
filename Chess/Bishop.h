#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(int team, int xPosition, int yPosition);
	~Bishop();
private:
	int repeatable;
};