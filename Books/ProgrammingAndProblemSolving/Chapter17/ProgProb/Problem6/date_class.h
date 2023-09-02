#pragma once
#include <iostream>
using std::cout;

class Date{
    public:
        Date();
        Date(int setDay, int setMonth, int setYear);
        void PrintDate();
        bool Equal(Date& toCompare);
    private:
        int day, month, year;
};