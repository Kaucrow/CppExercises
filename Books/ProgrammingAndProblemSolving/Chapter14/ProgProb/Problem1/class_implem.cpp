#include <iostream>
#include "class_spec.h"
#include "random_gen.h"
using std::cout, std::cin;

Roulette::Roulette(){}

void Roulette::Reset(){
    // RESET THE PLAYERS
    for(int i = 0; i < PLAYER_AMOUNT; i++){
        players[i].betAmount = 0;
        players[i].hasBetted = 0;
        for(int j = 0; j < 37; j++){
            players[i].betList[j] = 0;
        }
    }
}

void Roulette::Bet(int player, int amount, BetType type){
    if(players[player - 1].hasBetted){
        cout << "ERROR: The player " << player << " has already betted.\n"; return;
    }
    
    int markingNumber, tempValue;
    players[player - 1].betType = type;
    players[player - 1].betAmount += amount;

    switch(type){
        case ROW:{
            cout << "Input the row number (1 - 12): ";
            tempValue = GetBet(1, 12);
            // MARK THE ROW'S BET NUMBERS
            for(int i = 1; i <= 3; i++){
                markingNumber = 3 * (tempValue - 1) + i;
                players[player - 1].betList[markingNumber] = 1;
            }
            break;
        } 
        case COLUMN:{
            cout << "Input the column number (1, 2, 3): ";
            tempValue = GetBet(1, 3);
            // MARK THE COLUMN'S BET NUMBERS
            for(int i = 0; i <= 11; i++){
                markingNumber = 3 * i + tempValue;
                players[player - 1].betList[markingNumber] = 1;
            }
            break;
        }
        case NUMBER:{
            cout << "Input the number (0 - 36): ";
            tempValue = GetBet(0, 36);
            // MARK A BET NUMBER
            players[player - 1].betList[tempValue] = 1;
            break;
        }
    }
    players[player - 1].hasBetted = 1;
}

// private method
int Roulette::GetBet(int min, int max) const{
    int bet;
    cin >> bet;
    while(bet < min || bet > max){
        cout << "Please enter a valid number: ";
        cin >> bet;
    }
    return bet;
}

void Roulette::Spin(){
    currNum = Random(0, 1);
    cout << "The number is... " << currNum << "!\n";
}

void Roulette::HandleBet(int player){
    bool wonFlag = 0;
    switch(players[player - 1].betType){
        case RED:
        case EVEN:{
            if(currNum % 2 == 0) wonFlag = 1;
            break; 
        }
        case BLACK:
        case ODD:{
            if(currNum % 2 == 1) wonFlag = 1;
            break;
        }
        case ONE18:{
            if(currNum <= 18) wonFlag = 1;
            break;
        }
        case NINETEEN36:{
            if(currNum >= 19) wonFlag = 1;
            break;
        }
        case ROW:
        case COLUMN:
        case NUMBER:{
            if(players[player - 1].betList[currNum]) wonFlag = 1;
            break;
        }
    }
    if(wonFlag) cout << "The player " << player << " won! :)\n";
    else cout << "The player " << player << " lost! :(\n";
}