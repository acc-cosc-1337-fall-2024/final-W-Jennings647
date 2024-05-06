//
#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll)
{
    int check = roll->roll_value();
    if(check == 7 || check == 11)
    {
        return RollOutcome::natural;
    }
    else if(check == 2 || check == 3 || check == 12)
    {
        return RollOutcome::craps;
    }
    else
    {
        return RollOutcome::point;
    }
}