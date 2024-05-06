//

#include "point_phase.h"

RollOutcome PointPhase::get_outcome(Roll* roll)
{
    int check = roll->roll_value();
    if(check == point) //sorry, misread instructions so I'm submitting question 4 twice... (also i dont know how to play craps lol)
    {
        return RollOutcome::point;
    }
    else if(check == 7)
    {
        return RollOutcome::seven_out;
    }
    else
    {
        return RollOutcome::no_point;
    }
}