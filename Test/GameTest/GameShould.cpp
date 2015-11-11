#include "../TestRunner/catch.hpp"
#include <Game.h>
#include <PointsAdder.h>

/*
* 1. If you have 40 and you win the ball you win the game, however there are special rules.
*
* 2. If both have 40 the players are deuce.
*	a.If the game is in deuce, the winner of a ball will have advantage and game ball.
*	b.If the player with advantage wins the ball he wins the game
*	c.If the player without advantage wins they are back at deuce.
* */
TEST_CASE("Game should")
{
	Game game;
	PointsAdder PointsAdder;

	SECTION("start with state as Ongoing")
	{
		REQUIRE(game.getState() == Ongoing);
	}
	
	SECTION("return PlayerA as winner after winning four balls to zero")
	{
		PointsAdder.addPointsToPlayerAScore(game, 4);

		CHECK(game.getWinnerName() == "PlayerA");
		REQUIRE(game.getState() == Ended);
	}

	SECTION("return PlayerB as winner after winning four balls to zero")
	{
		PointsAdder.addPointsToPlayerBScore(game, 4);

		CHECK(game.getWinnerName() == "PlayerB");
		REQUIRE(game.getState() == Ended);
	}
	
	SECTION("return Deuce as State when both players have 40 points")
	{
		PointsAdder.addPointsToPlayerAScore(game, 3);
		PointsAdder.addPointsToPlayerBScore(game, 3);

		CHECK(game.getWinnerName() == "No winners yet");
		REQUIRE(game.getState() == Deuce);
	}
	
	SECTION("return Deuce as State when both players have 40 points and 1 advantage")
	{
		PointsAdder.addPointsToPlayerAScore(game, 3);
 		PointsAdder.addPointsToPlayerBScore(game, 4);
		PointsAdder.addPointsToPlayerAScore(game, 1);

		CHECK(game.getWinnerName() == "No winners yet");
		REQUIRE(game.getState() == Deuce);
	}
	
	SECTION("return Ongoing as State when both players have 40 points, and playerA has 1 advantage")
	{
		PointsAdder.addPointsToPlayerAScore(game, 3);
		PointsAdder.addPointsToPlayerBScore(game, 3);
		PointsAdder.addPointsToPlayerAScore(game, 1);
		
		CHECK(game.getWinnerName() == "No winners yet");
		REQUIRE(game.getState() == Ongoing);
	}

	SECTION("return Ended as State and PlayerA as winner")
	{
		PointsAdder.addPointsToPlayerAScore(game, 3);
		PointsAdder.addPointsToPlayerBScore(game, 3);
		PointsAdder.addPointsToPlayerAScore(game, 1);
		PointsAdder.addPointsToPlayerBScore(game, 1);
		PointsAdder.addPointsToPlayerAScore(game, 2);


		CHECK(game.getWinnerName() == "PlayerA");
		REQUIRE(game.getState() == Ended);
	}
}