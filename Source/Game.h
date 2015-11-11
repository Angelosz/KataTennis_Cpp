#pragma once
#include "Player.h"
#include <string>
#include <memory>

enum GameState { Ended, Deuce, Ongoing};

class Game
{
private:
	Player playerB;
	Player playerA;
	Player* winner;

	GameState state;


public:

	Game();

	Player& getPlayerA();
	Player& getPlayerB();

	GameState getState() const;

	void checkWinners();
	
	void updateState();

	std::string getWinnerName() const;

};
