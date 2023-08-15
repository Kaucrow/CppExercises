#include <iostream>
#include "ClassSpec.h"

using std::cout;

int main(){
    Period dinoPeriod(TRIASICO);
    cout << dinoPeriod.PeriodString(dinoPeriod.Name()) << '\n';
    cout << dinoPeriod.PeriodInt(dinoPeriod.Name()) << '\n';
    cout << dinoPeriod.PeriodStart(dinoPeriod.Name()) << '\n';
    dinoPeriod.PeriodIncrease();
    cout << dinoPeriod.PeriodString(dinoPeriod.Name()) << '\n';
}