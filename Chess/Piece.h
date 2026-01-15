#pragma once
#include <vector>
#include <tuple>
#include <unordered_map>
#include <cctype>

class Piece
{
public:
	Piece(int xPosition, int yPosition);
	virtual ~Piece();
	void movePiece(int xPosition, int yPosition);
	std::tuple<int,int> getPosition();
	virtual bool isValidMove(int xPosition, int yPosition, char board[8][8]);
	bool isOccupied(int xPosition, int yPosition, char board[8][8]);

protected:
	int repeatable; // can move multiple times in one direction
	int xPosition;
	int yPosition;
	int team; // -1 = white, 1 = black

	std::vector<std::vector<int>> rules; // rule: {xChange, yChange, condition: {isEmpty:0, isEnemy:1, isAlly:-1}
};

enum stateCondition {
	IS_EMPTY = 0,
	IS_ENEMY = 1,
	IS_ALLY = -1,
	EMPTY_OR_ENEMY = 2
};