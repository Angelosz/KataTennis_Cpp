#pragma once
#include "Player.h"
#include "Game.h"

class PointsAdder
{
public:

	void addPointsToPlayerAScore(Game& game, int times)
	{
		for (int i = 0; i < times; i++)
			game.addPointsForPlayer(game.getPlayerA());
	}
	
	void addPointsToPlayerBScore(Game& game, int times)
	{
		for (int i = 0; i < times; i++)
			game.addPointsForPlayer(game.getPlayerB());
	}
};
