#pragma once
#include <string>
using std::string;

enum BetType    {RED, BLACK, EVEN, ODD, ONE18,
                 NINETEEN36, ROW, COLUMN, NUMBER};

const int PLAYER_AMOUNT = 4;

struct PlayerBet{
    BetType type;
    int betAmount, number, row, column;
};

class Ball{
    public:
        Ball();
        void Reset();
    private:
        int number;
        int row;
        int column;
        string oddEven; 
};

class Roulette{
    public:
        Roulette();
        void Reset();
        void Bet(int player, int amount, BetType type);
        void Spin();
        void HandleBet(int player);
    private:
        PlayerBet players[PLAYER_AMOUNT];
        Ball ball;
};