#include "Bishop.h"

Bishop::Bishop(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{1, 1, stateCondition::IS_NOT_ALLY}, {1, -1, stateCondition::IS_NOT_ALLY},
		{-1, 1, stateCondition::IS_NOT_ALLY}, {-1, -1, stateCondition::IS_NOT_ALLY}
	};
	this->team = team;
	this->repeatable = true;
}

Bishop::~Bishop() {}