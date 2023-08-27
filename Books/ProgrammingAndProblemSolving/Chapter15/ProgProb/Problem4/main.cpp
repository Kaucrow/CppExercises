#include <iostream>
#include <sstream>
#include <string.h>
#include "sorted_list.h"
using   std::cerr, std::cout, std::cin, std::string, 
        std::ofstream, std::ifstream, std::stringstream;
const int MAX_FILES    = 100;
const int MAX_CONTACTS = 100;

int main(){
    stringstream outFileSS;
    string outFileName;
    ofstream outFile;
    /*
    char exitFlag;
    GenSortedList* contactList;
    system("del /s *.dat");
    
    // *** GENERATE THE contacts_.dat FILES ***
    for(int i = 0; i < MAX_FILES; i++){
        exitFlag = '0';
        outFileSS << "contacts" << i + 1 << ".dat"; outFileName = outFileSS.str();
        outFile.open(outFileName);
        
        // LIST GETS SORTED BY PATERNAL SURNAME. If contacts with no paternal surname are introduced, they
        // will be at the top of the outFile and the ones that do have a paternal surname will get sorted and
        // written after them
        contactList = new GenSortedList(MAX_CONTACTS, 1);
        cout << *contactList;
        outFile << *contactList;
 
        delete contactList; contactList = nullptr;
        outFileSS.str(""); outFileSS.clear();   
        outFile.close();
        
        while(exitFlag != 'y' && exitFlag != 'n' && i < MAX_FILES - 1){
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

    // fill the contactsNumArr (number of contacts in each file) 
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

    // create the sorted list for output on mergedcontacts.dat
    // and add each file's contacts to it 
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