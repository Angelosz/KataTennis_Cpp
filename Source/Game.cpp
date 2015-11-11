#include "Game.h"

Game::Game()
{
	state = Ongoing;
	playerA = Player("PlayerA");
	playerB = Player("PlayerB");
	winner = Player(noWinnerMessage);
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

std::string& Game::getWinnerName()
{
	return winner.getName();
}

void Game::addPointsForPlayer(Player& player)
{
	if (player.getAdvantage() == 1) winner = player;
	addPointsTo(player);
	updateState();
	if (state == Deuce) resetAdvantages();	
}

void Game::addPointsTo(Player& player)
{
	if (player.getPoints() >= 30)
	{
		player.addAdvantage();
	}
	player.addPoint();
}

void Game::resetAdvantages()
{
	playerA.resetAdvantage();
	playerB.resetAdvantage();
}

void Game::updateState()
{
	state = checkState();
}

GameState Game::checkState()
{
	if (thereIsAWinner()) return Ended;

	if (IsDeuce()) return Deuce;

	return Ongoing;
}

bool Game::thereIsAWinner()
{
	return winner.getName() != noWinnerMessage;
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