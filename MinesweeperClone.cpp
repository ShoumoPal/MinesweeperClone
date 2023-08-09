#include <iostream>

using namespace std;

#define MAXSIDE 25



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
		cout << "     ";
		for (int i = 0; i < side; i++) {
			cout << i;
		}
		cout << "\n\n";
		for (int i = 0; i < side; i++) {
			cout << i << "   ";
			for (int j = 0; j < side; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}	
};
int main() {
	cout << "Hello";
	return 0;
}