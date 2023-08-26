#include <iostream>
#include <fstream>
#include "sorted_list.h"
using   std::cout, std::cin, std::string, std::ofstream,
        std::cerr;

int main(){
    char outFileName[] = "contacts.dat";
    remove(outFileName);
    ofstream contactFile;
    contactFile.open(outFileName);
    if(!contactFile){ cerr << "ERR: COULD NOT OPEN FILE \"" << outFileName << "\"\n"; return 1; }
    
    SortedList contactList;

    contactFile.close();
}
