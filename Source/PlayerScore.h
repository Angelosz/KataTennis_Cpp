#pragma once

class PlayerScore
{
private:

	int points;
	int advantage;
public:

	PlayerScore();
	
	void addPoint();
	int getPoints();
	int getAdvantage();
};
