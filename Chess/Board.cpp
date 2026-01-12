#include "Board.h"
Board::Board() {
	// create pieces (team: -1 = white, 1 = black)
	for (int x = 0; x < 8; ++x) {
		wPieces.emplace_back(std::make_unique<Pawn>(-1, x, 1));
	}
	wPieces.emplace_back(std::make_unique<Rook>(-1, 0, 0));
	wPieces.emplace_back(std::make_unique<Rook>(-1, 7, 0));

	wPieces.emplace_back(std::make_unique<Knight>(-1, 1, 0));
	wPieces.emplace_back(std::make_unique<Knight>(-1, 6, 0));

	wPieces.emplace_back(std::make_unique<Bishop>(-1, 2, 0));
	wPieces.emplace_back(std::make_unique<Bishop>(-1, 5, 0));

	wPieces.emplace_back(std::make_unique<Queen>(-1, 3, 0));
	wPieces.emplace_back(std::make_unique<King>(-1, 4, 0));


	for (int x = 0; x < 8; ++x) {
		bPieces.emplace_back(std::make_unique<Pawn>(1, x, 6));
	}
	bPieces.emplace_back(std::make_unique<Rook>(1, 0, 7));
	bPieces.emplace_back(std::make_unique<Rook>(1, 7, 7));

	bPieces.emplace_back(std::make_unique<Knight>(1, 1, 7));
	bPieces.emplace_back(std::make_unique<Knight>(1, 6, 7));

	bPieces.emplace_back(std::make_unique<Bishop>(1, 2, 7));
	bPieces.emplace_back(std::make_unique<Bishop>(1, 5, 7));

	bPieces.emplace_back(std::make_unique<Queen>(1, 3, 7));
	bPieces.emplace_back(std::make_unique<King>(1, 4, 7));
}
int Board::isOccupied(int xPosition, int yPosition, int team) {
	for (const auto& piece : this->wPieces) {
		int px, py;
		std::tie(px, py) = piece->getPosition();
		if (px == xPosition && py == yPosition) {
			return (team == -1) ? IS_ALLY : IS_ENEMY;
		}
	}
	for (const auto& piece : this->bPieces) {
		int px, py;
		std::tie(px, py) = piece->getPosition();
		if (px == xPosition && py == yPosition) {
			return (team == 1) ? IS_ALLY : IS_ENEMY;
		}
	}
	return IS_EMPTY;
}

void Board::renderBoard() {
	// reset board
	for (int y = 0; y < 8; ++y) {
		for (int x = 0; x < 8; ++x) {
			board[y][x] = '.';
		}
	}
	// place white pieces
	for (const auto& piece : this->wPieces) {
		int px, py;
		std::tie(px, py) = piece->getPosition();
		char symbol = 'W';
		if (dynamic_cast<Pawn*>(piece.get())) symbol = 'P';
		else if (dynamic_cast<Rook*>(piece.get())) symbol = 'R';
		else if (dynamic_cast<Knight*>(piece.get())) symbol = 'N';
		else if (dynamic_cast<Bishop*>(piece.get())) symbol = 'B';
		else if (dynamic_cast<Queen*>(piece.get())) symbol = 'Q';
		else if (dynamic_cast<King*>(piece.get())) symbol = 'K';
		board[py][px] = symbol;
	}
	// place black pieces
	for (const auto& piece : this->bPieces) {
		int px, py;
		std::tie(px, py) = piece->getPosition();
		char symbol = 'b';
		if (dynamic_cast<Pawn*>(piece.get())) symbol = 'p';
		else if (dynamic_cast<Rook*>(piece.get())) symbol = 'r';
		else if (dynamic_cast<Knight*>(piece.get())) symbol = 'n';
		else if (dynamic_cast<Bishop*>(piece.get())) symbol = 'b';
		else if (dynamic_cast<Queen*>(piece.get())) symbol = 'q';
		else if (dynamic_cast<King*>(piece.get())) symbol = 'k';
		board[py][px] = symbol;
	}
	// print board
	for (int y = 7; y >= 0; --y) {
		for (int x = 0; x < 8; ++x) {
			std::cout << board[y][x] << ' ';
		}
		std::cout << std::endl;
	}
}