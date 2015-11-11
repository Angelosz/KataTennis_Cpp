#include "Game.h"

Game::Game()
{
	state = Ongoing;
	playerA = new Player("PlayerA");
	playerB = new Player("PlayerB");
	winner = nullptr;
}

Game::~Game()
{
	winner = nullptr;
	delete playerA;
	delete playerB;
}

Player* Game::getPlayerA() const
{
	return playerA;
}

GameState Game::getState() const
{
	return state;
}

void Game::checkWinners()
{
	if (playerA->getAdvantage() - playerB->getAdvantage() == 1)
		winner = playerA;
}

void Game::updateState()
{
	checkWinners();
	if (winner)
	{
		state = Ended;
	}
}

std::string Game::getWinnerName() const
{
	if (winner)
	{
		return winner->getName();
	}
	return "No winners yet";
}