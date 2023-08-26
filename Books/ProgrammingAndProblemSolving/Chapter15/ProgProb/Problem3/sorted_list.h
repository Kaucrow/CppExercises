#pragma once
#include <iostream>
#include <string>
using std::ostream, std::string; 

struct Contact{
    string  mSurname, fSurname, name, title,
            company, address, city, state,
            phoneNum, email, postalCode, faxNum;
};

typedef Contact ItemType;

const int MAX_LENGTH = 100;
class SortedList{
    public:
        SortedList();
        bool IsEmpty() const;
        bool IsFull() const;
        int Length() const;
        void InsertPtr(ItemType* ptr);
        void Delete(ItemType item);
        void DeleteAllOf(ItemType item);
        bool IsPresent(ItemType item) const;
        ItemType* GetNextItem();
        void Reset();
        ~SortedList();
    private:
        int length;
        int currentPos;
        ItemType* ptrs[MAX_LENGTH];
        ItemType* contacts = new ItemType[MAX_LENGTH];
        void BinSearch(ItemType, bool&, int&) const;
};

// PRINTS THE LIST
ostream& operator<<(ostream& COUT, SortedList& someList);