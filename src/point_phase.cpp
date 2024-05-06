//

#include "point_phase.h"

RollOutcome PointPhase::get_outcome(Roll* roll)
{
    int check = roll->roll_value();
    if(check == 7)
    {
        return RollOutcome::seven_out;
    }
    else
    {
        return RollOutcome::no_point;
    }
}