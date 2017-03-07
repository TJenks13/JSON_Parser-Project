#ifndef ARRAY_H
#define ARRAY_H
#include "Value.h"


class Array: public Value
{
    public:
        Array();
        virtual ~Array();
        int n = 0;
        //Weight function to return weight of Array.
        int weight() const{return 1;}

};

#endif // ARRAY_H
