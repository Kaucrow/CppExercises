#include "class_spec.h"

int main(){
    bool exitFlag = 0;
    CPU someCpu;
    Player somePlayer;
    while(true){
        someCpu.GetAction(); somePlayer.GetAction();

        exitFlag = somePlayer.CheckQuit();
        if(exitFlag) return 0;

        somePlayer.CompareAction(someCpu);
    }
}