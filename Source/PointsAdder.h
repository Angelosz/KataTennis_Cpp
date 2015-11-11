#pragma once
#include "Player.h"

class PointsAdder
{
public:

	void addPointsToPlayerScore(Player& Player, int times)
	{
		for (int i = 0; i < times; i++)
			Player.addPoint();
	}
};
