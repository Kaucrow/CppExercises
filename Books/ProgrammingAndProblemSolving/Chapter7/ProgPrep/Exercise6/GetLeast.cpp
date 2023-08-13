#include <iostream>
#include <fstream>

using std::cout, std::string, std::ifstream;

void GetLeast(string inFileName, int& lowest);

int main(){
    int lowest = 0;
    GetLeast("numbers.txt", lowest);
    cout << "The lowest number is: " << lowest;
}

void GetLeast(string inFileName, int& lowest){
    int currNum, prevNum;
    ifstream inFile;
    
    inFile.open(inFileName);
    if(!inFile){
        cout << "Could not open file \"" << inFileName << "\"";
    }

    inFile >> lowest;
    while(inFile){
        inFile >> currNum;
        if(currNum < lowest) lowest = currNum; 
    }
}