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

void Game::checkIfPlayerWonAgainst(Player& player, Player& enemyPlayer)
{
	if (player.getAdvantage() - enemyPlayer.getAdvantage() == 1){
		winner = player;
	}
}

void Game::addPointsForPlayer(Player& player)
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

void Game::scorePointForPlayerA()
{
	checkIfPlayerWonAgainst(playerA, playerB);
	addPointsForPlayer(playerA);
	updateState();
}

void Game::scorePointForPlayerB()
{
	checkIfPlayerWonAgainst(playerB, playerA);
	addPointsForPlayer(playerB);
	updateState();
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

GameState Game::checkState()
{
	if (thereIsAWinner()) return Ended;

	if (IsDeuce()){
		resetAdvantages();
		return Deuce;
	}

	return Ongoing;
}

void Game::updateState()
{
	state = checkState();
}

std::string& Game::getWinnerName()
{
	return winner.getName();
}