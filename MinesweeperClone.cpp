#include <iostream>

using namespace std;

#define MAXSIDE 25

int side;
int mines;

bool isValid(int _row, int _col) {
	return (((_row >= 0) && (_row < side)) && (_col >= 0) && (_col < side));
}

int main() {
	cout << "Hello";
	return 0;
}