#include "Pawn.h"


Pawn::Pawn(int team, int xPosition, int yPosition) :Piece(xPosition, yPosition) {
	this->rules = {
		{0, 1, stateCondition::IS_EMPTY},
		{0, 2, stateCondition::IS_EMPTY},
		{-1, 1, stateCondition::IS_ENEMY},
		{1, 1, stateCondition::IS_ENEMY },

	};
	this->team = team;
	this->repeatable = false;
}

Pawn::~Pawn() {}