#include "../TestRunner/catch.hpp"
#include <Player.h>
#include <PointsAdder.h>
/*
* 1. Each player can have either of these points in one game 0 15 30 40
*/



TEST_CASE("PlayerScore should")
{
	Player Player("Player");
	PointsAdder PointsAdder;

	SECTION("have 15 points after winning one ball")
	{
		Player.addPoint();

		REQUIRE(Player.getPoints() == 15);
	}

	SECTION("have 30 points after winning two balls")
	{
		PointsAdder.addPointsToPlayerScore(Player, 2);

		REQUIRE(Player.getPoints() == 30);
	}

	SECTION("have 40 points after winning three balls")
	{
		PointsAdder.addPointsToPlayerScore(Player, 3);

		REQUIRE(Player.getPoints() == 40);
	}

	SECTION("have 40 points and one advantage after winning four balls")
	{
		PointsAdder.addPointsToPlayerScore(Player, 4);

		REQUIRE(Player.getPoints() == 40);
		REQUIRE(Player.getAdvantage() == 1);
	}
}