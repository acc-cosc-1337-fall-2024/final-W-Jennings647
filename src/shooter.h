//
#include "roll.h"
#include "die.h"
#include<vector>

using std::vector;

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
    public:
        Roll* throw_dice(Die& die1, Die& die2);
        void display_rolled_values();
        ~Shooter();
    private:
        vector<Roll*> rolls;

};

#endif