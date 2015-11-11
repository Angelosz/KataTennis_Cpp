#pragma once
#include "Player.h"
#include <string>

enum GameState { Ended, Deuce, Ongoing};

class Game
{
private:
	Player* playerA;
	Player* playerB;
	Player* winner;

	GameState state;


public:

	Game();

	~Game();

	Player* getPlayerA() const;

	GameState getState() const;

	void checkWinners();
	
	void updateState();

	std::string getWinnerName() const;
};
