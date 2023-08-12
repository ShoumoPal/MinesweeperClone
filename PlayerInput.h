#pragma once

#include "Board.h"

class PlayerInput
{
public:
	static void MakeAMove(int*, int*);
	static void ChooseDifficulty(Board*);
	static bool isValid(int, int, Board*);
};

