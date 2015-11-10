#include "../TestRunner/catch.hpp"
#include <PlayerScore.h>

/*
* 1. Each player can have either of these points in one game 0 15 30 40
*/

void addPointsToPlayerScore(PlayerScore& PlayerScore, int times)
{
	for (int i = 0; i < times; i++)
		PlayerScore.addPoint();
}

TEST_CASE("PlayerScore should")
{
	PlayerScore PlayerScore;

	SECTION("have 15 points after winning one ball")
	{
		PlayerScore.addPoint();

		REQUIRE(PlayerScore.getPoints() == 15);
	}

	SECTION("have 30 points after winning two balls")
	{
		addPointsToPlayerScore(PlayerScore, 2);

		REQUIRE(PlayerScore.getPoints() == 30);
	}

	SECTION("have 40 points after winning three balls")
	{
		addPointsToPlayerScore(PlayerScore, 3);

		REQUIRE(PlayerScore.getPoints() == 40);
	}

	SECTION("have 40 points and an advantage after winning four balls")
	{
		addPointsToPlayerScore(PlayerScore, 4);

		REQUIRE(PlayerScore.getPoints() == 40);
		REQUIRE(PlayerScore.getAdvantage() == 1);
	}
}