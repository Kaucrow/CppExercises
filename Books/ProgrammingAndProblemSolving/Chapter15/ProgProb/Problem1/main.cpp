#include <iostream>
#include <fstream>
#include "sorted_list.h"
using   std::cout, std::cerr, std::string, std::ifstream,
        std::getline;

int main(){

    string fileName = "licensesA.dat";
    ifstream licenses;
    licenses.open(fileName);
    if(!licenses){ cerr << "ERR: FILE \"" << fileName << "\" COULD NOT BE OPENED\n"; return 0; }
    int dataSize;
    licenses >> dataSize;
    licenses.ignore(1);
    SortedList registry(10, licenses);
    cout << registry.Length();
    cout << registry;
    registry.Reset();
    cout << registry.GetPos();
    registry.ProcessItems();
}