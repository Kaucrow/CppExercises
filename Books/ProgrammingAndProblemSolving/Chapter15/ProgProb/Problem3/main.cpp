#include <iostream>
#include "sorted_list.h"
using std::cerr, std::ofstream;

int main(){
    char outFileName[] = "contacts.dat";
    remove(outFileName);
    ofstream contactFile;
    contactFile.open(outFileName);
    if(!contactFile){ cerr << "ERR: COULD NOT OPEN FILE \"" << outFileName << "\"\n"; return 1; }
    
    // LIST GETS SORTED BY PATERNAL SURNAME. If contacts with no paternal surname are introduced, they
    // will be at the top of the outFile and the ones that do have a paternal surname will get sorted and
    // written after them
    SortedList contactList;
    std::cout << contactList;
    contactFile << contactList;
    
    contactFile.close();
}