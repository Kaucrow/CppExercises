#include <iostream>
#include <sstream>
#include "class_spec.h"
using std::cout;

Computer::Computer (string newName, string newBrand,
                    string newModel, int newSpeed,
                    string newSerial, int newNumber)
{
    name = newName; brand = newBrand;
    model = newModel; speed = newSpeed;
    serialNumber = newSerial; inventoryNumber = newNumber;
}

string Computer::GetName() const{ return name; }

string Computer::GetBrand() const{ return brand; }

string Computer::GetModel() const{ return model; }

int Computer::GetSpeed() const{ return speed; }

string Computer::GetSerial() const{ return serialNumber; }

int Computer::GetNumber() const{ return inventoryNumber; }

void Computer::Write() const{
    cout    << "Name: " << name << '\n'
            << "Brand: " << brand << '\n'
            << "Model: " << model << '\n'
            << "Speed: " << speed << '\n'
            << "Serial Number: " << serialNumber << '\n'
            << "Inventory Number: " << inventoryNumber << "\n";
}

// ================================================================

InstallRecord::InstallRecord   (string newName, string newBrand,
                                string newModel, int newSpeed,
                                string newSerial, int newNumber,
                                string newLocation, int newDay,
                                int newMonth, int newYear)
    :Computer  (newName, newBrand, newModel, 
                newSpeed, newSerial, newNumber),
     date(newDay, newMonth, newYear)
{
    location = newLocation;
}

void InstallRecord::Write() const{
    Computer::Write();
    cout << "Location: " << location << '\n';
    cout << "Install date: " << date.GetDate() << '\n';
}

// ================================================================

SimpleDate::SimpleDate(int newDay, int newMonth, int newYear)
{
    day = newDay; month = newMonth; year = newYear;
}

string SimpleDate::GetDate() const{
    std::ostringstream outString;
    outString << day << '/' << month << '/' << year;
    return outString.str();
}