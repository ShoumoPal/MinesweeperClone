#include "Tile.h"

// Function to validate mine at position given
bool Tile::isMine(int _row, int _col, Board *board) {
	return board->realBoard[_row][_col] == '*';
}