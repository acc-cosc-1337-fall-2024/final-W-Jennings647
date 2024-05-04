//
#include<cstdlib>
using std::rand;
class die
{
    public:
        int roll(){return (1 + (rand() % (size - 1)));};
    private:
        int size{6};

};