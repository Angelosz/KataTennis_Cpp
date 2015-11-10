#include "PlayerScore.h"

PlayerScore::PlayerScore()
{
	points = 0;
}

void PlayerScore::addPoint()
{
	if (points == 40) advantage = 1;
	else points = (points == 30) ? 40 : points + 15;
}

int PlayerScore::getPoints()
{
	return points;
}

int PlayerScore::getAdvantage()
{
	return advantage;
}