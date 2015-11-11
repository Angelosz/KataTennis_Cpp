#include "PlayerScore.h"

PlayerScore::PlayerScore()
{
	points = 0;
	advantage = 0;
}

void PlayerScore::addPoint()
{
	points = (points >= 30) ? 40 : points + 15;
}

int& PlayerScore::getPoints()
{
	return points;
}

int& PlayerScore::getAdvantage()
{
	return advantage;
}

void PlayerScore::resetAdvantage()
{
	advantage = 0;
}

void PlayerScore::addAdvantage()
{
	advantage = 1;
}