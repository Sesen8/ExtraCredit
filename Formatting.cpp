// Title: Lab 1 - Formatting.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>

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
    char* JSONcp = new char[strlen(json)+1];
    strcpy(JSONcp,json);

    char* fName = GetStringInBetween(JSONcp,"\"FirstName\":\"","\"");
    char* LName = GetStringInBetween(JSONcp,"\"LastName\":\"","\"");
    char* age = new char[100];
    GetAge(JSONcp,age);
    char* height = GetStringInBetween(JSONcp,"\"Height\":\"",",");
    char* nat = GetStringInBetween(JSONcp,"\"Nationality\":\"","\"");(json);

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


char* GetStringInBetween(char* json, const char* startStr, const char* endStr){

    if(strstr(json,startStr) != nullptr){
        if(strlen(startStr) != 0){

            char* startPtr = strstr(json,startStr);
            char* startPosition = (startPtr + strlen(startStr));
            char* endPosition = strstr(startPosition,endStr);

            if(endPosition == nullptr) {
                endPosition = strstr(startPosition, " ");
            }

            char* spaces = new char[endPosition-startPosition+1];

            for (int i =0; i<(endPosition-startPosition); i++){
                spaces[i] = startPosition[i];
            }

            spaces[endPosition-startPosition] = '\0';
            return spaces;
        }
    }

    else {
        char nothingStr[] = "";
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

    char* ages = GetStringInBetween(JSONcp,"\"Age\":",",");
    for (int i =0; i<strlen(ages); i++){
        ageString[i] = ages[i];
    }

    ageString[strlen(ages)] = '\0';

    delete[] JSONcp;

}



