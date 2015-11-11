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
public:

	Game();

	Player& getPlayerA();
	Player& getPlayerB();

	GameState getState() const;
	void checkIfPlayerWonAgainst(Player& player, Player& enemyPlayer);
	void addPointsForPlayer(Player& player);
	void resetAdvantages();
	void scorePointForPlayerA();
	void scorePointForPlayerB();
	bool thereIsAWinner();
	
	bool IsDeuce();
	bool bothPointsAreForty();
	bool advantagesAreTied();

	GameState checkState();
	void updateState();

	std::string& getWinnerName();

};
