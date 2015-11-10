#include "PlayerScore.h"

PlayerScore::PlayerScore()
{
	points = 0;
}

void PlayerScore::addPoint()
{
	points = (points == 30) ? 40 : points + 15;
}

int PlayerScore::getPoints()
{
	return points;
}