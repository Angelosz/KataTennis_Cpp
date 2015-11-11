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
		PointsAdder.addPointsToPlayerScore(game.getPlayerA(), 4);
		game.updateState();

		CHECK(game.getWinnerName() == "PlayerA");
		REQUIRE(game.getState() == Ended);
	}
	
	SECTION("return PlayerB as winner after winning four balls to zero")
	{
		PointsAdder.addPointsToPlayerScore(game.getPlayerB(), 4);
		game.updateState();

		CHECK(game.getWinnerName() == "PlayerB");
		REQUIRE(game.getState() == Ended);
	}

	SECTION("Should return Deuce as State when both players have 40 points")
	{
		PointsAdder.addPointsToPlayerScore(game.getPlayerA(), 3);
		PointsAdder.addPointsToPlayerScore(game.getPlayerB(), 3);
		game.updateState();

		CHECK(game.getWinnerName() == "No winners yet");
		REQUIRE(game.getState() == Deuce);
	}


}