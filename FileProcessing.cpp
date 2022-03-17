// Title: Lab 1 - FileProcessing.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>

#include <cassert>

#include "Formatting.h"
#include "FileProcessing.h"

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

using std::string;
using std::string;
using std::iostream;
using std::endl;
using std::cin;
using std::cout;
using std::getline;



// Operates in a loop so multiple files can be processed.
// On each iteration, reads name of input and output files from user and opens them
// Then calls ProcessFile to do the actual file processing
// - If user enters a blank line for the input file, loop ends
// - If either file cannot be opened, loop restarts
//
// Parameters:
//      none
// Returns:
//      nothing
void ProcessFiles() {

    ofstream csv;
    string File;
    //char fileData;
    char csvData[500] = "";
    char* fileCstring;
    char* inputFile;
    ifstream jsonFile;
    char jsonFormat[] = ".json";
    bool GetFile = true;
    bool continueProgram = true;

    do{
        cout << "Input File Name: ";
        getline(cin,File);

        inputFile = new char[File.length()+1];
        strcpy(inputFile, File.c_str());

        if(File.empty()){
            GetFile = false;
            continueProgram = false;
        }

        else if(strstr(inputFile,jsonFormat) == nullptr){
            cout <<"ERROR: Incorrect file format, please provide a JSON file" << endl;
        }

        else{
            jsonFile.open(inputFile);
                if(!jsonFile.is_open()){
                    cout << "ERROR: " << inputFile << " was not found, please try again." << endl;
                }
                else {
                    GetFile = false;
                }
            }



    } while(GetFile);

    while(continueProgram){
        // for asking about csv file
        // simular to asking about json file
        char csvFormat[] = ".csv";

        do {
            cout << "Output File Name: ";
            getline(cin,File);
            fileCstring = new char[File.length()+1];
            strcpy(fileCstring,File.c_str());

            if(strstr(fileCstring,csvFormat) == nullptr){
                cout << "ERROR: Incorect file format, please provide a CSV file" << endl;
                continue;

            }
            break;
        } while(true);

        csv.open(fileCstring);
        if(jsonFile.is_open()){

            // for calculations
            double sum = 0;
            double avg = 0.0;
            int count = 0;
            int age = 0;


            // max is set to smallest
            int max = INT32_MIN;
            //min is set to largest
            int min = INT32_MAX;

            // for holding pointer values
            char hold[100] = "";
            char buffer[500];
            char head[500];

            // calls csvHeader function
            CSVHeader(head);
            csv << head << endl;

            while(!jsonFile.eof()){
                jsonFile.getline(buffer,500);

                if (fileCstring[0] != '\0'){
                    FormatAsCSV(buffer,csvData);
                    csv << csvData << endl;
                }

                //holds the age found and converts to string
                if(strcmp(buffer,"") != 0){
                    GetAge(buffer,hold);
                    age = stoi(hold);

                    if(age>max){
                        max = age;
                    }

                    if(age<min){
                        min = age;
                    }
                    count++;
                    sum+=age;
                    // dont need to convert since its already a double
                    avg = sum/count;
                }
            }

            cout << "Minimum Age: " << min << endl;
            cout << "Maximum Age: " << max << endl;
            cout << "Average Age: " << avg << endl;

        }
        // always close file
        jsonFile.close();

        do{
            //starts loop all over again for inputing.
            // same as above code

            cout << "Input File Name: ";
            getline(cin,File);

            inputFile = new char[File.length()+1];
            strcpy(inputFile, File.c_str());

            if(File.empty()){
                GetFile = false;
                continueProgram = false;
            }

            else if(strstr(inputFile,jsonFormat) == nullptr){
                cout <<"ERROR: Incorrect file format, please provide a JSON file" << endl;
            }

            else{
                jsonFile.open(inputFile);
                if(!jsonFile.is_open()){
                    cout << "ERROR: " << inputFile << " was not found, please try again." << endl;
                }
                else {
                    GetFile = false;
                }
            }



        } while(GetFile);
    }
}

