#include "class_spec.h"

Time::Time(){
    minutes = 0; seconds = 0;
}

Time::Time(int addMinutes, int addSeconds){
    Add(addMinutes, addSeconds);
}

void Time::Add(int addMinutes, int addSeconds){
    while(addSeconds >= 60){
        addMinutes++;
        addSeconds -= 60;
    }
    minutes += addMinutes; seconds += addSeconds;
}

void Time::Subtract(int subtractMinutes, int subtractSeconds){
    while(subtractSeconds >= 60){
        subtractMinutes++;
        subtractSeconds -= 60;
    }
    if(subtractMinutes > minutes){ minutes = 0; seconds = 0; }
    else{ minutes -= subtractMinutes; seconds -= subtractSeconds; }
}

int Time::GetMinutes(){ return minutes; }

int Time::GetSeconds(){ return seconds; }

int Time::GetTotalSeconds(){ return (seconds + (minutes * 60)); }