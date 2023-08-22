#include <iostream>
#include "class_spec.h"
using std::cout;

int main(){
    Status playerStatus;
    CPU someCpu;
    Player somePlayer;
    someCpu.ChooseAction(); somePlayer.GetAction();
    somePlayer.CompareAction(someCpu);
}