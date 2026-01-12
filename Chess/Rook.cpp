#include "Rook.h"

Rook::Rook(int team, int xPosition, int yPosition) : Piece(xPosition, yPosition) {
	this->rules = {
		{1, 0, stateCondition::EMPTY_OR_ENEMY}, {-1, 0, stateCondition::EMPTY_OR_ENEMY},
		{0, 1, stateCondition::EMPTY_OR_ENEMY}, {0, -1, stateCondition::EMPTY_OR_ENEMY}
	};
	this->team = team;
	this->repeatable = true;
}

Rook::~Rook() {}