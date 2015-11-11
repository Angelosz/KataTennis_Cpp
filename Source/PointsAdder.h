#pragma once
#include "Player.h"
#include "Game.h"

class PointsAdder
{
public:

	void addPointsToPlayerAScore(Game& game, int times)
	{
		for (int i = 0; i < times; i++)
			game.scorePointForPlayerA();
	}
	
	void addPointsToPlayerBScore(Game& game, int times)
	{
		for (int i = 0; i < times; i++)
			game.scorePointForPlayerB();
	}

	void addPointsToPlayerScore(Player& player, int times)
	{
		for (int i = 0; i < times; i++)
			player.addPoint();
	}
};
