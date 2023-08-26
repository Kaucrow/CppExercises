#include <iostream>
#include "sorted_list.h"
#define ORD_MEMBR fSurname
using std::cout, std::cerr, std::cin, std::getline;

SortedList::SortedList() : length(0), currentPos(0){
    char exitFlag;
    ItemType* tempPtr;
    string tempStr;
    // POPULATE THE CONTACT LIST
    for(int i = 0; i < MAX_LENGTH; i ++){
        cout << "Maternal surname: ";   getline(cin, contacts[i].mSurname);
        cout << "Paternal surname: ";   getline(cin, contacts[i].fSurname);
        cout << "Name: ";               getline(cin, contacts[i].name);
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

SortedList::~SortedList(){ delete[] contacts; }

bool SortedList::IsEmpty() const{ return(length == 0); }

bool SortedList::IsFull() const{ return(length == MAX_LENGTH); }

int SortedList::Length() const{ return length; }

// assumes that the length is increased on list construction
void SortedList::InsertPtr(ItemType* ptr){
    if(length == MAX_LENGTH){ cerr << "ERR: LIST OUT OF SPACE\n"; return; }
    int index;

    index = length - 1;
    while (index >= 0 && ptr->fSurname < ptrs[index]->fSurname){
        ptrs[index + 1] = ptrs[index];
        index--;
    }
    ptrs[index + 1] = ptr;
}

void SortedList::Delete(ItemType item){
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

bool SortedList::IsPresent(ItemType item) const{
    bool found;
    int position;           // required arg for BinSearch (unused)
    BinSearch(item, found, position);
    return found;
}

ItemType* SortedList::GetNextItem(){
    ItemType* itemPtr;
    itemPtr = ptrs[currentPos];
    if(currentPos == length - 1) currentPos = 0;
    else currentPos++;
    return itemPtr;
}

void SortedList::Reset(){
    currentPos = 0;
}

// =====================
//   - OP OVERLOADS - 
// =====================
ostream& operator<<(ostream& COUT, SortedList& someList){
    ItemType* tempItem = new ItemType;
    for(int i = 0; i < someList.Length(); i++){
        tempItem = someList.GetNextItem();
        cout << "--> CONTACT #" << i + 1 << '\n';
        cout << "Maternal surname: "    << tempItem->mSurname << '\n';
        cout << "Paternal surname: "    << tempItem->fSurname << '\n';
        cout << "Name: "                << tempItem->name << '\n';
        cout << "Title: "               << tempItem->title << '\n';
        cout << "Company name: "        << tempItem->company << '\n';
        cout << "Address: "             << tempItem->address << '\n';
        cout << "City: "                << tempItem->city << '\n';
        cout << "State: "               << tempItem->state << '\n';
        cout << "Postal code: "         << tempItem->postalCode << '\n';
        cout << "Fax number: "          << tempItem->faxNum << '\n';
    }
    cout << '\n';
    delete tempItem; tempItem = nullptr;
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