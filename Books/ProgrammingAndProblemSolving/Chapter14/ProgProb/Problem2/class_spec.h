#pragma once
#include <string>
using std::string;

enum BetType    {RED, BLACK, EVEN, ODD, ONE18,
                 NINETEEN36, ROW, COLUMN, NUMBER};

const int PLAYER_AMOUNT = 4;

struct PlayerBet{
    bool hasBet, hasWon;
    BetType betType;
    bool betList[37] = {};
    int betAmount, moneyAmount = 100;
};
class Roulette{
    public:
        Roulette();
        void Reset();
        void Bet(int player, int amount, BetType type);
        void Spin();
        void SetWinOrLose(int player);
        void HandleBet(int player);
        void PrintStats();
    private:
        int GetBet(int min, int max) const;
        PlayerBet players[PLAYER_AMOUNT];
        int currNum = 0;
};