#include <iostream>
#include <iomanip>

using namespace std;

#define MAXSIDE 25
#define MAXMINES 99

//Enum for difficulty
enum Difficulty { 
	Easy,
	Intermediate,
	Hard
};

class MineSweeperGame {
private:
	int side;
	int mines;
	char board[][MAXSIDE];

public:
	// Function to validate user input
	bool isValid(int _row, int _col) {
		return (((_row >= 0) && (_row < side)) && (_col >= 0) && (_col < side));
	}
	// Function to validate mine at position given
	bool isMine(int _row, int _col, char board[][MAXSIDE]) {
		return board[_row][_col] == '*';
	}
	// Function to print the board
	void printBoard(char board[][MAXSIDE]) {
		cout << "    ";
		for (int i = 0; i < side; i++) {
			cout << setw(2) << i << " ";
		}
		cout << "\n\n";
		for (int i = 0; i < side; i++) {
			cout << setw(2) << i << "  ";
			for (int j = 0; j < side; j++) {
				cout << setw(2) << board[i][j] << " ";
			}
			cout << endl;
		}
	}	
	// For choosing difficulty level
	void ChooseDifficulty() {
		int level;

		cout << "Enter the difficulty level: " << endl;
		cout << "Enter '0' for Easy( 9x9 board with 10 mines )" << endl;
		cout << "Enter '1' for Intermediate( 16x16 board with 40 mines )" << endl;
		cout << "Enter '2' for Easy( 24x24 board with 99 mines )" << endl;

		cin >> level;

		if (level == Difficulty::Easy) {
			side = 9;
			mines = 10;
		}
		else if (level == Difficulty::Intermediate) {
			side = 16;
			mines = 40;
		}
		else if (level == Difficulty::Hard) {
			side = 24;
			mines = 99;
		}
	}
	// Function to initialize the boards
	void InitializeBoards(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]) {
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				myBoard[i][j] = realBoard[i][j] = '-';
			}
		}
	}
	// Function for gameplay
	void PlayMineSweeper() {
		bool gameOver = false;

		char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];

		int movesLeft = side * side - mines;
		int x, y;

		int mines[MAXMINES][2]; //For storing coordinates of all the mines

		InitializeBoards(realBoard, myBoard);

		printBoard(myBoard);
	}
};
int main() {
	MineSweeperGame game;
	game.ChooseDifficulty();
	game.PlayMineSweeper();
	return 0;
}