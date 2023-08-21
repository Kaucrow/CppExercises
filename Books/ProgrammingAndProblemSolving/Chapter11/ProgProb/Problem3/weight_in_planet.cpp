#include <iostream>
#include "class_spec.h"
using std::cout, std::cin;

int main(){
    string tempName;
    double tempWeight;
    Planets planetName;
    
    cout << "Please input the planet name: "; cin >> tempName;
    planetName = StrToPlanets(tempName);
    while(planetName == ERROR){
        cout << "Please input a valid planet name: ";
        cin >> tempName;
        planetName = StrToPlanets(tempName);
    }
    Weight myWeight(planetName);

    cout << "Please input the object weight: "; cin >> tempWeight;
    myWeight.Set(tempWeight);

    cout << "The object weighs " << myWeight.Get() << "kg in " << tempName << ".\n";
}