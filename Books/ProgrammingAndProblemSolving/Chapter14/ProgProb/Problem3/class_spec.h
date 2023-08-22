#include <string>
using std::string;

enum Action {ROCK, PAPER, SCISSORS};
enum Status {WON, LOST, TIE};

class Player;

class CPU{
    public:
        CPU();
        void ChooseAction();
        string ActionStr(Action toConvert) const;
        friend class Player;
    private:
        Action action;
        int wins = 0;
};

class Player : public CPU{
    public:
        Player();
        void ChooseAction();
        void CompareAction(CPU& toCompare);
    private:
        Status status;
        void CheckString(string& toCheck) const;
        Action StrToAction(string& toConvert) const;
};