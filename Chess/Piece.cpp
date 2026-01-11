#include "Piece.h"

Piece::Piece(int xPosition, int yPosition) {
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->team = 0;
}

Piece::~Piece() {}

void Piece::movePiece(int xPosition, int yPosition) {
	if (xPosition >= 0 && xPosition < 8 && yPosition >= 0 && yPosition < 8) {
		this->xPosition = xPosition;
		this->yPosition = yPosition;
	}
}

std::tuple<int,int> Piece::getPosition() {
	return std::tuple<int, int>(this->xPosition, this->yPosition);
}

bool Piece::isValidMove(int xPosition, int yPosition, int isCupture) {
	int xDt = this->xPosition - xPosition;
	int yDt = this->yPosition - yPosition;
	for (std::vector<int> &r : this->rules) {
		if (xDt == r[0] && yDt == r[1] && isCupture == r[2]) {
			return true;
		}
	}
	return false;
}
