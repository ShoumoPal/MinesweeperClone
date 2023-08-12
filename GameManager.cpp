#include <iostream>
#include <iomanip>
#include "GameManager.h"

using namespace std;

void GameManager::Play() {

	PlayerInput *input = new PlayerInput();
	Board* board = new Board();
	GameLogic *game = new GameLogic();
	

	game->GameIntro();
	input->ChooseDifficulty(board);
	game->PlayMineSweeper(board);
}