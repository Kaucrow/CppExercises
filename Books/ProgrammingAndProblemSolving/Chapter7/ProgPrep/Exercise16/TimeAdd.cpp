#include <iostream>
#include <cassert>

using std::cout;

void TimeAdd(   int& currDays,  int& currHours, int& currMinutes,   int& currSeconds,
                int addDays,    int addHours,   int addMinutes,     int addSeconds);
int main(){
    int currDays = 0, currHours = 0, currMinutes = 0, currSeconds = 0;
    
    TimeAdd(currDays, currHours, currMinutes, currSeconds, 1, 1, 1, 1);
    cout    << "Days: "     << currDays << '\n'
            << "Hours: "    << currHours << '\n'
            << "Minutes: "  << currMinutes << '\n'
            << "Seconds: "  << currSeconds << '\n';

    TimeAdd(currDays, currHours, currMinutes, currSeconds, 34, 238, 62, 143);
    cout    << "Days: "     << currDays << '\n'
            << "Hours: "    << currHours << '\n'
            << "Minutes: "  << currMinutes << '\n'
            << "Seconds: "  << currSeconds << '\n';
}

void TimeAdd(   int& currDays,  int& currHours, int& currMinutes,   int& currSeconds,
                int addDays,    int addHours,   int addMinutes,     int addSeconds){
    
    // ensure that every addition value is positive
    assert(addDays >= 0); assert(addHours >= 0); assert(addMinutes >= 0); assert(addSeconds >= 0);

    while(addSeconds + currSeconds >= 60){
        addSeconds -= 60;
        addMinutes++;
    }
    while(addMinutes + currMinutes >= 60){
        addMinutes -= 60;
        addHours++;
    }
    while(addHours + currHours >= 24){
        addHours -= 24;
        addDays++;
    }

    currSeconds += addSeconds; currMinutes += addMinutes; currHours += addHours; currDays += addDays;
}