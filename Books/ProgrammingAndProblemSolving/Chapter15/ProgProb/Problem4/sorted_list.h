#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::ostream, std::ofstream, std::ifstream, std::string; 

struct Contact{
    string  mSurname, pSurname, name, title,
            company, address, city, state,
            phoneNum, email, postalCode, faxNum;
};

typedef Contact ItemType;

class GenSortedList{
    public:
        GenSortedList(int newMaxSize, bool populate);
        bool IsFull() const;
        int Length() const;
        ItemType* GetNextItem();
        void Reset();
        friend class OutSortedList;
        ~GenSortedList();
    private:
        const int MAX_LENGTH;
        int length;
        int currentPos;
        ItemType** ptrs;        // defined as double ptr so the array can be initialized dynamically
        ItemType* contacts;
        void InsertPtr(ItemType* ptr);
};

// PRINTS THE LIST
ostream& operator<<(ostream& COUT, GenSortedList& someList);

class OutSortedList : public GenSortedList{
    public:
        OutSortedList(int newMaxLength);
        void GetFileContacts(string contactInName, int contactsNumArr[], int currFile);
    private:
        void StoreNextField(char initialChar, string currLine);
        void InsertPtr(ItemType* ptr);
};