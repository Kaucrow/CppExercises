#include <iostream>
#include "sorted_list.h"
using   std::cout, std::cerr, std::string, std::ifstream,
        std::getline;

const int FILE_NUM = 3;    // FILE_NUM MUST BE 1 <= FILE_NUM <= 26

int main(){
    string inFile;
    int dataSize;
    char outFile[] = "duplicates.dat";
    ifstream licenses;
    ifstream* licensesPtr = &licenses;
    remove(outFile);
    ofstream duplicates;
    duplicates.open(outFile);

    for(char letter = 'A'; letter <= FILE_NUM + 64; letter++){     // 'A' ASCII value = 65
        cout << "\n--> PROCESSING FILE " << letter << "...\n";
        inFile = string("licenses") + letter + ".dat";
        cout << inFile << "\n\n";
        
        licenses.open(inFile);
        if(!licenses){ cerr << "ERR: FILE \"" << inFile << "\" COULD NOT BE OPENED\n"; return 0; }
        
        licenses >> dataSize;
        licenses.ignore(1);
        SortedList registry(dataSize, licensesPtr);
        cout << "LIST: " << registry;
        registry.ProcessItems(duplicates, letter);
        licenses.close();
    }
    duplicates.open(outFile);
}