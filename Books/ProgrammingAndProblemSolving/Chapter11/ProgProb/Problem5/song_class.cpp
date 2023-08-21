#include <iostream>
#include "class_spec.h"
using std::cout;

int main(){
    Song mySong("none", "none", 3, 67, COUNTRY);
    cout << mySong.GetData() << '\n';
    mySong.SetArtist("Me");
    mySong.SetGenre(METAL);
    mySong.SetTitle("Epic Song");
    cout << mySong.GetData() << '\n';
}