#include <iostream>
#include <fstream>

using std::cout, std::string, std::ifstream;

void SkipToEmptyLine(string& inFileName, int& skipped);

int main(){
    int skipped = 0;
    string inFileName = "data.txt";
    SkipToEmptyLine(inFileName, skipped);
    cout << "The number of lines that were skipped is: " << skipped << '\n';
}

void SkipToEmptyLine(string& inFileName, int& skipped){
    string tempStr;

    ifstream inFile;
    inFile.open(inFileName);
    if(!inFile){ cout << "Could not open file \"" << inFileName << "\"\n"; return; }

    while(getline(inFile, tempStr)){
        skipped++;
        if(tempStr.empty()) return;
    }
}