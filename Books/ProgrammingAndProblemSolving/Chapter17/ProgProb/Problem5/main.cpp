#include <iostream>
#include <map>
#include <cmath>
#include "exceptions.h"
using std::cout, std::cerr, std::cin, std::string, std::map;

map<int, string> NumStrMap = {{1, "one"},   {2, "two"},     {3, "three"},   {4, "four"},
                              {5, "five"},  {6, "six"},     {7, "seven"},   {8, "eight"},
                              {9, "nine"},  {10, "ten"},    {11, "eleven"}, {12, "twelve"},
                              {13, "thirteen"}, {14, "fourteen"},   {15, "fifteen"},
                              {16, "sixteen"},  {17, "seventeen"},  {18, "eighteen"},
                              {19, "ninteen"},  {20, "twenty"},     {30, "thirty"},
                              {40, "fourty"},   {50, "fifty"},      {60, "sixty"}};

string NumToStr(int toConvert);
void GetHoursMins(int& hours, int& mins);

int main(){
    int hours, mins, realHours;
    while(true){
        try{ GetHoursMins(hours, mins); break; }
        catch(BadInput excep){ cerr << excep.what(); }
    }

    string amPm;
    amPm = (hours >= 12) ? "p.m." : "a.m.";
    
    if(mins == 0){
        if(hours == 12){ cout << "Midday\n"; return 0; }
        if(hours == 0) { cout << "Midnight\n"; return 0; }
    }
    if(hours >= 13) realHours = hours - 12;
    else realHours = hours;

    cout << NumToStr(realHours) << ' ' << NumToStr(mins) << ' ' << amPm << '\n';
}

void GetHoursMins(int& hours, int& mins){
    cout << "Input hours and minutes, separated by a space: ";
    cin >> hours; cin >> mins;
    if(hours < 0 || hours >= 24 || mins < 0 || mins >= 60 )
        throw BadInput("ERR: INVALID INPUT\n");
}

string NumToStr(int toConvert){
    string returnStr;

    if(toConvert >= 20){
        int switchInt = floor(toConvert / 10.0) * 10;
        for(auto& i : NumStrMap){
            if(i.first == switchInt) returnStr += i.second; }
        returnStr.push_back('-');
    }

    if(toConvert >= 10 && toConvert <= 19)
        for(auto& i : NumStrMap){
            if(i.first == toConvert) returnStr += i.second; }
    else
        for(auto& i : NumStrMap){
            if(i.first == (toConvert % 10)) returnStr += i.second; }
    
    return returnStr;
}