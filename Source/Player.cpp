#include "Player.h"

Player::Player(std::string name) : name(name){}

void Player::addPoint()
{
	score.addPoint();
}

int Player::getPoints()
{
	return score.getPoints();
}

int Player::getAdvantage()
{
	return score.getAdvantage();
}

std::string Player::getName()
{
	return name;
}