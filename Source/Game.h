#pragma once
#include "Player.h"
#include <string>

enum GameState { Ended, Deuce, Ongoing};

class Game
{

	Player playerB;
	Player playerA;
	Player winner;

	GameState state;
	std::string noWinnerMessage = "No winners yet";

	void resetAdvantages();

	bool thereIsAWinner();

	bool IsDeuce();
	bool bothPointsAreForty();
	bool advantagesAreTied();

	GameState checkState();
	void updateState();

public:

	Game();

	Player& getPlayerA();
	Player& getPlayerB();

	GameState getState() const;

	void addPointsTo(Player& player);
	void addPointsForPlayer(Player& player);

	std::string& getWinnerName();

};
