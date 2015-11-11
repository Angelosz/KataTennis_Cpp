#include "Game.h"

Game::Game()
{
	state = Ongoing;
	playerA = Player("PlayerA");
	playerB = Player("PlayerB");
	winner = nullptr;
}

Player& Game::getPlayerA()
{
	return playerA;
}

Player& Game::getPlayerB()
{
	return playerB;
}

GameState Game::getState() const
{
	return state;
}

void Game::checkWinners()
{
	if (playerA.getAdvantage() - playerB.getAdvantage() == 1)
		winner = &playerA;
	if (playerB.getAdvantage() - playerA.getAdvantage() == 1)
		winner = &playerB;
}

bool Game::advantagesAreTied()
{
	return playerA.getAdvantage() == playerB.getAdvantage();
}

bool Game::bothPointsAreForty()
{
	return (playerA.getPoints() == 40 && playerB.getPoints() == 40);
}

bool Game::IsDeuce()
{
	return bothPointsAreForty() && advantagesAreTied();
}

void Game::updateState()
{
	checkWinners();
	if (winner)
		state = Ended;
	else
		if (IsDeuce()) state = Deuce;
}

std::string Game::getWinnerName() const
{
	if (winner)
	{
		return winner->getName();
	}
	return "No winners yet";
}
