#include "../TestRunner/catch.hpp"
#include <Player.h>
#include <PointsAdder.h>
/*
* 1. Each player can have either of these points in one game 0 15 30 40
*/



TEST_CASE("PlayerScore should")
{
	Game game;
	PointsAdder PointsAdder;

	SECTION("have 15 points after winning one ball")
	{
		PointsAdder.addPointsToPlayerAScore(game, 1);

		REQUIRE(game.getPlayerA().getPoints() == 15);
	}

	SECTION("have 30 points after winning two balls")
	{
		PointsAdder.addPointsToPlayerAScore(game, 2);

		REQUIRE(game.getPlayerA().getPoints() == 30);
	}

	SECTION("have 40 points after winning three balls")
	{
		PointsAdder.addPointsToPlayerAScore(game, 3);

		REQUIRE(game.getPlayerA().getPoints() == 40);
	}

	SECTION("have 40 points and one advantage after winning four balls")
	{
		PointsAdder.addPointsToPlayerAScore(game, 4);

		REQUIRE(game.getPlayerA().getPoints() == 40);
		REQUIRE(game.getPlayerA().getAdvantage() == 1);
	}
}