#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include<iostream>
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"
using std::cout;

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
	Roll* test = new Roll(die1, die2);
	int check;
	for(auto i = 0; i < 10; i++)
	{
		test->roll_dice();
		check = test->roll_value();
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

TEST_CASE("Verify the parent class Phase and child classes ComeOutPhase and PointPhase work")
{
	Die die1, die2;
	Roll* test = new Roll(die1, die2);
	ComeOutPhase comeoutphase;
	int check;

	for(auto i = 0; i < 20; i++)
	{
		test->roll_dice();
		check = test->roll_value();
		PointPhase pointphase(11); //set to 11 to simplify test cases
		cout<<check<<"\n";
		if(check == 7)
    	{
			REQUIRE(comeoutphase.get_outcome(test) == RollOutcome::natural);
			REQUIRE(pointphase.get_outcome(test) == RollOutcome::seven_out);
    	}
		else if(check == 11)
		{
			REQUIRE(comeoutphase.get_outcome(test) == RollOutcome::natural);
			REQUIRE(pointphase.get_outcome(test) == RollOutcome::point);
		}
    	else if(check == 2 || check == 3 || check == 12)
    	{
			REQUIRE(comeoutphase.get_outcome(test) == RollOutcome::craps);
			REQUIRE(pointphase.get_outcome(test) == RollOutcome::no_point);
    	}
    	else
    	{
        	REQUIRE(comeoutphase.get_outcome(test) == RollOutcome::point);
			REQUIRE(pointphase.get_outcome(test) == RollOutcome::no_point);
    	}
	}
	

}