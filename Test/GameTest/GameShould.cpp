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

	SECTION("return PlayerA as winner after winning four balls to zero")
	{
		PointsAdder.addPointsToPlayerScore(*(game.getPlayerA()), 4);
		game.updateState();

		REQUIRE(game.getWinnerName() == "PlayerA");
		REQUIRE(game.getState() == Ended);
	}
}