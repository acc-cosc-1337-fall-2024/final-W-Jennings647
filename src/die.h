//
#include<cstdlib>
using std::rand;

#ifndef DIE_H
#define DIE_H

class Die
{
    public:
        int roll(){return (1 + (rand() % (size - 1)));};
    private:
        int size{6};

};

#endif