#include <string>
using std::string;

enum Action {ROCK, PAPER, SCISSORS, QUIT, ERROR};
enum Status {WON, LOST, TIE};

class Player;

class CPU{
    public:
        CPU();
        void GetAction();
        string ActionStr(Action toConvert) const;
        int GetWins();
        friend class Player;
    private:
        Action action;
        int wins = 0;
};

class Player : public CPU{
    public:
        Player();
        void GetAction();
        void CompareAction(CPU& toCompare);
        bool CheckQuit();
    private:
        Status status;
        Action StrToAction(string& toConvert) const;
};