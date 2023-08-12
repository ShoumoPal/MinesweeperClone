#include "GameLogic.h"
#include <iostream>


using namespace std;

Tile tile;

// Function for introduction message
void GameLogic::GameIntro() {
	cout << "========================================" << endl;
	cout << "||                                    || " << endl;
	cout << "||            MINESWEEPER             || " << endl;
	cout << "||                                    || " << endl;
	cout << "========================================\n" << endl;

	cout << "Rules: " << endl;
	cout << "1. Board is divided into cells with mines randomly distributed\n2. To win, you will need to open all cells without triggering the mines\n3. Number on the cell denotes the number of mines adjacent to it\n4. Contains 3 diificulty levels\n5. Have fun and enjoy!\n" << endl;
	cout << "----------------------------------------" << endl;
}

// Function for gameloop
bool GameLogic::Gameloop(int row, int col, int* movesLeft, Board *board) {
	// Base case
	if (board->myBoard[row][col] != '-')
		return false;

	if (board->realBoard[row][col] == '*') {
		board->myBoard[row][col] = '*';

		for (int i = 0; i < board->GetMines(); i++) {
			board->myBoard[board->mine[i][0]][board->mine[i][1]] = '*';
		}

		board->PrintBoard();
		cout << "You lost!" << endl;
		return true;
	}
	else
	{
		int count = GameLogic::CountAdjacentMines(row, col, board);
		(*movesLeft)--;

		board->myBoard[row][col] = count + '0';

		// If no mines are nearby, we recur for all adjacent 8 cells
		if (!count) {

			if (PlayerInput::isValid(row, col - 1, board)) {
				if (tile.isMine(row, col, board) == false) {
					Gameloop(row, col - 1, movesLeft, board);
				}
			}
			if (PlayerInput::isValid(row, col + 1, board)) {
				if (tile.isMine(row, col + 1, board) == false) {
					Gameloop(row, col + 1, movesLeft, board);
				}
			}
			if (PlayerInput::isValid(row + 1, col, board)) {
				if (tile.isMine(row + 1, col, board) == false) {
					Gameloop(row + 1, col, movesLeft, board);
				}
			}
			if (PlayerInput::isValid(row - 1, col, board)) {
				if (tile.isMine(row - 1, col, board) == false) {
					Gameloop(row - 1, col, movesLeft, board);
				}
			}
			if (PlayerInput::isValid(row - 1, col + 1, board)) {
				if (tile.isMine(row - 1, col + 1, board) == false) {
					Gameloop(row - 1, col + 1, movesLeft, board);
				}
			}
			if (PlayerInput::isValid(row - 1, col - 1, board)) {
				if (tile.isMine(row - 1, col - 1, board) == false) {
					Gameloop(row - 1, col - 1, movesLeft, board);
				}
			}
			if (PlayerInput::isValid(row + 1, col - 1, board)) {
				if (tile.isMine(row + 1, col - 1, board) == false) {
					Gameloop(row + 1, col - 1, movesLeft, board);
				}
			}
			if (PlayerInput::isValid(row + 1, col + 1, board)) {
				if (tile.isMine(row + 1, col + 1, board) == false) {
					Gameloop(row + 1, col + 1, movesLeft, board);
				}
			}
		}
		return false;
	}
}
// Function for gameplay
void GameLogic::PlayMineSweeper(Board *board) {
	bool gameOver = false;

	int movesLeft = board->GetSide() * board->GetSide() - board->GetMines();
	int x, y;

	board->InitializeBoards();

	board->PlaceMines();

	int moveIndex = 0;
	while (!gameOver) {
		cout << "Current board status: " << endl;
		board->PrintBoard();
		PlayerInput::MakeAMove(&x, &y);

		// If the first move is a mine
		if (moveIndex == 0 && tile.isMine(x, y, board))
			board->ReplaceMine(x, y);

		moveIndex++;

		gameOver = Gameloop(x, y, &movesLeft, board);

		if (!gameOver && movesLeft == 0) {
			cout << "You won!" << endl;
			gameOver = true;
		}
	}
}
// Function for counting adjacent mines
int GameLogic::CountAdjacentMines(int row, int col, Board *board) {
	int count = 0;

	if (PlayerInput::isValid(row, col - 1, board)) {
		if (Tile::isMine(row, col - 1, board)) {
			count++;
		}
	}
	if (PlayerInput::isValid(row, col + 1, board)) {
		if (Tile::isMine(row, col + 1, board)) {
			count++;
		}
	}
	if (PlayerInput::isValid(row + 1, col, board)) {
		if (Tile::isMine(row + 1, col, board)) {
			count++;
		}
	}
	if (PlayerInput::isValid(row - 1, col, board)) {
		if (Tile::isMine(row - 1, col, board)) {
			count++;
		}
	}
	if (PlayerInput::isValid(row - 1, col - 1, board)) {
		if (Tile::isMine(row - 1, col - 1, board)) {
			count++;
		}
	}
	if (PlayerInput::isValid(row + 1, col + 1, board)) {
		if (Tile::isMine(row + 1, col + 1, board)) {
			count++;
		}
	}
	if (PlayerInput::isValid(row + 1, col - 1, board)) {
		if (Tile::isMine(row + 1, col - 1, board)) {
			count++;
		}
	}
	if (PlayerInput::isValid(row - 1, col + 1, board)) {
		if (Tile::isMine(row - 1, col + 1, board)) {
			count++;
		}
	}
	return count;
}