#pragma once

class PlayerScore
{

	int points;
	int advantage;

public:

	PlayerScore();
	
	void addPoint();
	int& getPoints();
	int& getAdvantage();
	void resetAdvantage();
	void addAdvantage();
};
