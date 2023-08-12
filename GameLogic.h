#pragma once
#include "PlayerInput.h"
#include "Tile.h"
#include "Board.h"

class GameLogic
{
public:
	void GameIntro();
	bool Gameloop(int, int, int*, Board*);
	void PlayMineSweeper(Board*);
	int CountAdjacentMines(int, int, Board*);
};

