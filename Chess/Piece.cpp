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

bool Piece::isOccupied(int xPosition, int yPosition, char board[8][8]) {

	if (board[yPosition][xPosition] == '.') {
		return IS_EMPTY;
	}
	else {
		// determine if ally or enemy
		// For simplicity, let's assume uppercase letters are white pieces and lowercase are black pieces
		if ((team == -1 && std::isupper(board[yPosition][xPosition])) ||
			(team == 1 && std::islower(board[yPosition][xPosition]))) {
			return IS_ALLY;
		}
		else {
			return IS_ENEMY;
		}
	}
}


bool Piece::isValidMove(int xPosition, int yPosition, char board[8][8]) {
	int xDt = this->xPosition - xPosition;
	int yDt = this->yPosition - yPosition;
	if (this->repeatable){
		for (std::vector<int>& r : this->rules) {
			int tempX = this->xPosition;
			int tempY = this->yPosition;

			while (true) {
				tempX += r[0];
				tempY += r[1] * team;

				xDt = tempX-xPosition;
				yDt = tempY-yPosition;

				if (isOccupied(xPosition, yPosition, board) == IS_ALLY ||
					tempX < 0 || tempX >= 8 || tempY < 0 || tempY >= 8)
				{
					break;
				}
				else if (xDt == r[0] && yDt == r[1] * team) {
					return true;
				}
			}
		}
		return false;
	}
	else {
		for (std::vector<int> &r : this->rules) {
			if (xDt == r[0] && yDt == r[1] * team && isOccupied(xPosition, yPosition, board) != IS_ALLY 
				&&  (r[2] == isOccupied(xPosition, yPosition, board) || r[2] == EMPTY_OR_ENEMY)) {
				return true;
			}
		}
		return false;
	}
	
}
