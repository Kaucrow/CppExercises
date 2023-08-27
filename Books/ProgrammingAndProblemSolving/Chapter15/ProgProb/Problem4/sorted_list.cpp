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

bool GenSortedList::IsEmpty() const{ return(length == 0); }

bool GenSortedList::IsFull() const{ return(length == MAX_LENGTH); }

int GenSortedList::Length() const{ return length; }

// assumes that the length is increased on list construction
void GenSortedList::InsertPtr(ItemType* ptr){
    if(length == MAX_LENGTH){ cerr << "ERR: LIST OUT OF SPACE\n"; return; }
    int index;

    index = length - 1;
    while (index >= 0 && ptr->pSurname < ptrs[index]->pSurname){
        ptrs[index + 1] = ptrs[index];
        index--;
    }
    ptrs[index + 1] = ptr;
}

void GenSortedList::Delete(ItemType item){
    if(this->IsEmpty()){ cerr << "ERR: THERE ARE NO ELEMENTS IN LIST\n"; return; }
    bool found;
    int position;
    int index;

    BinSearch(item, found, position);
    if(found){
        for(index = position; index < length - 1; index++){
            ptrs[index] = ptrs[index + 1];
        }
        length--;
    }
}

void GenSortedList::DeleteAllOf(ItemType item){
    if(this->IsEmpty()){ cerr << "ERR: THERE ARE NO ELEMENTS IN LIST\n"; return; }
    bool found;
    int basePos;

    // get the base pos (the position of any of the items we want to delete)
    BinSearch(item, found, basePos);
    if(found){
        // right and left index limits of the collection of items that will be deleted
        int leftIndex = basePos, rightIndex = basePos;
        // check if the item(s) on the left are equal to the base item,
        // and if so, reduce the left index
        if(basePos > 0){
            while(leftIndex > 0){
                if(ptrs[basePos] == ptrs[leftIndex - 1]){ leftIndex--; }
                else break;
            }
        }
        // check if the item(s) on the right are equal to the base item,
        // and if so, increase the right index
        if(basePos < length - 1){
            while(rightIndex < length - 1){
                if(ptrs[basePos] == ptrs[rightIndex + 1]){ rightIndex++; }
                else break;
            }
        }
        // set the amount of items that will be deleted
        int amountToDel = (rightIndex - leftIndex) + 1;
        // set the amount of items to the right of the right index
        int itemsToRight = ((length - 1) - rightIndex);
        int displaceLim = leftIndex + itemsToRight;
        // displace the items so that the collection to delete gets "pushed out" of the data
        for(leftIndex; leftIndex < displaceLim; leftIndex++){
            ptrs[leftIndex] = ptrs[rightIndex + 1]; rightIndex++;
        }
        length -= amountToDel;
    }
}

bool GenSortedList::IsPresent(ItemType item) const{
    bool found;
    int position;           // required arg for BinSearch (unused)
    BinSearch(item, found, position);
    return found;
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

// =====================
//  - PRIVATE METHODS -
// =====================
void GenSortedList::BinSearch(ItemType item, bool& found, int& position) const{
    if(length > INT_MAX / 2){ cerr << "ERR: CANNOT SAFELY PERFORM BIN SEARCH\n"; return; }
    int first = 0;
    int last = length - 1;
    int middle;

    found = false;
    while (last >= first && !found){
        middle = (first + last) / 2;
        if(item.ORD_MEMBR < ptrs[middle]->ORD_MEMBR){
            last = middle - 1;
        }
        else if(item.ORD_MEMBR > ptrs[middle]->ORD_MEMBR){
            first = middle + 1;
        }
        else found = true;
    }
    if(found) position = middle;
}

// ==========================================
//      *** OutSortedList CLASS ***
// ==========================================
OutSortedList::OutSortedList(int newMaxLength) 
    : GenSortedList(newMaxLength, 0){}

// assumes that the length is increased on list construction
void OutSortedList::InsertPtr(ItemType* ptr){
    if(length == MAX_LENGTH){ cerr << "ERR: LIST OUT OF SPACE\n"; return; }
    else { cout << "INSERTED\n"; }
    int index;

    index = length - 1;
    while (index >= 0 && ptr->mSurname < ptrs[index]->mSurname){
        ptrs[index + 1] = ptrs[index];
        index--;
    }
    ptrs[index + 1] = ptr;
}

void OutSortedList::GetFileContacts(string contactInName, int contactsNumArr[], int currFile){
    ifstream contactIn;
    contactIn.open(contactInName);
    if(!contactIn) { cerr << "ERR: FILE \"" << contactInName << "\" COULD NOT BE OPENED\n"; return; }

    bool earlyExit;
    string currLine; 
    DataFields currField;
    ItemType* contactPtr;
    getline(contactIn, currLine); getline(contactIn, currLine);     // ignore first 2 lines of contactIn
    for(int i = 0; i < contactsNumArr[currFile]; i++){
        earlyExit = 0;
        getline(contactIn, currLine);
        for(int j = 0; j < 12; j++){
            getline(contactIn, currLine);
            if(currLine.empty()){ earlyExit = 1; break; }
            currField = DataFields(j);
            this->StoreNextField(currField, currLine); 
        }
        if(!earlyExit) getline(contactIn, currLine);
        contactPtr = &contacts[currentPos];
        this->InsertPtr(contactPtr);
        length++;
        currentPos++;       // after a contact has been stored, increase the currentPos
    }
    contactIn.close();
}

void OutSortedList::Test(){
    cout << contacts[1].mSurname << '\n';
    cout << contacts[1].pSurname << '\n';
    cout << contacts[1].name << '\n';
    cout << contacts[1].phoneNum << '\n';
    cout << contacts[1].address << '\n';
    cout << contacts[1].email << '\n';
}

// =====================
//  - PRIVATE METHODS -
// =====================
void OutSortedList::StoreNextField(DataFields currField, string currLine){
    string data = currLine.substr(currLine.find(':') + 2);
    switch(currField){
        case MSURNAME:      if(currLine.substr(0,1) == "M"){     contacts[currentPos].mSurname   = data; cout << "EXECUTED\n"; } break;
        case PSURNAME:      if(currLine.substr(0,2) == "Pa")    contacts[currentPos].pSurname   = data; break;
        case NAME:          if(currLine.substr(0,1) == "N")     contacts[currentPos].name       = data; break;
        case PHONENUM:      if(currLine.substr(0,2) == "Ph")    contacts[currentPos].phoneNum   = data; break;
        case TITLE:         if(currLine.substr(0,1) == "T")     contacts[currentPos].title      = data; break;
        case COMPANY:       if(currLine.substr(0,2) == "Co")    contacts[currentPos].company    = data; break;
        case ADDRESS:       if(currLine.substr(0,1) == "A")     contacts[currentPos].address    = data; break;
        case CITY:          if(currLine.substr(0,2) == "Ci")    contacts[currentPos].city       = data; break;
        case STATE:         if(currLine.substr(0,1) == "S")     contacts[currentPos].state      = data; break;
        case POSTALCODE:    if(currLine.substr(0,2) == "Po")    contacts[currentPos].postalCode = data; break;
        case FAXNUM:        if(currLine.substr(0,1) == "F")     contacts[currentPos].faxNum     = data; break;
        case EMAIL:         if(currLine.substr(0,1) == "E")     contacts[currentPos].email      = data; break;
        default: cerr << "ERR: ERROR ON STORE NEXT FIELD!!!\n"; break;
    }
}