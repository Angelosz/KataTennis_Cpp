#include "../TestRunner/catch.hpp"
#include <PlayerScore.h>

/*
* 1. Each player can have either of these points in one game 0 15 30 40
* 
* 2. If you have 40 and you win the ball you win the game, however there are special rules.
* 
* 3. If both have 40 the players are deuce.
*	a.If the game is in deuce, the winner of a ball will have advantage and game ball.
*	b.If the player with advantage wins the ball he wins the game 
*	c.If the player without advantage wins they are back at deuce.
* 
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

}