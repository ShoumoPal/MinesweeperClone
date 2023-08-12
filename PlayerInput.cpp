#include "PlayerInput.h"
#include "Difficulty.h"
#include <iostream>

using namespace std;

//Function to make a move
void PlayerInput::MakeAMove(int* x, int* y) {
	cout << "Enter the x and y co-ordinates: " << endl;
	cin >> *x >> *y;
}
// Function to validate user input
bool PlayerInput::isValid(int _row, int _col, Board *board) {
	return (((_row >= 0) && (_row < board->GetSide())) && (_col >= 0) && (_col < board->GetSide()));
}
// For choosing difficulty level
void PlayerInput::ChooseDifficulty(Board *board) {
	int level;

	cout << "Enter the difficulty level: " << endl;
	cout << "Enter '0' for Easy( 9x9 board with 10 mines )" << endl;
	cout << "Enter '1' for Intermediate( 16x16 board with 40 mines )" << endl;
	cout << "Enter '2' for Hard( 24x24 board with 99 mines )" << endl;

	cin >> level;

	if (level == Difficulty::Easy) {
		board->SetSide(9);
		board->SetMines(10);
	}
	else if (level == Difficulty::Intermediate) {
		board->SetSide(16);
		board->SetMines(40);
	}
	else if (level == Difficulty::Hard) {
		board->SetSide(24);
		board->SetMines(99);
	}
}
