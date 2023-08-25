#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::string, std::ostream, std::istream, std::ofstream;
struct Register{
    string nameAndAddress;
    int licenseNum;
};
typedef Register ItemType;
class SortedList{
    public:
        SortedList(int newMaxLength, istream* ISTREAM);
        bool IsEmpty() const;
        bool IsFull() const;
        int Length() const;
        void Insert(ItemType item);
        void Delete(int license);
        void DeleteAllOf(int license);
        bool IsPresent(int license) const;
        int GetNextLicense();
        string GetNextFull();
        void Reset();
        void ProcessItems(ofstream& outFile, char fileLetter);
        int GetPos();       // used for debugging purposes
        ~SortedList();
        friend class SortedListBYSTR;
    private:
        const int MAX_LENGTH;
        int length;
        int currentPos;
        ItemType* data;
        void BinSearch(int, bool&, int&) const;
        ItemType* GetNextItem();
        int Find2ndChar(char ch, string str) const;
};

// PRINTS THE LIST
ostream& operator<<(ostream& COUT, SortedList& someList);

// This sorted list has function Insert() redefined so it can sort
// based on the alphabetical order of a the last name of each person
// in the "licenses.dat" files. DO NOT ATTEMPT TO USE FUNCTIONS Delete(),
// DeleteAllOf(), IsPresent(), AND BinSearch() AS THEY ARE LIKELY NOT
// TO WORK DUE TO THE CHANGE IN SORTING METHOD
class SortedListBYSTR : public SortedList{
    public:
        SortedListBYSTR(int nexMaxLength);
        void Insert(ItemType item);
};