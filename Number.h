#ifndef NUMBER_H
#define NUMBER_H
#include "Value.h"

class Number: public Value
{
    public:
        Number();
        virtual ~Number();
        //Inherited function to return the value of a number.
        int weight() const {return 1;}
};

#endif // NUMBER_H
