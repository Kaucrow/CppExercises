#include <iostream>
#include "..\..\..\..\..\Tools\RandomGenerator\random_gen.h"
#include "class_spec.h"
using std::cout, std::cin;

CPU::CPU(){}

void CPU::GetAction(){ action = Action(Random(1,3) - 1); }

int CPU::GetWins(){ return wins; }

string CPU::ActionStr(Action toConvert) const{
    switch(toConvert){
        case ROCK:      return "rock";
        case PAPER:     return "paper";
        case SCISSORS:  return "scissors";
    }
}

// ================================================================

Player::Player(){}

void Player::GetAction(){
    string tempStr;
    bool repeatFlag = 0;
    do{
        if(repeatFlag) cout << "Please enter a valid action: ";
        else cout << "Choose an action (R/P/S/QUIT): ";
        cin >> tempStr;
        for(int i = 0; i < tempStr.length(); i++){
            tempStr[i] = tolower(tempStr[i]);
        }
        action = StrToAction(tempStr);
        repeatFlag = 1;
    }while(action == ERROR);
}

void Player::CompareAction(CPU& toCompare){
    if(action == toCompare.action) status = TIE;
    else if(toCompare.action == ROCK){
        if(action == PAPER) status = WON;
        else status = LOST;
    }
    else if(toCompare.action == PAPER){
        if(action == SCISSORS) status = WON;
        else status = LOST;
    }
    else{
        if(action == ROCK) status = WON;
        else status = LOST;
    }

    cout << "CPU Action: " << ActionStr(toCompare.action) << '\n';
    if(status == WON){ cout << "The player won! :)\n\n"; wins++; }
    else if(status == LOST){ cout << "The player lost... :(\n\n"; toCompare.wins++; }
    else cout << "It's a tie :/\n\n";
}

bool Player::CheckQuit(){
    if(action == QUIT) return 1;
    else return 0;
}

// =========================
//  *** PRIVATE METHODS ***
// =========================
Action Player::StrToAction(string& toConvert) const{
    if      (toConvert == "rock"      || toConvert == "r") return ROCK;
    else if (toConvert == "paper"     || toConvert == "p") return PAPER;
    else if (toConvert == "scissors"  || toConvert == "s") return SCISSORS;
    else if (toConvert == "quit"      || toConvert == "q") return QUIT;
    else return ERROR;
}