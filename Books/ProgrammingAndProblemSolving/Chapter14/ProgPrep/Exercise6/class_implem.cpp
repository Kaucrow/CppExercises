#include <iostream>
#include "class_spec.h"
using std::cout;

Phone::Phone(int newAreaCode, int newNumber, PhoneType newType){
    areaCode = newAreaCode; number = newNumber, type = newType;
}

void Phone::Write() const{
    cout    << "Area code: " << areaCode << '\n'
            << "Number: " << number << '\n'
            << "Type: " << TypeToStr(type) << '\n';
}

string Phone::TypeToStr(PhoneType toConvert) const{
    switch(toConvert){
        case HOME:      return "Home";
        case OFFICE:    return "Office";
        case CELL:      return "Cell";
        case FAX:       return "Fax";
        case PAGE:      return "Page";
        default:        return "ERROR";
    }
}

InternPhone::InternPhone(int newCountryCode, int newAreaCode,
                         int newNumber, PhoneType newType)
    :Phone(newAreaCode, newNumber, newType){
    countryCode = newCountryCode;
}

void InternPhone::Write() const{
    cout << "Country code: " << countryCode << '\n';
    Phone::Write();
}