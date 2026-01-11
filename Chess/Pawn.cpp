#include "Pawn.h"


Pawn::Pawn(int team, int xPosition, int yPosition) :Piece(xPosition, yPosition) {
	this->rules = {
		{1, 0, stateCondition::IS_EMPTY},
		{1, -1, stateCondition::IS_ENEMY},
		{1, 1, stateCondition::IS_ENEMY }
	};
	this->team = team;
	this->repeatable = false;
}

Pawn::~Pawn() {}