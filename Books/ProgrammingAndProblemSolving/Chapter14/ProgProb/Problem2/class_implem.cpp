#include <iostream>
#include "class_spec.h"
#include "..\..\..\..\..\Tools\RandomGenerator\random_gen.h"
#define PLAYER players[player - 1]
using std::cout, std::cin;

Roulette::Roulette(){}

void Roulette::Reset(){
    // RESET THE PLAYERS
    for(int i = 0; i < PLAYER_AMOUNT; i++){
        players[i].hasBet = 0;
        players[i].hasWon = 0;
        for(int j = 0; j < 37; j++){
            players[i].betList[j] = 0;
        }
    }
}

void Roulette::Bet(int player, int amount, BetType type){
    if(PLAYER.hasBet){
        cout << "ERROR: The player " << player << " has already bet.\n"; return;
    }
    if(amount > PLAYER.moneyAmount){
        cout << "ERROR: The player " << player << " doesn't have that much money.\n"; return;
    }

    int markingNumber, tempValue;
    PLAYER.betType = type;
    PLAYER.betAmount = amount;

    switch(type){
        case ROW:{
            cout << "Input the row number (1 - 12): ";
            tempValue = GetBet(1, 12);
            // MARK THE ROW'S BET NUMBERS
            for(int i = 1; i <= 3; i++){
                markingNumber = 3 * (tempValue - 1) + i;
                PLAYER.betList[markingNumber] = 1;
            }
            break;
        } 
        case COLUMN:{
            cout << "Input the column number (1, 2, 3): ";
            tempValue = GetBet(1, 3);
            // MARK THE COLUMN'S BET NUMBERS
            for(int i = 0; i <= 11; i++){
                markingNumber = 3 * i + tempValue;
                PLAYER.betList[markingNumber] = 1;
            }
            break;
        }
        case NUMBER:{
            cout << "Input the number (0 - 36): ";
            tempValue = GetBet(0, 36);
            // MARK A BET NUMBER
            PLAYER.betList[tempValue] = 1;
            break;
        }
    }
    PLAYER.hasBet = 1;
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
    currNum = Random(0, 36);
    cout << "The number is... " << currNum << "!\n";
}

void Roulette::SetWinOrLose(int player){
    int addMoney = 0;
    switch(PLAYER.betType){
        case RED:
        case EVEN: if(currNum % 2 == 0) PLAYER.hasWon = 1; break;

        case BLACK:
        case ODD: if(currNum % 2 == 1) PLAYER.hasWon = 1; break;

        case ONE18: if(currNum <= 18) PLAYER.hasWon = 1; break;
        
        case NINETEEN36: if(currNum >= 19) PLAYER.hasWon = 1; break;

        case ROW:
        case COLUMN:
        case NUMBER: if(PLAYER.betList[currNum]) PLAYER.hasWon = 1; break;
    }
    if(PLAYER.hasWon) cout << "The player " << player << " won! :)\n";
    else cout << "The player " << player << " lost! :(\n";
}

void Roulette::HandleBet(int player){
    int addMoney;
    if(PLAYER.hasWon){
        switch(PLAYER.betType){
            case RED: case BLACK:
            case EVEN: case ODD:
            case ONE18: case NINETEEN36: addMoney = PLAYER.betAmount * 2; break;

            case ROW: addMoney = PLAYER.betAmount * 12; break;

            case COLUMN: addMoney = PLAYER.betAmount * 3; break;

            case NUMBER: addMoney = PLAYER.betAmount * 36; break;
        }
    }
    else addMoney = -1 * PLAYER.betAmount;

    if(addMoney > 0) cout << addMoney << "$ have been added to the player " << player << " account.\n";
    else cout << -1 * addMoney << "$ have been taken from the player " << player << " account.\n";
    PLAYER.moneyAmount += addMoney;
}

void Roulette::PrintStats(){
    cout << '\n';
    for(int i = 0; i < PLAYER_AMOUNT; i++){
        cout << "PLAYER " << i + 1 << '\n';
        cout << "Money: " << players[i].moneyAmount << "$\n\n";
    }
}