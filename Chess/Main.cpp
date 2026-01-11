#include "Main.h"

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
	// use smart pointers to hold polymorphic pieces without slicing
	std::vector<std::unique_ptr<Piece>> wPieces, bPieces;

	// create pieces (team: -1 = white, 1 = black)
	for (int i = 0; i < 8; ++i) {
		wPieces.emplace_back(std::make_unique<Pawn>(-1, 1, i));
	}
	wPieces.emplace_back(std::make_unique<Rook>(-1, 0, 0));
	wPieces.emplace_back(std::make_unique<Rook>(-1, 0, 7));

	wPieces.emplace_back(std::make_unique<Knight>(-1, 0, 1));
	wPieces.emplace_back(std::make_unique<Knight>(-1, 0, 6));
	
	wPieces.emplace_back(std::make_unique<Bishop>(-1, 0, 2));
	wPieces.emplace_back(std::make_unique<Bishop>(-1, 0, 5));
	
	wPieces.emplace_back(std::make_unique<Queen>(-1, 0, 3));
	wPieces.emplace_back(std::make_unique<King>(-1, 0, 4));
	

	for (int i = 0; i < 8; ++i) {
		bPieces.emplace_back(std::make_unique<Pawn>(1, 6, i));
	}
	bPieces.emplace_back(std::make_unique<Rook>(-1, 7, 0));
	bPieces.emplace_back(std::make_unique<Rook>(-1, 7, 7));

	bPieces.emplace_back(std::make_unique<Knight>(-1, 7, 1));
	bPieces.emplace_back(std::make_unique<Knight>(-1, 7, 6));

	bPieces.emplace_back(std::make_unique<Bishop>(-1, 7, 2));
	bPieces.emplace_back(std::make_unique<Bishop>(-1, 7, 5));

	bPieces.emplace_back(std::make_unique<Queen>(-1, 7, 3));
	bPieces.emplace_back(std::make_unique<King>(-1, 7, 4));

	while (true)
	{	
		char pieceChar;
		int xPos, yPos;
		std::tie(pieceChar, xPos, yPos) = getInput();
		std::cout << "Piece: " << pieceChar << " to " << xPos << ", " << yPos << std::endl;
	}
	


	return 0;
}