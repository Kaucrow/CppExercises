#include <iostream>
#include "..\..\..\..\..\Tools\RandomGenerator\random_gen.h"
#include "class_spec.h"
using std::cout, std::cin;

CPU::CPU(){}

void CPU::ChooseAction(){ action = Action(Random(1,3) - 1); }

string CPU::ActionStr(Action toConvert) const{
    switch(toConvert){
        case ROCK:      return "rock";
        case PAPER:     return "paper";
        case SCISSORS:  return "scissors";
    }
}

// ================================================================

Player::Player(){}

void Player::ChooseAction(){
    string tempStr;
    cout << "Player\n";
    cout << "Choose an action (Rock, Paper, Scissors): ";
    cin >> tempStr;
    CheckString(tempStr);
    while(tempStr != "rock" && tempStr != "paper" && tempStr != "scissors"){
        cout << "Please choose a valid action: ";
        cin >> tempStr;
        CheckString(tempStr);
    }
    action = StrToAction(tempStr);
}

void Player::CompareAction(CPU& toCompare){
    if(action == toCompare.action) status = TIE;
    else if(toCompare.action == ROCK){
        if(action == PAPER) status = WON;
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
    if(status == WON){ cout << "The player won! :)\n"; wins++; }
    else if(status == LOST){ cout << "The player lost... :(\n"; toCompare.wins++; }
    else cout << "It's a tie :/\n";
}
// =========================
//  *** PRIVATE METHODS ***
// =========================
void Player::CheckString(string& toCheck) const{
    for(int i = 0; i < toCheck.length(); i++){
        toCheck[i] = tolower(toCheck[i]);
    }
}

Action Player::StrToAction(string& toConvert) const{
    if(toConvert == "rock")     return ROCK;
    if(toConvert == "paper")    return PAPER;
    if(toConvert == "scissors") return SCISSORS;
}