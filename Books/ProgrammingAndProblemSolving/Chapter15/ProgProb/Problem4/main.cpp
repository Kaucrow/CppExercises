#include <iostream>
#include <sstream>
#include "sorted_list.h"
using   std::cerr, std::cout, std::cin, std::string, 
        std::ofstream, std::stringstream;

int main(){
    stringstream outFileSS;
    string outFileName;
    char exitFlag;
    system("del /s *.dat");
    ofstream contactFile;
    SortedList* contactList;
    for(int i = 0; i < MAX_LENGTH; i++){
        exitFlag = '0';
        outFileSS << "contacts" << i + 1 << ".dat"; outFileName = outFileSS.str();
        contactFile.open(outFileName);
        
        // LIST GETS SORTED BY PATERNAL SURNAME. If contacts with no paternal surname are introduced, they
        // will be at the top of the outFile and the ones that do have a paternal surname will get sorted and
        // written after them
        contactList = new SortedList;
        std::cout << *contactList;
        contactFile << *contactList;
 
        delete contactList; contactList = nullptr;
        outFileSS.str(""); outFileSS.clear();   
        contactFile.close();
        
        while(exitFlag != 'y' && exitFlag != 'n' && i < MAX_LENGTH - 1){
            cout << "Create a new contacts file? (y/n): "; exitFlag = cin.get();
        }
        cin.ignore(1);
        if(exitFlag == 'n') break;
    }
}