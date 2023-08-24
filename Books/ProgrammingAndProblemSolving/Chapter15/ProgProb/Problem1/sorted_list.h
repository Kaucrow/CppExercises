#pragma once
#include <iostream>
#include <string>
using std::string, std::ostream, std::istream;
struct Register{
    string nameAndAddress;
    int licenseNum;
};
typedef Register ItemType;
class SortedList{
    public:
        SortedList(int newMaxLength, istream& ISTREAM);
        bool IsEmpty() const;
        bool IsFull() const;
        int Length() const;
        void Insert(ItemType item);
        void Delete(int license);
        void DeleteAllOf(int license);
        bool IsPresent(int license) const;
        int GetNextLicense();
        void Reset();
        void ProcessItems();
        int GetPos();
        ~SortedList();
    private:
        /*const*/ int MAX_LENGTH;
        int length;
        int currentPos;
        ItemType* data;
        void BinSearch(int, bool&, int&) const;
        ItemType* GetNextItem();
        int Find2ndChar(char ch, string str) const;
};

// PRINTS THE LIST
ostream& operator<<(ostream& COUT, SortedList& someList);