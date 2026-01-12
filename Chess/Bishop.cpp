#include "Bishop.h"

Bishop::Bishop(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{1, 1, stateCondition::EMPTY_OR_ENEMY}, {1, -1, stateCondition::EMPTY_OR_ENEMY},
		{-1, 1, stateCondition::EMPTY_OR_ENEMY}, {-1, -1, stateCondition::EMPTY_OR_ENEMY}
	};
	this->team = team;
	this->repeatable = true;
}

Bishop::~Bishop() {}