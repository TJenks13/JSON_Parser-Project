#include "JSON_Parser.h"
#include <string>


JSON_Parser::JSON_Parser()
{
    //ctor
}

JSON_Parser::~JSON_Parser()
{
    //dtor
}

//Function definition for the parsing function.
int JSON_Parser::parser_for_weight(std::ifstream &inputFile)
{
    //Variable to hold a char and the next char, a string, and the weight.
    char value = ' ';
    char tempVal = ' ';
    std::string line = " ";
    int counter = 0;

    //Get the first value from the JSON document.
    inputFile.get(value);

    //Assign tempVal the value of the next char.
    tempVal = inputFile.peek();

    //Loop through the document as long as it is not at the end.
    while(inputFile)
    {
        //If statement to add to weight if there is an object, which starts with {.
        if(value == '{')
            {
              //Create a Map object.
              Map object;
              //Add value to the weight holder using the Map weight function.
              counter += object.weight();
              //Get the next value from the document.
              inputFile.get(value);
            }
        //If statement to add to weight if a double quotation is found (string).
        if(value == '"')
        {
            //Get the line after the double quote until the next double quote.
            getline(inputFile, line, '"');
            //Get the next values after the line.
            inputFile.get(value);
            inputFile.get(value);
            inputFile.get(value);

            //If statement to get weight if value is null.
            if(value == 'n')
            {
                //Create a Null object.
                Null nullObj;
                //Increment the weight holder using the Null weight function.
                counter += nullObj.weight();
                //Get the line after null to move past the value.
                getline(inputFile, line, ',');
                //Get values after the line.
                inputFile.get(value);
                inputFile.get(value);
            }

            //If statement to get weight if value is a boolean value.
            if(value == 't' || value == 'f')
            {
                //Create a Bool object.
                Bool boolObject;
                //Increment the weight holder using the Bool weight function.
                counter += boolObject.weight();
                //Get the line after the value to move through the document.
                getline(inputFile, line, ',');
                //Get the values after the line.
                inputFile.get(value);
                inputFile.get(value);
            }

            //If the value is a double quote, and the next value is not a comma, get the next value.
            if(value == '"')
            {
                while(value != '"' && tempVal != ',')
                {
                    inputFile.get(value);
                }
                //Create a String object.
                String stringObject;
                //Add to weight holder using String weight function, after the string is found.
                counter += stringObject.weight();
                //Get the next values after the string.
                inputFile.get(value);
                inputFile.get(value);
                inputFile.get(value);
            }

            //If statement to identify a number.
            if(value == '.' || isdigit(value))
            {
                //Create a Number object.
                Number numObj;
                //Increment the weight counter using the Number weight function.
                counter += numObj.weight();
                //Move to the next value in the document.
                inputFile.get(value);

                //While loop to move through the rest of the number.
                while(isdigit(value) || value == '.')
                    inputFile.get(value);

                //Get the next values after the number.
                inputFile.get(value);
                inputFile.get(value);
            }

            //If statement to identify beginning of array.
            if(value == '[')
            {
                //Create an Array object.
                Array arrayObj;
                //Increment the weight holder using the Array weight function.
                counter += arrayObj.weight();
                //Move to the next value.
                inputFile.get(value);
            }
        }

        //Get the next value.
        inputFile.get(value);
    }

    //Return the weight.
    return counter;
}
