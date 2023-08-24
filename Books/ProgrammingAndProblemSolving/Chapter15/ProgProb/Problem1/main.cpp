#include <iostream>
#include <fstream>
#include "sorted_list.h"
using   std::cout, std::cerr, std::string, std::ifstream,
        std::getline;

int main(){
    string inFile = "licensesA.dat";
    string outFile = "duplicatesA.dat";
    ifstream licenses;
    licenses.open(inFile);
    if(!licenses){ cerr << "ERR: FILE \"" << inFile << "\" COULD NOT BE OPENED\n"; return 0; }
    int dataSize;
    licenses >> dataSize;
    licenses.ignore(1);
    SortedList registry(10, licenses);
    cout << registry;
    registry.ProcessItems(outFile);
}