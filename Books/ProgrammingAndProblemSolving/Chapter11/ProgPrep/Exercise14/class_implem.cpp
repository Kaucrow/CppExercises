#include <iostream>
#include "class_spec.h"

using std::cout;

Money::Money(){
    dollars = 0; cents = 0;
}

Money::Money(int addDollars, int addCents){
    dollars = 0; cents = 0;
    Add(addDollars, addCents);
}

void Money::Add(int addDollars, int addCents){
    while(addCents >= 100){
        addDollars++;
        addCents -= 100;
    }
    dollars += addDollars; cents += addCents;
}

void Money::Subtract(int subtractDollars, int subtractCents){
    while(subtractCents >= 100){
        subtractDollars++;
        subtractCents -= 100;
    }
    dollars -= subtractDollars; cents -= subtractCents;
}

void Money::PrintDollars(){ cout << dollars; }

void Money::PrintCents(){ cout << cents; }

float Money::Total(){
    return (dollars + (cents / 100.0));
}