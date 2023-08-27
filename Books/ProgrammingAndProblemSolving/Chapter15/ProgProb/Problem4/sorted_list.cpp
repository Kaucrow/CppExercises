#include <iostream>
#include <string.h>
#include "sorted_list.h"
#define ORD_MEMBR pSurname
using   std::cout, std::cerr, std::cin, std::getline,
        std::ofstream;

GenSortedList::GenSortedList(int newMaxLength, bool populate) : length(0), MAX_LENGTH(newMaxLength), currentPos(0){
    ptrs     = new ItemType*[MAX_LENGTH];
    contacts = new ItemType[MAX_LENGTH];
    if(populate){
        char exitFlag;
        ItemType* tempPtr;
        string tempStr;
        // POPULATE THE CONTACT LIST
        for(int i = 0; i < MAX_LENGTH; i ++){
            cout << "Maternal surname: ";   getline(cin, contacts[i].mSurname);
            cout << "Paternal surname: ";   getline(cin, contacts[i].pSurname);
            cout << "Name: ";               getline(cin, contacts[i].name);
            cout << "Phone number:";        getline(cin, contacts[i].phoneNum);
            cout << "Title: ";              getline(cin, contacts[i].title);
            cout << "Company name: ";       getline(cin, contacts[i].company);
            cout << "Address: ";            getline(cin, contacts[i].address);
            cout << "City: ";               getline(cin, contacts[i].city);
            cout << "State: ";              getline(cin, contacts[i].state);
            cout << "Postal code: ";        getline(cin, contacts[i].postalCode);
            cout << "Fax number: ";         getline(cin, contacts[i].faxNum);
            cout << "Email address: ";      getline(cin, contacts[i].email);
            tempPtr = &contacts[i];
            this->InsertPtr(tempPtr);
            length++;
            do{
            cout << "Enter another contact? (y/n): "; cin.get(exitFlag);
            }while(exitFlag != 'y' && exitFlag != 'n');
            cin.ignore(1);
            if(exitFlag == 'n') break;
        }
    }
}

GenSortedList::~GenSortedList(){ delete[] ptrs; delete[] contacts; }

bool GenSortedList::IsFull() const{ return(length == MAX_LENGTH); }

int GenSortedList::Length() const{ return length; }

// assumes that the length is increased on list construction
void GenSortedList::InsertPtr(ItemType* ptr){
    if(this->IsFull()){ cerr << "ERR: LIST OUT OF SPACE\n"; return; }
    int index;

    index = length - 1;
    while (index >= 0 && ptr->pSurname < ptrs[index]->pSurname){
        ptrs[index + 1] = ptrs[index];
        index--;
    }
    ptrs[index + 1] = ptr;
}

ItemType* GenSortedList::GetNextItem(){
    ItemType* itemPtr;
    itemPtr = ptrs[currentPos];
    if(currentPos == length - 1) currentPos = 0;
    else currentPos++;
    return itemPtr;
}

void GenSortedList::Reset(){
    currentPos = 0;
}

// =====================
//   - OP OVERLOADS - 
// =====================
ostream& operator<<(ostream& out, GenSortedList& someList){
    ItemType* tempItem;
    out << "*** Number of contacts: " << someList.Length() << " ***\n";
    for(int i = 0; i < someList.Length(); i++){
        tempItem = someList.GetNextItem();
        out << "\n--> CONTACT #" << i + 1 << '\n';
        if(tempItem->mSurname.empty()){}     else out << "Maternal surname: "   << tempItem->mSurname   << '\n';
        if(tempItem->pSurname.empty()){}     else out << "Paternal surname: "   << tempItem->pSurname   << '\n';
        if(tempItem->name.empty()){}         else out << "Name: "               << tempItem->name       << '\n';
        if(tempItem->phoneNum.empty()){}     else out << "Phone number: "       << tempItem->phoneNum   << '\n';
        if(tempItem->title.empty()){}        else out << "Title: "              << tempItem->title      << '\n';
        if(tempItem->company.empty()){}      else out << "Company name: "       << tempItem->company    << '\n';
        if(tempItem->address.empty()){}      else out << "Address: "            << tempItem->address    << '\n';
        if(tempItem->city.empty()){}         else out << "City: "               << tempItem->city       << '\n';
        if(tempItem->state.empty()){}        else out << "State: "              << tempItem->state      << '\n';
        if(tempItem->postalCode.empty()){}   else out << "Postal code: "        << tempItem->postalCode << '\n';
        if(tempItem->faxNum.empty()){}       else out << "Fax number: "         << tempItem->faxNum     << '\n';
        if(tempItem->email.empty()){}        else out << "Email address: "      << tempItem->email      << '\n';
    }
    return out;
}

// ==========================================
//      *** OutSortedList CLASS ***
// ==========================================
OutSortedList::OutSortedList(int newMaxLength) 
    : GenSortedList(newMaxLength, 0){}

void OutSortedList::GetFileContacts(string contactInName, int contactsNumArr[], int currFile){
    ifstream contactIn;
    contactIn.open(contactInName);
    if(!contactIn) { cerr << "ERR: FILE \"" << contactInName << "\" COULD NOT BE OPENED\n"; return; }

    bool earlyExit;                         // 1 if at least one of the contact's fields were missing, 
                                            // 0 if all 12 fields were processed
    string currLine, tempStr;
    char initialChar;
    ItemType* contactPtr;
    getline(contactIn, currLine); getline(contactIn, currLine);     // ignore first 2 lines of contactIn

    for(int i = 0; i < contactsNumArr[currFile]; i++){
        earlyExit = 0;
        getline(contactIn, currLine);       // ignore "--> CONTACT #N" line
        for(int j = 0; j < 12; j++){
            getline(contactIn, currLine);
            if(currLine.empty()){ earlyExit = 1; break; }           // if an empty line is reached before the for loop
                                                                    // finished, set the emptyExit flag and exit the loop
            tempStr = currLine.substr(0, 1);
            initialChar = tempStr[0];                               // store the first char of the current line
            this->StoreNextField(initialChar, currLine);
        }
        if(!earlyExit) getline(contactIn, currLine);                // if there was no early exit, consume the empty line
        contactPtr = &contacts[currentPos];
        this->InsertPtr(contactPtr);
        length++;                           // after a contact has been stored, increase the length
        currentPos++;                       // and the currentPos 
    }
    contactIn.close();
}

// =====================
//  - PRIVATE METHODS -
// =====================
// stores the next contact field
void OutSortedList::StoreNextField(char initialChar, string currLine){
    string data = currLine.substr(currLine.find(':') + 2);
    switch(initialChar){
        case 'M': contacts[currentPos].mSurname = data; break;
        case 'N': contacts[currentPos].name     = data; break;
        case 'T': contacts[currentPos].title    = data; break;
        case 'A': contacts[currentPos].address  = data; break;
        case 'S': contacts[currentPos].state    = data; break;
        case 'F': contacts[currentPos].faxNum   = data; break;
        case 'E': contacts[currentPos].email    = data; break;
        case 'P':{
            if(currLine.substr(0,2) == "Pa")        contacts[currentPos].pSurname = data;
            else if(currLine.substr(0,2) == "Ph")   contacts[currentPos].phoneNum = data;
            else                                    contacts[currentPos].postalCode = data;
            break;
        }
        case 'C':{
            if(currLine.substr(0,2) == "Co")    contacts[currentPos].company = data;
            else                                contacts[currentPos].city = data;
            break;
        }
        default: cerr << "ERR: ERROR ON STORE NEXT FIELD!!!\n"; break;
    }
}

// assumes that the length is increased in caller method
void OutSortedList::InsertPtr(ItemType* ptr){
    if(this->IsFull()){ cerr << "ERR: LIST OUT OF SPACE\n"; return; }
    int index;

    index = length - 1;
    while (index >= 0 && ptr->mSurname < ptrs[index]->mSurname){
        ptrs[index + 1] = ptrs[index];
        index--;
    }
    ptrs[index + 1] = ptr;
}
