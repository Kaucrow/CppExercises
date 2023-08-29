#include <iostream>
#include "exceptions.h"
using std::cout, std::cerr, std::string;

const int ALPHABET_LENGTH = 26;

void PrintICAOConversion
    (string toConvert, char letters[], const char* ICAO[]);

int main(){
    char letters[ALPHABET_LENGTH] =  
       {'A','B','C','D','E','F','G','H',
        'I','J','K','L','M','N','O','P','Q',
        'R','S','T','U','V','W','X','Y','Z'};

    const char* ICAO[ALPHABET_LENGTH] =   
       {"Alpha", "Bravo", "Charlie", "Delta",
        "Echo", "Foxtrot", "Golf", "Hotel",
        "India", "Juliet", "Kilo", "Lima",
        "Mike", "November", "Oscar", "Papa",
        "Quebec", "Romeo", "Sierra", "Tango", "Uniform",
        "Victor", "Whiskey", "X-Ray", "Yankee", "Zulu"};

   try{ PrintICAOConversion("SomeW()rld", letters, ICAO); }
   catch(NotFound err){ cerr << err.what(); }
}

void PrintICAOConversion
    (string toConvert, char letters[], const char* ICAO[])
{
    bool found;
    for(int i = 0; i < toConvert.length(); i++){
        found = 0;
        for(int j = 0; j < ALPHABET_LENGTH; j++){
            if(toupper(toConvert[i]) == letters[j])
                { cout << ICAO[j] << '\n'; found = 1; }
        }
        if(found == 0){
            cerr << '\'' << toConvert[i] << '\'' << ' ';
            throw NotFound("CHARACTER NOT FOUND ON ALPHABET\n");
        } 
    }
}