// Title: Lab 1 - Formatting.h
//
// Purpose: Declares the functions that understand the JSON format and can reformat a line of
// JSON to a line of CSV
//
// Class: CSC 2430 Winter 2022
// Author: Max Benson

#ifndef FORMATTING_H
#define FORMATTING_H



void CSVHeader(char* csvHeader);
void FormatAsCSV(const char* json, char* csvLine);
void GetAge(const char* json, char* ageString);
char* GetStringInBetween(char* json, const char* startStr, const char* endStr);

#endif //FORMATTING_H
