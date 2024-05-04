#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify random")
{
	die test;
	int check;
	for(auto i = 0; i < 10; i++)
	{
		check = test.roll();
		REQUIRE(1 <= check);
		REQUIRE(6 >= check);
	}
}