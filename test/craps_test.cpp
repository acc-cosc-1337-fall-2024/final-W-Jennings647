#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify random for Die class, function roll")
{
	Die test;
	int check;
	for(auto i = 0; i < 10; i++)
	{
		check = test.roll();
		REQUIRE(1 <= check);
		REQUIRE(6 >= check);
	}
}

TEST_CASE("Verify that roll successfully adds together two dice rolls")
{
	Die die1, die2;
	Roll test(die1, die2);
	int check;
	for(auto i = 0; i < 10; i++)
	{
		test.roll_dice();
		check = test.roll_value();
		REQUIRE(2 <= check);
		REQUIRE(12 >= check);
	}
}

TEST_CASE("Verify that class shooter works")
{
	Shooter shooter;
	int check;
	Die die1, die2;
	for(auto i = 0; i < 10; i++)
	{
		check = shooter.throw_dice(die1, die2)->roll_value();
		REQUIRE(2 <= check);
		REQUIRE(12 >= check);
	}
}