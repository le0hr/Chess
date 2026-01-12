#pragma once
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include <iostream>
#include <memory>
#include <vector>

class Board
{
public:
	Board();
	int isOccupied(int xPosition, int yPosition, int team);
	void renderBoard();

	std::vector<std::unique_ptr<Piece>> wPieces, bPieces;
	
private:
	char board[8][8] = { {'.', '.', '.', '.', '.', '.', '.', '.'},
						{'.', '.', '.', '.', '.', '.', '.', '.'},
						{'.', '.', '.', '.', '.', '.', '.', '.'},
						{'.', '.', '.', '.', '.', '.', '.', '.'},
						{'.', '.', '.', '.', '.', '.', '.', '.'},
						{'.', '.', '.', '.', '.', '.', '.', '.'},
						{'.', '.', '.', '.', '.', '.', '.', '.'},
						{'.', '.', '.', '.', '.', '.', '.', '.'}, };


};

