//
#include "die.h"

#ifndef ROLL_H
#define ROLL_H

class Roll
{
    public:
        Roll(Die& x, Die& y):die1(x), die2(y){};
        void roll_dice();
        int roll_value() const{return rolled_value;};
    private:
        Die& die1;
        Die& die2;
        int rolled_value;
};

#endif
