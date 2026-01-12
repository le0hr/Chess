#include "Piece.h"
#include "King.h"

King::King(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{1, 1, stateCondition::EMPTY_OR_ENEMY}, {1, -1, stateCondition::EMPTY_OR_ENEMY},
		{-1, 1, stateCondition::EMPTY_OR_ENEMY}, {-1, -1, stateCondition::EMPTY_OR_ENEMY},
		{-1, 0, stateCondition::EMPTY_OR_ENEMY}, {1, 0, stateCondition::EMPTY_OR_ENEMY},
		{0, 1, stateCondition::EMPTY_OR_ENEMY}, {0, -1, stateCondition::EMPTY_OR_ENEMY}
	};
	this->team = team;
	this->repeatable = false;
}

King::~King() {}