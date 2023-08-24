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
        // right and left index limits of the collection of items that will be deleted
        int leftIndex = basePos, rightIndex = basePos;
        // check if the item(s) on the left are equal to the base item,
        // and if so, reduce the left index
        if(basePos > 0){
            while(leftIndex > 0){
                if(data[basePos] == data[leftIndex - 1]){ leftIndex--; }
                else break;
            }
        }
        // check if the item(s) on the right are equal to the base item,
        // and if so, increase the right index
        if(basePos < length - 1){
            while(rightIndex < length - 1){
                if(data[basePos] == data[rightIndex + 1]){ rightIndex++; }
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