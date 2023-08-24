#pragma once
#include <iostream>
using std::ostream; 
typedef int ItemType;
const int MAX_LENGTH = 100;
class SortedList{
    public:
        SortedList();
        bool IsEmpty() const;
        bool IsFull() const;
        int Length() const;
        void Insert(ItemType item);
        void Delete(ItemType item);
        void DeleteAllOf(ItemType item);
        bool IsPresent(ItemType item) const;
        ItemType GetNextItem();
        void Reset();
    private:
        int length;
        int currentPos;
        ItemType data[MAX_LENGTH];
        void BinSearch(ItemType, bool&, int&) const;
};

// PRINTS THE LIST
ostream& operator<<(ostream& COUT, SortedList someList);