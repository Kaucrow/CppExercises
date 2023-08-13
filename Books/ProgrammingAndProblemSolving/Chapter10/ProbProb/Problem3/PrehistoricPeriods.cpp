#include <iostream>

using   std::cout, std::cin, std::string,
        std::swap;

enum Periodos  {CUATERNARIO, TERCIARIO, CRETACEO,
                JURASICO, TRIASICO, PERMICO,
                CARBONIFERO, DEVONICO, SILURICO,
                ORDOVICICO, CAMBRICO, PRECAMBRICO};

Periodos InicioFin(float fecha);
string ImprimirPeriodo(Periodos periodo);

int main(){
    // Cuaternario  2.5
    // Terciario    65
    // Cretaceo     136
    // Jurasico     192
    // Triasico     225
    // Permico      280
    // Carbonifero  345
    // Devonico     395
    // Silurico     435
    // Ordovicico   500
    // Cambrico     570
    // Precambrico  4500 o antes
    float fechaInicio, fechaFin;
    Periodos periodoInicio, periodoFin;
    while(true){
        cout << "Introduzca una fecha (mill. de anos): "; cin >> fechaInicio;
        cout << "Introduzca otra fecha (mill. de anos): "; cin >> fechaFin;
        if(fechaFin > fechaInicio) swap(fechaInicio, fechaFin);
        periodoInicio = InicioFin(fechaInicio);
        periodoFin = InicioFin(fechaFin);
        cout << "Inicio: " << fechaInicio << '\n'; cout << "Fin: " << fechaFin << '\n';
        for(periodoInicio; periodoInicio >= periodoFin; periodoInicio = Periodos(periodoInicio - 1)){
            cout << ImprimirPeriodo(periodoInicio) << '\n';
        }
    }
}

Periodos InicioFin(float fecha){
    if(fecha <= 2.5)            return CUATERNARIO;
    else if(fecha <= 65 )       return TERCIARIO;
    else if(fecha <= 136 )      return CRETACEO;
    else if(fecha <= 192 )      return JURASICO;
    else if(fecha <= 225 )      return TRIASICO;
    else if(fecha <= 280 )      return PERMICO;
    else if(fecha <= 345 )      return CARBONIFERO;
    else if(fecha <= 395 )      return DEVONICO;
    else if(fecha <= 435 )      return SILURICO;
    else if(fecha <= 500 )      return ORDOVICICO;
    else if(fecha <= 570 )      return CAMBRICO;
    else                        return PRECAMBRICO; 
} 

string ImprimirPeriodo(Periodos periodo){
    switch(periodo){
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
    }
}