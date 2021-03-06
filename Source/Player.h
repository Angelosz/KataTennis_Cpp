﻿#pragma once
#include "PlayerScore.h"
#include <codecvt>

class Player
{

	PlayerScore score;
	std::string name;

public:
	Player();
	
	Player(std::string name);

	void addPoint();

	int& getPoints();

	int& getAdvantage();
	
	std::string& getName();
	void resetAdvantage();
	void addAdvantage();
};
