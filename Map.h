#ifndef MAP_H
#define MAP_H
#include "Value.h"

class Map: public Value
{
    public:
        Map();
        virtual ~Map();
        //Inherited function to return the value of a Map.
        int weight()const {return 1;}
};

#endif // MAP_H
