#ifndef NULL_H
#define NULL_H
#include "Value.h"

class Null: public Value
{
    public:
        Null();
        virtual ~Null();
        //Inherited function to return the value of a null.
        int weight() const {return 1;}
};

#endif // NULL_H
