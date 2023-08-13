#include <iostream>
#include <fstream>
#include <iomanip>

using   std::cout, std::cerr, std::string, std::setw,
        std::ifstream, std::ofstream, std::stof;

void DiffFileGen(string& dataFileName, char diffFileName[]);
void FindMaxMin(char diffFileName[], float& max, float& min, int check);             // check = [2 : max] [5 : min] [8 : diff]
size_t FindNthCharPos(string currStr, int nthChar);

int main(){
    float max, min;
    string dataFileName = "barometric.dat";
    char diffFileName[] = "differences.dat";
    DiffFileGen(dataFileName, diffFileName);

    FindMaxMin(diffFileName, max, min, 8);
    cout << "Year max difference: " << max << '\n';
    cout << "Year min difference: " << min << '\n';
    FindMaxMin(diffFileName, max, min, 2);
    cout << "Year max pressure: " << max << '\n';
    FindMaxMin(diffFileName, max, min, 5);
    cout << "Year min pressure: " << min << '\n';
}

void DiffFileGen(string& dataFileName, char diffFileName[]){
    float max, min, currVal;
    string currStr;
    size_t remainingStr, currStrSize;
    int valCount, currLine = 0;
    int errorFlag = 0;              // [0 : No error] [1 : Invalid value] [2 : Less values than expected] [3 : More values than expected]

    remove(diffFileName); ofstream differences(diffFileName);
    differences << setw(10) << "Max" << setw(6) << "Min" << setw(13) << "Difference" << '\n';

    ifstream barPressure(dataFileName);
    if(!barPressure){ cerr << "Could not open file \"" << dataFileName << "\".\n"; return; }

    while(getline(barPressure, currStr)){
        currLine++; max = 28.0; min = 32.0, valCount = 0;
        currStrSize = currStr.length();
        while(true){
            currVal = stof(currStr, &remainingStr);             // get the first value of the currStr and store the
                                                                // index of the remaining str in a size_t variable
            valCount++;
            if((currVal < 28.0 || currVal > 32.0) && valCount <= 24){ errorFlag = 1; valCount = 24; break; }
            if(currVal > max) max = currVal;
            if(currVal < min) min = currVal;
            if(remainingStr == currStr.length()) break;         // if the remaining str is equal to the currStr length,
                                                                // the currStr's values have been checked.
            currStr = currStr.substr(remainingStr + 1);
        }
        if(valCount < 24) errorFlag = 2;
        if(valCount > 24) errorFlag = 3;

        // ERROR HANDLER
        if(errorFlag){
            cerr << "ERROR: ";
            switch(errorFlag){
                case 1: cerr << "Invalid value detected on line " << currLine << ".\n"; break;
                case 2: cerr << "Line: " << currLine << " has too few values.\n"; break;
                case 3: cerr << "Line: " << currLine << " has too many values.\n"; break;
            }
            break;
        }

        differences << "Day " << currLine << ": " << max << "   " << min << "   " << (max-min); 
        if(currLine != 7) differences << '\n';
    }
    barPressure.close();
    differences.close();
}

void FindMaxMin(char diffFileName[], float& max, float& min, int checkPos){
    max = 0; min = 99;
    float currVal;
    string currStr;
    ifstream differences; differences.open(diffFileName);

    getline(differences, currStr);
    while(getline(differences, currStr)){
        currVal = stof(currStr.substr(FindNthCharPos(currStr, checkPos) + 1)); 
        if(currVal > max) max = currVal;
        if(currVal < min) min = currVal;
    }
    differences.close();
}

size_t FindNthCharPos(string currStr, int nthChar){
    size_t pos = -1;
    while(nthChar > 0){
        pos = currStr.find(' ', pos + 1);
        nthChar--;
    }
    return pos;
}