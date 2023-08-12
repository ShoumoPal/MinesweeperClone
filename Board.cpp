#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace std;


//Getters and Setters
int Board::GetMines() {
	return mines;
}
int Board::GetSide() {
	return side;
}
void Board::SetSide(int _side) {
	side = _side;
}
void Board::SetMines(int _mines) {
	mines = _mines;
}
// Function to print the board
void Board::PrintBoard() {
	cout << "    ";
	for (int i = 0; i < side; i++) {
		cout << setw(2) << i << " ";
	}
	cout << "\n\n";
	for (int i = 0; i < side; i++) {
		cout << setw(2) << i << "  ";
		for (int j = 0; j < side; j++) {
			cout << setw(2) << myBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----------------------------------------" << endl;
}
// Function to initialize the boards
void Board::InitializeBoards() {
	for (int i = 0; i < side; i++) {
		for (int j = 0; j < side; j++) {
			myBoard[i][j] = realBoard[i][j] = '-';
		}
	}
}

// Function for placing mines
void Board::PlaceMines() {
	bool mark[MAXSIDE * MAXSIDE];
	memset(mark, false, sizeof(mark));
	srand(time(0));

	int i = 0;
	while (i < mines) {
		int random = rand() % (side * side);
		int x = random / side;
		int y = random % side;

		if (mark[random] == false) {
			mine[i][0] = x;
			mine[i][1] = y;
			realBoard[mine[i][0]][mine[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}
}
// Function to find mine index
int Board::FindMineIndex(int row, int col) {
	for (int i = 0; i < mines; i++) {
		if (mine[i][0] == row && mine[i][1] == col)
			return i;
	}
	return -1;
}
// Function to replace mine
void Board::ReplaceMine(int row, int col) {
	for (int i = 0; i < side; i++) {
		for (int j = 0; j < side; j++) {
			if (realBoard[i][j] != '*') {
				realBoard[i][j] = '*';
				int mineIndex = FindMineIndex(row, col);
				mine[mineIndex][0] = i;
				mine[mineIndex][1] = j;
				realBoard[row][col] = '-';
				return;
			}
		}
	}
}