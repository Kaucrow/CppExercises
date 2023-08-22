#include <iostream>
#include "class_spec.h"
using std::cout;

int main(){
    Roulette coolRoulette;
    coolRoulette.Reset();
    coolRoulette.Bet(1, 36, ROW);
    coolRoulette.Bet(1, 43, COLUMN);
    coolRoulette.Spin();
    coolRoulette.HandleBet(1);
}