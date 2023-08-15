#include <iostream>
#include "ClassSpec.h"
using std::cout, std::string;

Period::Period(){
    currName = PRECAMBRICO;
}

Period::Period(Periods newName){
    currName = newName;
}

Periods Period::Name(){ return currName; }

string Period::PeriodString(Periods name){
    switch(name){
        case CUATERNARIO:   return "Cuaternario";
        case TERCIARIO:     return "Terciario";
        case CRETACEO:      return "Cretaceo";
        case JURASICO:      return "Jurasico";
        case TRIASICO:      return "Triasico";
        case PERMICO:       return "Permico";
        case CARBONIFERO:   return "Carbonifero";
        case DEVONICO:      return "Devonico";
        case SILURICO:      return "Silurico";
        case ORDOVICICO:    return "Ordovicico";
        case CAMBRICO:      return "Cambrico";
        case PRECAMBRICO:   return "Precambrico";
        default:            return "Invalido";
    }
}

int Period::PeriodInt(Periods name){
    return name;
}

string Period::PeriodStart(Periods name){
    switch(name){
        case CUATERNARIO:   return "2.5";
        case TERCIARIO:     return "65";
        case CRETACEO:      return "136";
        case JURASICO:      return "192";
        case TRIASICO:      return "225";
        case PERMICO:       return "280";
        case CARBONIFERO:   return "345";
        case DEVONICO:      return "395";
        case SILURICO:      return "435";
        case ORDOVICICO:    return "500";
        case CAMBRICO:      return "570";
        case PRECAMBRICO:   return "4500";
        default:            return "[Invalido]";
    }
}

void Period::PeriodIncrease(){
    if(currName == CUATERNARIO) return;
    else{
        currName = Periods(currName - 1);
    }
}
