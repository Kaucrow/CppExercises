#pragma once
#include <string>
using std::string;

class SimpleDate{
    public:
        SimpleDate(int newDay, int newMonth, int newYear);
        string GetDate() const;
    private:
        int day, month, year;
};

class Computer{
    public:
        Computer(string newName, string newBrand,
                 string newModel, int newSpeed,
                 string newSerial, int newNumber);
        string GetName() const;
        string GetBrand() const;
        string GetModel() const;
        int GetSpeed() const;
        string GetSerial() const;
        int GetNumber() const;
        virtual void Write() const;
    private:
        string name;
        string brand;
        string model;
        int speed;
        string serialNumber;
        int inventoryNumber;
};

class InstallRecord : public Computer{
    public:
        InstallRecord(string newName, string newBrand,
                 string newModel, int newSpeed,
                 string newSerial, int newNumber,
                 string newLocation, int newDay,
                 int newMonth, int newYear);
        void Write() const;
    private:
        string location;
        SimpleDate date;
};