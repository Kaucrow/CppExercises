#include <iostream>
#include "class_spec.h"
using std::cout;

int main(){
    Roulette coolRoulette;
    coolRoulette.Reset();
    coolRoulette.Bet(1, 36, ROW);
    coolRoulette.Spin();
    coolRoulette.HandleBet(1);
}