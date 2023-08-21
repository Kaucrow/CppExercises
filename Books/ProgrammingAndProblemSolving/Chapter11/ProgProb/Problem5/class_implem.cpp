#include <string>
#include <iomanip>
#include <sstream>
#include "class_spec.h"
using std::setw, std::setfill;

string CategoryToStr(Category toConvert);

Song::Song(){
    title = "NONE"; 
    artist = "NONE";
    Time.minutes = 0;
    Time.seconds = 0;
    genre = ROCK;
}

Song::Song (string setTitle, string setArtist,
            int setMinutes, int setSeconds,
            Category setGenre)
{
    SetTitle(setTitle);
    SetArtist(setArtist);
    SetMinutes(setMinutes);
    SetSeconds(setSeconds);
    SetGenre(setGenre);
}

void Song::SetTitle(string setTitle){
    title = setTitle;
}

void Song::SetArtist(string setArtist){
    artist = setArtist;
}

void Song::SetMinutes(int setMinutes){
    Time.minutes = setMinutes;
}

void Song::SetSeconds(int setSeconds){
    int secondsRemainder = 0;
    while(setSeconds >= 60){
        secondsRemainder++;
        setSeconds -= 60;
    }
    Time.seconds = setSeconds;
    Time.minutes += secondsRemainder;
}

void Song::SetGenre(Category setGenre){
    genre = setGenre;
}

string Song::GetData() const{
    std::stringstream ss;
    ss  << title << ", " << artist 
        << " | Genre: " << CategoryToStr(genre) 
        << " | Duration: " << setfill('0') << setw(2) 
        << Time.minutes << ':' << setw(2) << Time.seconds;
    return ss.str();
}

bool Song::Equal(Song compareSong) const{
    return
        (title != compareSong.title)                ? 0 :
        (artist != compareSong.artist)              ? 0 :
        (Time.minutes != compareSong.Time.minutes)  ? 0 :
        (Time.seconds != compareSong.Time.seconds)  ? 0 :
        (genre != compareSong.genre)                ? 0 : 1;
}

string CategoryToStr(Category toConvert){
    switch(toConvert){
        case ROCK:      return "Rock";
        case POP:       return "Pop";
        case METAL:     return "Metal";
        case JAZZ:      return "Jazz";
        case COUNTRY:   return "Country";
        case BLUES:     return "Blues";
        default:        return "ERROR";
    }
}