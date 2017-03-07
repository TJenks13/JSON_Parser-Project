/*Assignment 2: JSON Parser
Written by Trevor Jenkins
The purpose of this project is to read a JSON document
into an ifstream object, and then pass the file by reference
through to a parsing object, which will assign weights to values
found in the JSON document through polymorphism. That value is
then returned and displayed to the user.*/
#include <iostream>
#include "Bool.h"
#include "Null.h"
#include "Number.h"
#include "String.h"
#include "Array.h"
#include "Map.h"
#include "JSON_Parser.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //ifstream object to read in JSON file.
    ifstream readFile;

    //Open the file to be read.
    readFile.open("json.txt");

    //File verification.
    if(!readFile)
    {
        cout << "The file could not be read. Please try again later.";
    }

    //Create a JSON_Parser object to parse through the JSON document.
    JSON_Parser parser;

    //Display the weight of the document by calling the JSON_Parser parsing function.
    cout << "Here is the calculated weight of the JSON document: " << parser.parser_for_weight(readFile);

    return 0;
}
