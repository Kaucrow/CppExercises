#include <iostream>
#include <fstream>
#include "sorted_list.h"
#define ORD_MEMBR licenseNum    // struct member to base the list order on
using std::cout, std::cerr, std::getline, std::ofstream;

SortedList::SortedList(int newMaxLength, istream& ISTREAM) 
    :   length(0), currentPos(0), MAX_LENGTH(newMaxLength)
{
    data = new Register[newMaxLength];
    // POPULATE THE LIST WITH ISTREAM (LICENSE FILE) CONTENTS
    int tempPos;
    Register* tempReg;
    string* tempStr;
    
    for(int i = 0; i < MAX_LENGTH; i++){
        tempReg = new Register;
        tempStr = new string;
        getline(ISTREAM, *tempStr);
        tempPos = this->Find2ndChar('|', *tempStr);
        
        // store the name and address
        tempReg->nameAndAddress = tempStr->substr(0, tempPos);

        // store the license number
        *tempStr = tempStr->substr(tempPos + 3, string::npos);
        tempReg->licenseNum = stoi(*tempStr);

        this->Insert(*tempReg);
        delete tempReg; delete tempStr;
    }
} 

SortedList::~SortedList(){ delete[] data; }

bool SortedList::IsEmpty() const{ return(length == 0); }

bool SortedList::IsFull() const{ return(length == MAX_LENGTH); }

int SortedList::Length() const{ return length; }

void SortedList::Insert(ItemType item){
    if(length == MAX_LENGTH){ cerr << "ERR: LIST OUT OF SPACE\n"; return; }
    int index;

    index = length - 1;
    while (index >= 0 && item.ORD_MEMBR < data[index].ORD_MEMBR){
        data[index + 1] = data[index];
        index--;
    }
    data[index + 1] = item;
    length++;
}

void SortedList::Delete(int license){
    if(this->IsEmpty()){ cerr << "ERR: THERE ARE NO ELEMENTS IN LIST\n"; return; }
    bool found;
    int position;
    int index;

    BinSearch(license, found, position);
    if(found){
        for(index = position; index < length - 1; index++){
            data[index] = data[index + 1];
        }
        length--;
    }
}

void SortedList::DeleteAllOf(int license){
    if(this->IsEmpty()){ cerr << "ERR: THERE ARE NO ELEMENTS IN LIST\n"; return; }
    bool found;
    int basePos;

    // get the base pos (the position of any of the items we want to delete)
    BinSearch(license, found, basePos);
    if(found){
        // right and left index limits of the collection of items that will be deleted
        int leftIndex = basePos, rightIndex = basePos;
        // check if the item(s) on the left are equal to the base item,
        // and if so, reduce the left index
        if(basePos > 0){
            while(leftIndex > 0){
                if(data[basePos].ORD_MEMBR == data[leftIndex - 1].ORD_MEMBR){ leftIndex--; }
                else break;
            }
        }
        // check if the item(s) on the right are equal to the base item,
        // and if so, increase the right index
        if(basePos < length - 1){
            while(rightIndex < length - 1){
                if(data[basePos].ORD_MEMBR == data[rightIndex + 1].ORD_MEMBR){ rightIndex++; }
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
            data[leftIndex] = data[rightIndex + 1]; rightIndex++;
        }
        length -= amountToDel;
    }
}

bool SortedList::IsPresent(int license) const{
    bool found;
    int position;           // required arg for BinSearch (unused)
    BinSearch(license, found, position);
    return found;
}

int SortedList::GetNextLicense(){
    int license;
    license = data[currentPos].ORD_MEMBR;
    if(currentPos == length - 1) currentPos = 0;
    else currentPos++;
    return license;
}

void SortedList::Reset(){
    currentPos = 0;
}

int SortedList::GetPos(){ return currentPos; }

void SortedList::ProcessItems(string outFile){
    int repeats = 0;
    Register *tempReg1, *tempReg2;
    tempReg1 = this->GetNextItem();
    tempReg2 = this->GetNextItem();
    for(int i = 0; i < MAX_LENGTH; i++){
        if(tempReg1->licenseNum == tempReg2->licenseNum){ cout << "EQUAL\n"; repeats++; }
        tempReg1 = tempReg2;
        tempReg2 = this->GetNextItem();
    }
    if(repeats > 0){
        ofstream duplicates;
        char* charOutFile = &outFile[0];
        remove(charOutFile);
        duplicates.open(outFile);
        duplicates << "duplicatesA.dat: " << repeats;
    }
}

// =====================
//   - OP OVERLOADS - 
// =====================
ostream& operator<<(ostream& COUT, SortedList& someList){
    for(int i = 0; i < someList.Length(); i++){
        cout << someList.GetNextLicense() << ' ';
    }
    cout << '\n';
    return COUT;
}

// =====================
//  - PRIVATE METHODS -
// =====================
void SortedList::BinSearch(int license, bool& found, int& position) const{
    if(length > INT_MAX / 2){ cerr << "ERR: CANNOT SAFELY PERFORM BIN SEARCH\n"; return; }
    int first = 0;
    int last = length - 1;
    int middle;

    found = false;
    while (last >= first && !found){
        middle = (first + last) / 2;
        if(license < data[middle].ORD_MEMBR){
            last = middle - 1;
        }
        else if(license > data[middle].ORD_MEMBR){
            first = middle + 1;
        }
        else found = true;
    }
    if(found) position = middle;
}

ItemType* SortedList::GetNextItem(){
    ItemType* reg;
    reg = &data[currentPos];
    if(currentPos == length - 1) currentPos = 0;
    else currentPos++;
    return reg;
}

int SortedList::Find2ndChar(char ch, string str) const{
    int pos1, pos2;
    pos1 = str.find('|');
    str = str.substr(pos1 + 1, string::npos);
    pos2 = str.find('|');
    return pos1 + pos2;
}