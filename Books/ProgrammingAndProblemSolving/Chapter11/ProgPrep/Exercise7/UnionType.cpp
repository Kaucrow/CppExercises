#include <iostream>
using std::cout, std::string;

struct Time{
    int mins, secs;
};
union Temporal{
    // MUST DEFINE CONSTRUCTOR AND
    // DESTRUCTOR EXPLICITLY TO USE STRING TYPE
    // IN UNION TYPE
    Temporal(){};
    string str;
    char timeStr[5];
    int timeInt;
    Time timeStruct;
    ~Temporal(){};
};

int main(){
    Time someTime;
    someTime.mins = 6; someTime.secs = 54;

    Temporal shift;
    shift.str = "9:33";

    cout << shift.str;
}