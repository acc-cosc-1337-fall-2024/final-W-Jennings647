#include<iostream>
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"
using std::cout; using std::cin;

int main() 
{
	srand(time(0));
	Die die1, die2;
	Shooter shooter;
	Roll* roll = new Roll(die1, die2);
	roll = shooter.throw_dice(die1, die2);
	int rolled_value = roll->roll_value();
	ComeOutPhase come_out_phase;
	char win = 'N';
	if(come_out_phase.get_outcome(roll) == RollOutcome::natural){win = 'Y'; cout<<"Rolled "<<rolled_value<<", natural! You win!\n";}
	
	
	if(win == 'N') 
	{
		
		while(come_out_phase.get_outcome(roll) == RollOutcome::craps)
		{
			cout<<"Rolled "<<rolled_value<<"\n";
			if(come_out_phase.get_outcome(roll) == RollOutcome::craps)
			{
				cout<<"Craps! Roll again \n";
				roll = shooter.throw_dice(die1, die2);
				rolled_value = roll->roll_value();
			}
			if(come_out_phase.get_outcome(roll) == RollOutcome::natural){win = 'Y'; cout<<"Rolled "<<rolled_value<<", natural!\n";}
		};

		if(win == 'N')
		{
			cout<<"Rolled "<<rolled_value<<" Start of point phase\n";
			int point = rolled_value;
			PointPhase point_phase(point);
			roll = shooter.throw_dice(die1, die2);
			rolled_value = roll->roll_value();
			cout<<"Roll until a "<<point<<" or 7 is rolled\n";
			if(point_phase.get_outcome(roll) == RollOutcome::seven_out){win = 'Y'; cout<<"Rolled "<<rolled_value<<", seven out\n";}

			while(point_phase.get_outcome(roll) == RollOutcome::no_point)
			{
				cout<<"Rolled "<<rolled_value<<" Roll again!\n";
				roll = shooter.throw_dice(die1, die2);
				rolled_value = roll->roll_value();
				if(point_phase.get_outcome(roll) == RollOutcome::seven_out){win = 'Y'; cout<<"Rolled "<<rolled_value<<", seven out\n";}
			};

			if(win == 'N')
			{
				cout<<"Rolled "<<rolled_value<<" end of point phase\n";
				win = 'Y';
			}
		}
	} //sorry that the program is so different from the instructions, but i wanted to make it so that end on a natural 7

	cout<<"Previous rolls:\n";
	shooter.display_rolled_values();

	return 0;
}