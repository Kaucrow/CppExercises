#include <iostream>
#include <sstream>
#include <string.h>
#include "sorted_list.h"
using   std::cerr, std::cout, std::cin, std::string, 
        std::ofstream, std::ifstream, std::stringstream;
const int MAX_LENGTH = 100;

int main(){
    stringstream outFileSS;
    string outFileName;
    char exitFlag;
    //system("del /s *.dat");
    ofstream outFile;
    GenSortedList* contactList;
    /*
    // *** GENERATE THE contacts_.dat FILES ***
    for(int i = 0; i < MAX_LENGTH; i++){
        exitFlag = '0';
        outFileSS << "contacts" << i + 1 << ".dat"; outFileName = outFileSS.str();
        outFile.open(outFileName);
        
        // LIST GETS SORTED BY PATERNAL SURNAME. If contacts with no paternal surname are introduced, they
        // will be at the top of the outFile and the ones that do have a paternal surname will get sorted and
        // written after them
        contactList = new GenSortedList(MAX_LENGTH, 1);
        std::cout << *contactList;
        outFile << *contactList;
 
        delete contactList; contactList = nullptr;
        outFileSS.str(""); outFileSS.clear();   
        outFile.close();
        
        while(exitFlag != 'y' && exitFlag != 'n' && i < MAX_LENGTH - 1){
            cout << "Create a new contacts file? (y/n): "; exitFlag = cin.get();
        }
        cin.ignore(1);
        if(exitFlag == 'n') break;
    }*/

    // *** MERGE THE contacts_.dat FILES ***
    int filesNum, contactsNum = 0;
    stringstream inFileSS;
    string inFileName, tempStr;
    ifstream inFile;
    cout << "How many files will be merged?: "; cin >> filesNum;
    int contactsNumArr[filesNum];
    memset(contactsNumArr, 0, sizeof(contactsNumArr));
    
    for(int i = 0; i < filesNum; i++){
        inFileSS << "contacts" << i + 1 << ".dat"; inFileName = inFileSS.str();
        inFile.open(inFileName);
        if(!inFile){ cerr << "ERR: FILE \"" << inFileName << "\" COULD NOT BE OPENED\n"; }

        std::getline(inFile, tempStr);
        contactsNumArr[i] += stoi(tempStr.substr(tempStr.find_first_of("123456789")));
        contactsNum += contactsNumArr[i];

        inFileSS.str(""); inFileSS.clear();
        inFile.close();
    }

    OutSortedList outList(contactsNum);
    for(int i = 0; i < filesNum; i++){
        inFileSS << "contacts" << i + 1 << ".dat"; inFileName = inFileSS.str();
        inFile.open(inFileName);
        if(!inFile){ cerr << "ERR: FILE \"" << inFileName << "\" COULD NOT BE OPENED\n"; }

        outList.GetFileContacts(inFileName, contactsNumArr, i);

        inFileSS.str(""); inFileSS.clear();
        inFile.close();
    }

    outFile.open("mergedcontacts.dat");
    outList.Reset();
    outFile << outList;
    outFile.close();
}