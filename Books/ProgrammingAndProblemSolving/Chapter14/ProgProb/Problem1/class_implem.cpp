#include <iostream>
#include "class_spec.h"
#include "random_gen.h"
using std::cout, std::cin;

Ball::Ball(){}

void Ball::Reset(){
    number = 99; row = 99; column = 99; oddEven = "RESET";
}

// ===========================================================

Roulette::Roulette(){
    for(int i = 0; i < PLAYER_AMOUNT; i++){
        players[i].betAmount = 0;
    }
}

void Roulette::Reset(){
    ball.Reset();
}

void Roulette::Bet(int player, int amount, BetType type){
    players[player].type = type;
    players[player].betAmount += amount;
    switch(type){
        case ROW:{
            cout << "Input the row number (1 - 12): ";
            cin >> players[player].row;
            break;
        } 
        case COLUMN:{
            cout << "Input the column number (1, 2, 3): ";
            cin >> players[player].column;
            break;
        }
        case NUMBER:{
            cout << "Input the number (1 - 36): ";
            cin >> players[player].number;
        }
    }
}

void Roulette::Spin(){
    cout << Random(1, 36);
}