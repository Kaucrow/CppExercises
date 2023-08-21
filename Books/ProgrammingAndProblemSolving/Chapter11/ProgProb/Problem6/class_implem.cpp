#include <iostream>
#include <string>
#include "class_spec.h"
using std::cerr;

Phone::Phone(){
    type = HOME; number = "+0 (000) 000-0000"; countryCode = 0; areaCode = 0;
}

Phone::Phone(string setNumber){
    int setCountryCode, setAreaCode;
    type = HOME;
    number = setNumber;

    setCountryCode = stoi(setNumber);
    SetCountryCode(setCountryCode);
    setNumber = setNumber.substr(setNumber.find('(') + 1);

    setAreaCode = stoi(setNumber);
    SetAreaCode(setAreaCode);
}

Phone::Phone(Type setType, string setNumber, int setCountryCode, int setAreaCode){
    type = setType; number = setNumber; countryCode = setCountryCode; areaCode = setAreaCode;
}

void Phone::SetType(Type setType){
    type = setType;
}

void Phone::SetNumber(string setNumber){
    number = setNumber;
}

void Phone::SetCountryCode(int setCountryCode){
    if((setCountryCode / 100) >= 10){ cerr << "INVALID COUNTRY CODE" << '\n'; return; }
    countryCode = setCountryCode;
}

void Phone::SetAreaCode(int setAreaCode){
    if((setAreaCode / 100) >= 10){ cerr << "INVALID AREA CODE" << '\n'; return; }
    areaCode = setAreaCode;
}

string Phone::GetType() const{
    switch(type){
        case HOME:      return "Home";
        case OFFICE:    return "Office";
        case FAX:       return "Fax";
        case CELL:      return "Cell";
        case PAGER:     return "Pager";
        default:        return "ERROR";
    }
}

string Phone::GetNumber() const{ return number; }

int Phone::GetCountryCode() const{ return countryCode; }

int Phone::GetAreaCode() const{ return areaCode; }

bool Phone::IsEqual(Phone comparePhone) const{
    return
        (number != comparePhone.number)             ? 0 :
        (countryCode != comparePhone.countryCode)   ? 0 :
        (areaCode != comparePhone.areaCode)         ? 0 : 1;
}