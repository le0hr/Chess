#include "Knight.h"

Knight::Knight(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{2, 1, stateCondition::EMPTY_OR_ENEMY}, {2, -1, stateCondition::EMPTY_OR_ENEMY},
		{-2, 1, stateCondition::EMPTY_OR_ENEMY}, {-2, -1, stateCondition::EMPTY_OR_ENEMY},
		{1, 2, stateCondition::EMPTY_OR_ENEMY}, {-1, 2, stateCondition::EMPTY_OR_ENEMY},
		{1, -2, stateCondition::EMPTY_OR_ENEMY}, {-1, -2, stateCondition::EMPTY_OR_ENEMY}
	};
	this->team = team;
	this->repeatable = false;
}

Knight::~Knight() {}
