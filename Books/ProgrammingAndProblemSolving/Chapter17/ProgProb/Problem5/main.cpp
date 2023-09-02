#include <iostream>
#include <map>
#include <cmath>
using std::cout, std::cin, std::string, std::map;

map<int, string> NumStrMap = {{1, "one"},   {2, "two"},     {3, "three"},   {4, "four"},
                              {5, "five"},  {6, "six"},     {7, "seven"},   {8, "eight"},
                              {9, "nine"},  {10, "ten"},    {11, "eleven"}, {12, "twelve"},
                              {13, "thirteen"}, {14, "fourteen"},   {15, "fifteen"},
                              {16, "sixteen"},  {17, "seventeen"},  {18, "eighteen"},
                              {19, "ninteen"},  {20, "twenty"},     {30, "thirty"},
                              {40, "fourty"},   {50, "fifty"},      {60, "sixty"}};

string NumToStr(int toConvert);

int main(){
    int hours, mins, realHours;
    cout << "Input hours and minutes, separated by a space: ";
    cin >> hours; cin >> mins;
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

string NumToStr(int toConvert){
    string returnStr;
    if(toConvert >= 20){
        int switchInt = floor(toConvert / 10.0) * 10;
        switch(switchInt){
            case 20: returnStr += "twenty"; break;
            case 30: returnStr += "thirty"; break;
            case 40: returnStr += "fourty"; break;
            case 50: returnStr += "fifty"; break;
        }
        returnStr.push_back('-');
    }

    if(toConvert >= 10 && toConvert <= 19){
        switch(toConvert){
            case 10: returnStr += "ten";        break;
            case 11: returnStr += "eleven";     break;
            case 12: returnStr += "twelve";     break;
            case 13: returnStr += "thirteen";   break;
            case 14: returnStr += "fourteen";   break;
            case 15: returnStr += "fifteen";    break;
            case 16: returnStr += "sixteen";    break;
            case 17: returnStr += "seventeen";  break;
            case 18: returnStr += "eighteen";   break;
            case 19: returnStr += "nineteen";   break;
        }
    }
    else{
        switch(toConvert % 10){
            case 1: returnStr += "one";         break;
            case 2: returnStr += "two";         break;
            case 3: returnStr += "three";       break;
            case 4: returnStr += "four";        break;
            case 5: returnStr += "five";        break;
            case 6: returnStr += "six";         break;
            case 7: returnStr += "seven";       break;
            case 8: returnStr += "eight";       break;
            case 9: returnStr += "nine";        break;
        }
    }
    
    return returnStr;
}