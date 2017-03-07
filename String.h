#ifndef STRING_H
#define STRING_H
#include "Value.h"

class String: public Value
{
    public:
        String();
        virtual ~String();
        //Inherited function to return the value of a string.
        int weight() const {return 1;}
};

#endif // STRING_H
