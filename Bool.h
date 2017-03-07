#ifndef BOOL_H
#define BOOL_H
#include "Value.h"

class Bool: public Value
{
    public:
        Bool();
        virtual ~Bool();
        //Inherited weight function to return weight of Boolean values.
        int weight() const{return 1;}
};

#endif // BOOL_H
