#include "random_gen.h"
#include <random>
#include <ctime>
#include <cassert>

float Random(float min, float max, bool floatNum){
    static std::mt19937 Eng(time(NULL));
    static std::uniform_real_distribution<double> DistF;
    static std::uniform_int_distribution<int> DistI;
    
    assert(min < max);
    if(floatNum){ DistF.param(std::uniform_real_distribution<double>::param_type(min, max)); return (DistF(Eng)); }
    else{ DistI.param(std::uniform_int_distribution<int>::param_type(min, max)); return (DistI(Eng)); }
}