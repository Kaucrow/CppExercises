#include <iostream>
#include <fstream>

using std::cout, std::cerr, std::string, std::ifstream;

void GetNonemptyLine(string& inFileName, int& lineNum);

int main(){
    int lineNum = 0;
    string inFileName = "data.txt";
    GetNonemptyLine(inFileName, lineNum);
    cout << "Found characters in line: " << lineNum << '\n';
}

void GetNonemptyLine(string& inFileName, int& lineNum){
    string tempStr;

    ifstream inFile;
    inFile.open(inFileName);
    if(!inFile){ cerr << "Could not open file \"" << inFileName << "\"\n"; return; }
    while(getline(inFile, tempStr)){
        lineNum++;
        if(!tempStr.empty()) return;
    }
}