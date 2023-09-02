#include "date_class.h"
#include "exceptions.h"

Date::Date(){}

Date::Date(int setDay, int setMonth, int setYear) : day(setDay), month(setMonth), year(setYear){
    if(setDay < 1 || setDay > 31) 
        throw InvalidDay("ERR: THE DAY CANNOT BE LESS THAN 1 OR EXCEED 31\n");
    else if(setDay > 28){
        if(setMonth == 2){
            // if the year is not a leap year, throw excep
            if(setYear % 4 != 0 || (setYear % 100 == 0 && setYear % 400 != 0))
                throw InvalidDay("ERR: FEBRUARY CAN'T HAVE MORE THAN 28 DAYS ON NON-LEAP YEAR\n");
            // if the year is a leap year but the day is higher than 29, throw excep
            else if(setDay > 29)
                throw InvalidDay("ERR: FEBRUARY CAN'T HAVE MORE THAN 29 DAYS\n");
        }
        else if(setDay == 31){
            // if the day is 31 on a month that can't have more than 30 days, throw excep
            if(setMonth == 4 || setMonth == 6 || setMonth == 9 || setMonth == 11)
                throw InvalidDay("ERR: THE ENTERED MONTH CAN'T HAVE MORE THAN 30 DAYS\n");
        }
    }
    else if(setMonth < 0 || setMonth > 12)
        throw InvalidMonth("ERR: THE MONTH CANNOT BE LESS THAN 1 OR EXCEED 12\n");
    else if(setYear < 0)
        throw InvalidYear("ERR: THE YEAR CANNOT BE NEGATIVE\n");
}

void Date::PrintDate(){
    cout << day << " / " << month << " / " << year << '\n';
}

bool Date::Equal(Date& toCompare){
    return(
        (day != toCompare.day)      ? 0 :
        (month != toCompare.month)  ? 0 :
        (year != toCompare.year)    ? 0 : 1
    );
}