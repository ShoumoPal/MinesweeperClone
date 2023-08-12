#pragma once


#define MAXMINES 99
#define MAXSIDE 25

class Board
{
private:
	int mines;
	int side;

public:
	int mine[MAXMINES][2];
	char myBoard[MAXSIDE][MAXSIDE];
	char realBoard[MAXSIDE][MAXSIDE];

	void PrintBoard();
	void InitializeBoards();
	int GetMines();
	int GetSide();
	void SetSide(int);
	void SetMines(int);
	void PlaceMines();
	void ReplaceMine(int, int);
	int FindMineIndex(int, int);
};

