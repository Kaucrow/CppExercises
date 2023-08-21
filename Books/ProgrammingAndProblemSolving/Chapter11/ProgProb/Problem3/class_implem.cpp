#include <iostream>
#include "class_spec.h"
using std::cout;
typedef string str;

Weight::Weight(){ planet = EARTH; Set(0); }

Weight::Weight(Planets planetName){ planet = planetName; Set(0); }

void Weight::Set(double setWeight){ weight = setWeight; }

double Weight::Get(){ 
    if      (planet == MERCURY)     return (weight * 0.4155);
    else if (planet == VENUS)       return (weight * 0.8975);
    else if (planet == EARTH)       return (weight * 1.0);
    else if (planet == MOON)        return (weight * 0.166);
    else if (planet == MARS)        return (weight * 0.3507);
    else if (planet == JUPITER)     return (weight * 2.5374);
    else if (planet == SATURN)      return (weight * 1.0677);
    else if (planet == URANUS)      return (weight * 0.8947);
    else if (planet == NEPTUNE)     return (weight * 1.1794);
    else if (planet == PLUTO)       return (weight * 0.0899);
}

Planets StrToPlanets(string planetName){
    for(int i = 0; i < planetName.length(); i++){
        planetName[i] = toupper(planetName[i]);
    }
    if      (planetName == "MERCURY")   return MERCURY;
    else if (planetName == "VENUS")     return VENUS;
    else if (planetName == "EARTH")     return EARTH;
    else if (planetName == "MOON")      return MOON;
    else if (planetName == "MARS")      return MARS;
    else if (planetName == "JUPITER")   return JUPITER;
    else if (planetName == "SATURN")    return SATURN;
    else if (planetName == "URANUS")    return URANUS;
    else if (planetName == "NEPTUNE")   return NEPTUNE;
    else if (planetName == "PLUTO")     return PLUTO;
    else return ERROR;
}