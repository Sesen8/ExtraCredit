// Title: Lab 1 - Formatting.cpp
//
// Purpose: The programs found in the file is used to get ages found in json files
//          get strings found between two strings, formating the found infromation
//          into  a csv file as well as creates a header.
//
// Class: CSC 2430 Winter 2022
// Author: Sesen Yonas

#include <cassert>

#include "Formatting.h"
#include "FileProcessing.h"
#include <iostream>
#include <cstring>
#include <string>

using std::string;



// Returns CSV header as a string
//
// Parameters:
//      None
// Returns:
//      CSV header
void CSVHeader(char* csvHeader) {


    const char* CSVheader  = "FirstName, LastName, Age, Height, Nationality ";
    strcpy(csvHeader,CSVheader);

}


// Converts one JSON formatted line to CSV, returning the CSV
// representation as a string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      CSV formatted line
void FormatAsCSV(const char* json, char* csvLine) {
    //creates a copy for json
    char* JSONcp = new char[strlen(json)+1];
    strcpy(JSONcp,json);

    // gathers arll the found strings with the GetStringInBetween function
    char* fName = GetStringInBetween(JSONcp,"\"FirstName\":\"","\"");
    char* LName = GetStringInBetween(JSONcp,"\"LastName\":\"","\"");
    char* age = new char[100];
    GetAge(JSONcp,age);
    char* height = GetStringInBetween(JSONcp,"\"Height\":",",");
    char* nat = GetStringInBetween(JSONcp,"\"Nationality\":\"","\"");(json);


    // adds all the found strings and and commas to the copy c string
    strcpy(csvLine,fName);
    strcat(csvLine,",");
    strcat(csvLine,LName);
    strcat(csvLine,",");
    strcat(csvLine,age);
    strcat(csvLine,",");
    strcat(csvLine,height);
    strcat(csvLine,",");
    strcat(csvLine,nat);


}

// Gets the string between the two parameters sent
//
//
// Parameters:
//      json - JSON formatted line
//      startStr- first string
//      endStr - end string
// Returns:
//      string found in between
char* GetStringInBetween(char* json, const char* startStr, const char* endStr){
    //checks if its null
    if(strstr(json,startStr) != nullptr){
        if(strlen(startStr) != 0){

            // creates a starting pointer and gets the start and end positions
            char* startPtr = strstr(json,startStr);
            char* startPosition = (startPtr + strlen(startStr));
            char* endPosition = strstr(startPosition,endStr);

            //checks if end position is null
            if(endPosition == nullptr) {
                endPosition = strstr(startPosition, " ");
            }


            //allocates the spaces
            char* spaces = new char[endPosition-startPosition+1];

            for (int i =0; i<(endPosition-startPosition); i++){
                spaces[i] = startPosition[i];
            }

            spaces[endPosition-startPosition] = '\0';
            return spaces;
        }
    }

    else {
        // important for the zendaya no last name case
        static char nothingStr[] = "";
        return nothingStr;
    }
    return nullptr;
}




// Return the age value stored in a JSON
// formatted line.  The return value is a string
// If age doesn't appear, returns empty string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      age as string, or empty if age doesn't appear
void GetAge(const char* json,char* ageString) {

    //creates a copy of the json sent through parameter
    char* JSONcp = new char[strlen(json)+1];
    strcpy(JSONcp,json);

    // uses the GetStringInBetween
    char* ages = GetStringInBetween(JSONcp,"\"Age\":",",");
    for (int i =0; i<strlen(ages); i++){
        ageString[i] = ages[i];
    }

    ageString[strlen(ages)] = '\0';


    //remember to delete!
    delete[] JSONcp;

}



