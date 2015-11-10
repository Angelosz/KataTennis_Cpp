#include "PlayerScore.h"

PlayerScore::PlayerScore()
{
	points = 0;
}

void PlayerScore::addPoint()
{
	points += 15;
}

int PlayerScore::getPoints()
{
	return points;
}