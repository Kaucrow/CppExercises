#include <iostream>
#include <ctime>
#include <random>
#include <cassert>
#include <climits>

using   std::cout, std::cin, std::string;

enum Periods   {CUATERNARIO, TERCIARIO, CRETACEO,
                JURASICO, TRIASICO, PERMICO,
                CARBONIFERO, DEVONICO, SILURICO,
                ORDOVICICO, CAMBRICO, PRECAMBRICO,
                INVALIDO};

static string defStr = "none";
Periods GetPeriod(float date, string& periodGuess = defStr);
float Random(float min, float max, bool floatNum = 0);

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
    auto RndTwoDec = [](float num){ return (round(num * 100) / 100); };

    char flagExit;
    float date;
    string periodGuessStr;
    Periods periodReal, periodGuessPrd;

    do{
        if(Random(0.0, 1.0, 1) < 0.2){ date = Random(0.0, 2.5, 1); }
        else date = Random(2.5, 600.0, 1);
        date = RndTwoDec(date);
        periodReal = GetPeriod(date);
    
        while(true){
            cout << "Periodo hace " << date << " millon"; if(date != 1) cout << "es"; cout << " de anos?: "; cin >> periodGuessStr;
            for(int i = 0; i < periodGuessStr.length(); i++){ periodGuessStr[i] = tolower(periodGuessStr[i]); }
            periodGuessPrd = GetPeriod(-1, periodGuessStr);
            if(periodGuessPrd == periodReal){ cout << "Correcto!\n"; break;}
            else if(periodGuessPrd == INVALIDO) cout << "Ese no es un periodo valido.\n";
            else cout << "No es correcto...\n";
        }

        cin.ignore(1);
        do{
            cout << "Desea seguir jugando? (y/n): "; 
            flagExit = getchar();
        }while(flagExit != 'y' && flagExit != 'n');
    }while(flagExit == 'y');
}

Periods GetPeriod(float date, string& periodGuess){ 
    if((date <= 2.5 && date >= 0) || periodGuess == "cuaternario")         return CUATERNARIO;
    else if((date <=  65 && date >= 0) || periodGuess == "terciario")      return TERCIARIO;
    else if((date <= 136 && date >= 0) || periodGuess == "cretaceo")       return CRETACEO;
    else if((date <= 192 && date >= 0) || periodGuess == "jurasico")       return JURASICO;
    else if((date <= 225 && date >= 0) || periodGuess == "triasico")       return TRIASICO;
    else if((date <= 280 && date >= 0) || periodGuess == "permico")        return PERMICO;
    else if((date <= 345 && date >= 0) || periodGuess == "carbonifero")    return CARBONIFERO;
    else if((date <= 395 && date >= 0) || periodGuess == "devonico")       return DEVONICO;
    else if((date <= 435 && date >= 0) || periodGuess == "silurico")       return SILURICO;
    else if((date <= 500 && date >= 0) || periodGuess == "ordovicico")     return ORDOVICICO;
    else if((date <= 570 && date >= 0) || periodGuess == "cambrico")       return CAMBRICO;
    else if((date  > 570 && date >= 0) || periodGuess == "precambrico")    return PRECAMBRICO; 
    else return INVALIDO;
} 

float Random(float min, float max, bool floatNum){
    static std::mt19937 Eng(time(NULL));
    static std::uniform_real_distribution<double> DistF;
    static std::uniform_int_distribution<int> DistI;
    
    assert(min < max);
    if(floatNum){ DistF.param(std::uniform_real_distribution<double>::param_type(min, max)); return (DistF(Eng)); }
    else{ DistI.param(std::uniform_int_distribution<int>::param_type(min, max)); return (DistI(Eng)); }
}