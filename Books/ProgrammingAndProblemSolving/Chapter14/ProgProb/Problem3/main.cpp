#include <iostream>
#include "class_spec.h"
using std::cout;

void ActionChoose(CPU& someObj);

int main(){
    Status playerStatus;
    CPU someCpu;
    Player somePlayer;
    someCpu.ChooseAction(); somePlayer.ChooseAction();
    somePlayer.CompareAction(someCpu);
}