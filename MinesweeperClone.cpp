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
	char myBoard[MAXSIDE][MAXSIDE];
	char realBoard[MAXSIDE][MAXSIDE];
	int mine[MAXMINES][2];

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
	void InitializeBoards() {
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				myBoard[i][j] = realBoard[i][j] = '-';
			}
		}
	}
	// Function for placing mines
	void PlaceMines() {
		bool mark[MAXSIDE * MAXSIDE];
		memset(mark, false, sizeof(mark));

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
	// Function for counting adjacent mines
	int CountAdjacentMines(int row, int col) {
		int count = 0;

		if (isValid(row, col - 1)) {
			if (isMine(row, col - 1, realBoard)) {
				count++;
			}
		}
		if (isValid(row, col + 1)) {
			if (isMine(row, col + 1, realBoard)) {
				count++;
			}
		}
		if (isValid(row + 1, col)) {
			if (isMine(row + 1, col, realBoard)) {
				count++;
			}
		}
		if (isValid(row - 1, col)) {
			if (isMine(row - 1, col, realBoard)) {
				count++;
			}
		}
		if (isValid(row - 1, col - 1)) {
			if (isMine(row - 1, col - 1, realBoard)) {
				count++;
			}
		}
		if (isValid(row + 1, col + 1)) {
			if (isMine(row + 1, col + 1, realBoard)) {
				count++;
			}
		}
		if (isValid(row + 1, col - 1)) {
			if (isMine(row + 1, col - 1, realBoard)) {
				count++;
			}
		}
		if (isValid(row - 1, col + 1)) {
			if (isMine(row - 1, col + 1, realBoard)) {
				count++;
			}
		}
		return count;
	}
	// Function for gameloop
	bool Gameloop(int row, int col, int *movesLeft) {
		// Base case
		if (myBoard[row][col] != '-')
			return false;

		if (realBoard[row][col] == '*') {
			myBoard[row][col] = '*';

			for (int i = 0; i < mines; i++) {
				myBoard[mine[i][0]][mine[i][1]] = '*';
			}

			printBoard(myBoard);
			cout << "You lost!" << endl;
			return true;
		}
		else
		{
			int count = CountAdjacentMines(row, col);
			(*movesLeft)--;

			myBoard[row][col] = count + '0';

			// If no mines are nearby, we recur for all adjacent 8 cells
			if (!count) {

				if (isValid(row, col - 1)) {
					if (isMine(row, col, realBoard) == false) {
						Gameloop(row, col - 1, movesLeft);
					}
				}
				if (isValid(row, col + 1)) {
					if (isMine(row, col + 1, realBoard) == false) {
						Gameloop(row, col + 1, movesLeft);
					}
				}
				if (isValid(row + 1, col)) {
					if (isMine(row + 1, col, realBoard) == false) {
						Gameloop(row + 1, col, movesLeft);
					}
				}
				if (isValid(row - 1, col)) {
					if (isMine(row - 1, col, realBoard) == false) {
						Gameloop(row - 1, col, movesLeft);
					}
				}
				if (isValid(row - 1, col + 1)) {
					if (isMine(row - 1, col + 1, realBoard) == false) {
						Gameloop(row - 1, col + 1, movesLeft);
					}
				}
				if (isValid(row - 1, col - 1)) {
					if (isMine(row - 1, col - 1, realBoard) == false) {
						Gameloop(row - 1, col - 1, movesLeft);
					}
				}
				if (isValid(row + 1, col - 1)) {
					if (isMine(row + 1, col - 1, realBoard) == false) {
						Gameloop(row + 1, col - 1, movesLeft);
					}
				}
				if (isValid(row + 1, col + 1)) {
					if (isMine(row + 1, col + 1, realBoard) == false) {
						Gameloop(row + 1, col + 1, movesLeft);
					}
				}
			}
		}
	}
	// Function for gameplay
	void PlayMineSweeper() {
		bool gameOver = false;

		int movesLeft = side * side - mines;
		int x, y;

		int mines[MAXMINES][2]; //For storing coordinates of all the mines

		InitializeBoards();

		PlaceMines();

		printBoard(myBoard);
	}
};
int main() {
	MineSweeperGame game;
	game.ChooseDifficulty();
	game.PlayMineSweeper();
	return 0;
}