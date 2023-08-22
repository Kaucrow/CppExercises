#include <iostream>
#include "class_spec.h"
using std::cout;

int main(){
    Roulette coolRoulette;
    coolRoulette.Reset();
    coolRoulette.PrintStats();
    coolRoulette.Bet(1, 36, COLUMN);
    coolRoulette.Bet(1, 43, ROW);
    coolRoulette.Spin();
    coolRoulette.SetWinOrLose(1);
    coolRoulette.HandleBet(1);
    coolRoulette.PrintStats();
}