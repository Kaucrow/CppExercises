#include <iostream>
#include "sorted_list.h"
using std::cout, std::cerr;

SortedList::SortedList() : length(0), currentPos(0){}

bool SortedList::IsEmpty() const{ return(length == 0); }

bool SortedList::IsFull() const{ return(length == MAX_LENGTH); }

int SortedList::Length() const{ return length; }

void SortedList::Insert(ItemType item){
    if(length == MAX_LENGTH){ cerr << "ERR: LIST OUT OF SPACE\n"; return; }
    int index;

    index = length - 1;
    while (index >= 0 && item < data[index]){
        data[index + 1] = data[index];
        index--;
    }
    data[index + 1] = item;
    length++;
}

void SortedList::Delete(ItemType item){
    if(this->IsEmpty()){ cerr << "ERR: THERE ARE NO ELEMENTS IN LIST\n"; return; }
    bool found;
    int position;
    int index;

    BinSearch(item, found, position);
    if(found){
        for(index = position; index < length - 1; index++){
            data[index] = data[index + 1];
        }
        length--;
    }
}

void SortedList::DeleteAllOf(ItemType item){
    if(this->IsEmpty()){ cerr << "ERR: THERE ARE NO ELEMENTS IN LIST\n"; return; }
    bool found;
    int basePos;

    // get the base pos (the position of any of the items we want to delete)
    BinSearch(item, found, basePos);
    if(found){
        // right and left displacement relative to the base item's pos
        int dispLeft = 0, dispRight = 0;
        // check if the item(s) on the left are equal to the base item,
        // and if so, increase the left displacement
        for(int i = 1; i <= basePos; i++){
            if(data[basePos] == data[basePos - i]){ dispLeft++; }
            else break;
        }
        // check if the item(s) on the right are equal to the base item,
        // and if so, increase the right displacement
        for(int i = 1; i <= (length - 1); i++){
            if(data[basePos] == data[basePos + i]){ dispRight++; }
            else break;
        }
        int leftIndex = basePos - dispLeft;
        int rightIndex = basePos + dispRight;
        int amountToDel = (rightIndex - leftIndex) + 1;
        for(leftIndex; leftIndex < (length - amountToDel); leftIndex++){
            data[leftIndex] = data[rightIndex + 1]; rightIndex++;
        }
        length -= amountToDel;
    }
}

bool SortedList::IsPresent(ItemType item) const{
    bool found;
    int position;           // required arg for BinSearch (unused)
    BinSearch(item, found, position);
    return found;
}

ItemType SortedList::GetNextItem(){
    ItemType item;
    item = data[currentPos];
    if(currentPos == length - 1) currentPos = 0;
    else currentPos++;
    return item;
}

void SortedList::Reset(){
    currentPos = 0;
}

// =====================
//   - OP OVERLOADS - 
// =====================
ostream& operator<<(ostream& COUT, SortedList someList){
    for(int i = 0; i < someList.Length(); i++){
        cout << someList.GetNextItem() << ' ';
    }
    cout << '\n';
    return COUT;
}

// =====================
//  - PRIVATE METHODS -
// =====================
void SortedList::BinSearch(ItemType item, bool& found, int& position) const{
    if(length > INT_MAX / 2){ cerr << "ERR: CANNOT SAFELY PERFORM BIN SEARCH\n"; return; }
    int first = 0;
    int last = length - 1;
    int middle;

    found = false;
    while (last >= first && !found){
        middle = (first + last) / 2;
        if(item < data[middle]){
            last = middle - 1;
        }
        else if(item > data[middle]){
            first = middle + 1;
        }
        else found = true;
    }
    if(found) position = middle;
}