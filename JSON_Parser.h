#ifndef JSON_PARSER_H
#define JSON_PARSER_H
#include <fstream>
#include "Value.h"
#include "Array.h"
#include "Bool.h"
#include "Map.h"
#include "Null.h"
#include "Number.h"
#include "String.h"
#include <string>

//Forward declaration of parent classes.
class Value;
class Array;
class Bool;
class Map;
class Null;
class Number;
class String;


//Class JSON_Parser to parse through the JSON document.
class JSON_Parser
{
    public:
        JSON_Parser();
        virtual ~JSON_Parser();

        //Function prototype for parsing function, which takes an ifstream argument.
        int parser_for_weight(std::ifstream&);
};

#endif // JSON_PARSER_H
