#include <iostream>

using std::cout, std::string;

enum Category  {ROCK, POP, METAL, COUNTRY,
                JAZZ, BLUES};

struct Time{
    int mins, secs;
};

struct Song{
    string title, artist;
    Time duration;
    Category genre;
};

int main(){
    Time someTime;
    someTime.mins = 6; someTime.secs = 54;

    Song mySong;
    mySong.title = "I Met a Girl Once";
    mySong.artist = "Me";
    mySong.duration = someTime;
    mySong.genre = ROCK;

    cout << mySong.duration.mins << ':' << mySong.duration.secs << '\n'; 
}