#include <iostream>
#include "exceptions.h"
using std::cout, std::cerr, std::cin, std::string;

enum Planets   {MERCURY, VENUS, EARTH, MOON, MARS,
                JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};

float GetWeight(float& weight, Planets planet);
Planets StrToPlanets(string toConvert);

int main(){
    float weight;
    string planet;
    cout << "Input your weight in earth (in kg): "; cin >> weight;
    cout << "Input a planet, or the moon: "; cin >> planet;
    try{ 
        cout    << "Your weight in " << planet << " is "
                << GetWeight(weight, StrToPlanets(planet)) << "kg.\n";
    }
    catch(InvalidPlanet err){
        cerr << err.what(); return 1;
    }
}

float GetWeight(float& weight, Planets planet){
    // Mercury      0.4155
    // Venus        0.8975
    // Earth        1.0
    // Moon         0.166
    // Mars         0.3507
    // Jupiter      2.5374
    // Uranus       0.8947
    // Neptune      1.1794
    // Pluto        0.0899
    switch(planet){
        case MERCURY:   return weight * 0.4155;
        case VENUS:     return weight * 0.8975;
        case EARTH:     return weight * 1.0;
        case MOON:      return weight * 0.166;
        case MARS:      return weight * 0.3507;
        case JUPITER:   return weight * 2.5374;
        case SATURN:    return weight * 1.0677;
        case URANUS:    return weight * 0.8947;
        case NEPTUNE:   return weight * 1.1794;
        case PLUTO:     return weight * 0.0899;
    }
}

Planets StrToPlanets(string toConvert){
    for(auto& i : toConvert) i = toupper(i); 
    if      (toConvert == "MERCURY")    return MERCURY;
    else if (toConvert == "VENUS")      return VENUS;
    else if (toConvert == "EARTH")      return EARTH;
    else if (toConvert == "MOON")       return MOON;
    else if (toConvert == "MARS")       return MARS;
    else if (toConvert == "JUPITER")    return JUPITER;
    else if (toConvert == "SATURN")     return SATURN;
    else if (toConvert == "URANUS")     return URANUS;
    else if (toConvert == "NEPTUNE")    return NEPTUNE;
    else if (toConvert == "PLUTO")      return PLUTO;
    else{
        cerr << toConvert;
        throw InvalidPlanet(" IS NOT A VALID PLANET NAME\n");
    }
}