#include "Piece.h"
#include "King.h"

King::King(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{1, 1, stateCondition::IS_NOT_ALLY}, {1, -1, stateCondition::IS_NOT_ALLY},
		{-1, 1, stateCondition::IS_NOT_ALLY}, {-1, -1, stateCondition::IS_NOT_ALLY},
		{-1, 0, stateCondition::IS_NOT_ALLY}, {1, 0, stateCondition::IS_NOT_ALLY},
		{0, 1, stateCondition::IS_NOT_ALLY}, {0, -1, stateCondition::IS_NOT_ALLY}
	};
	this->team = team;
	this->repeatable = false;
}

King::~King() {}