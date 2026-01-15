#include "Main.h"
#include <cstdlib>

std::tuple<char, int, int> getInput() {
	std::string in;
	std::cin >> in;
	
	if (in.length() == 2) {
		return std::make_tuple('P', in[0] - 'a', in[1] - '1');
	}
	else {
		return std::make_tuple(in[0], in[1] - 'a', in[2] - '1');
	}
}

int main() {
	Board board;


	while (true)
	{	
		board.renderBoard();
		board.displayBoard();

		while (true) {
			char pieceChar;
			int xPos, yPos;
			bool isValidMove = 0;
			std::tie(pieceChar, xPos, yPos) = getInput();
			for (auto& piece : board.wPieces) {
				if ((pieceChar == 'P' && dynamic_cast<Pawn*>(piece.get())) ||
					(pieceChar == 'R' && dynamic_cast<Rook*>(piece.get())) ||
					(pieceChar == 'N' && dynamic_cast<Knight*>(piece.get())) ||
					(pieceChar == 'B' && dynamic_cast<Bishop*>(piece.get())) ||
					(pieceChar == 'Q' && dynamic_cast<Queen*>(piece.get())) ||
					(pieceChar == 'K' && dynamic_cast<King*>(piece.get()))) {
					if (piece->isValidMove(xPos, yPos, board.board)) {
						piece->movePiece(xPos, yPos);
						isValidMove = 1;
						break;
					}

				}
			}
			if (isValidMove) {
				break;
			}
			else {
				std::cout << "Invalid move, try again." << std::endl;
			}
		}

		board.renderBoard();
		board.displayBoard();

		while (true)
		{
			char pieceChar;
			int xPos, yPos;
			bool isValidMove = 0;
			std::tie(pieceChar, xPos, yPos) = getInput();
			for (auto& piece : board.bPieces) {
				if ((pieceChar == 'P' && dynamic_cast<Pawn*>(piece.get())) ||
					(pieceChar == 'R' && dynamic_cast<Rook*>(piece.get())) ||
					(pieceChar == 'N' && dynamic_cast<Knight*>(piece.get())) ||
					(pieceChar == 'B' && dynamic_cast<Bishop*>(piece.get())) ||
					(pieceChar == 'Q' && dynamic_cast<Queen*>(piece.get())) ||
					(pieceChar == 'K' && dynamic_cast<King*>(piece.get()))) {
					if (piece->isValidMove(xPos, yPos, board.board)) {
						piece->movePiece(xPos, yPos);
						isValidMove = 1;
						break;
					}

				}
			}
			if (isValidMove) {
				break;
			}
			else {
				std::cout << "Invalid move, try again." << std::endl;
			}
		}

	}
	
	// TODO: implement check, checkmate, stalemate, castling, promotion, non-repeatable pawn move

	return 0;
}