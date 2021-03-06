﻿#include "Player.h"

Player::Player()
{
	name = "Player";
}

Player::Player(std::string name) : name(name){}

void Player::addPoint()
{
	score.addPoint();
}

int& Player::getPoints()
{
	return score.getPoints();
}

int& Player::getAdvantage()
{
	return score.getAdvantage();
}

std::string& Player::getName()
{
	return name;
}

void Player::resetAdvantage()
{
	score.resetAdvantage();
}

void Player::addAdvantage()
{
	score.addAdvantage();
}