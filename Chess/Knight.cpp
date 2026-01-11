#include "Knight.h"

Knight::Knight(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{2, 1, stateCondition::IS_NOT_ALLY}, {2, -1, stateCondition::IS_NOT_ALLY},
		{-2, 1, stateCondition::IS_NOT_ALLY}, {-2, -1, stateCondition::IS_NOT_ALLY},
		{1, 2, stateCondition::IS_NOT_ALLY}, {-1, 2, stateCondition::IS_NOT_ALLY},
		{1, -2, stateCondition::IS_NOT_ALLY}, {-1, -2, stateCondition::IS_NOT_ALLY}
	};
	this->team = team;
	this->repeatable = false;
}

Knight::~Knight() {}
