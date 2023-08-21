#include <iostream>
#include <iomanip>
#include "class_spec.h"
using std::cout, std::setw, std::setfill;

int main(){
    Time myTime;
    myTime.Add(1, 100);
    cout << myTime.GetTotalSeconds() << '\n';
    cout << myTime.GetMinutes() << '\n';
    myTime.Subtract(1, 50);
    cout << myTime.GetTotalSeconds() << '\n';
    myTime.Subtract(100, 100);
    cout << setfill('0') << setw(2) << myTime.GetMinutes() << ':' << setw(2) << myTime.GetSeconds() << '\n';
}