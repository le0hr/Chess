#include "Rook.h"

Rook::Rook(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{1, 0, stateCondition::IS_NOT_ALLY}, {-1, 0, stateCondition::IS_NOT_ALLY},
		{0, 1, stateCondition::IS_NOT_ALLY}, {0, -1, stateCondition::IS_NOT_ALLY}
	};
	this->team = team;
	this->repeatable = true;
}

Rook::~Rook() {}