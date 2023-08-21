#include <iostream>
#include "class_spec.h"

using std::cout;

int main(){
    Money myMoney(34, 1040);
    myMoney.PrintDollars();
    cout << '\n';
    myMoney.PrintCents();
    cout << '\n';
    myMoney.Add(1, 101);
    cout << myMoney.Total();
}